#include <Arduino.h>
#include <Wire.h>
#include <limits.h>

#include "constants.h"

void print(bool released, int row, int column)
{
    Serial.print(released ? "released: " : "pressed: ");
    Serial.print(column);
    Serial.print(" ");
    Serial.println(row);
}

unsigned long timeDifference(unsigned long a, unsigned long b)
{
    if (a>=b)
        return a-b;
    else
        return ULONG_MAX-a+b;
}

struct PressedState
{
    PressedState(const uint8_t *layoutTable) : currentTime(0), layoutTable(layoutTable)
    {
        memset(state, 0, sizeof(int8_t)*keysTotalNumber);
        memset(changeTime, 0, sizeof(unsigned long)*keysTotalNumber);
    }
    int8_t get(int row, int column) const { return state[row*2*countColumns+column]; }
//    void set(int row, int column, int8_t newState) { state[row*2*countColumns+column]=newState; }

    void setCurrentTime(unsigned long time) { currentTime=time; }

    void update(int row, int column, bool pressed)
    {
        const unsigned index=row*2*countColumns+column;
        int8_t &currState=state[index];
        bool oldPressed=((currState&1)!=0);

        if (oldPressed==pressed)
        {
            bool changing=((currState&2)!=0);
            if (changing && timeDifference(currentTime, changeTime[index])>5)
            {
                currState=(pressed ? 1 : 0);
                stateChange(pressed, row, column);
            }
        }
        else
        {
            currState=(pressed ? 1 : 0)+2;
            changeTime[index]=currentTime;
        }
    }

    void stateChange(bool pressed, int row, int column) const
    {
        uint8_t scanCode=layoutTable[row*2*countColumns+column];
        if (scanCode>0)
        {
            Serial.print(pressed ? "pressed key:" : "released key:");
            Serial.println(scanCode);
            if (pressed)
                Keyboard.press(scanCode);
            else
                Keyboard.release(scanCode);
        }
        else
            print(!pressed, row, column);
    }
private:
    int8_t state[keysTotalNumber];
    unsigned long changeTime[keysTotalNumber];
    unsigned long currentTime;
    const uint8_t * const layoutTable;
};

namespace Native
{
    const int outputPins[7]={A0, A1, A2, 5, A4, A5, A6};
    const int inputPins[7]={6, 7, 8, 9, 10, 11, 12};

    void setup()
    {
        for (int ii=0; ii<countRows; ++ii)
            pinMode(outputPins[ii], INPUT_PULLUP);
        for (int ii=0; ii<countColumns; ++ii)
            pinMode(inputPins[ii], INPUT_PULLUP);
    }

    void iterate(PressedState &pressedState, int offsetColumn)
    {
        for (int column=0; column<countColumns; ++column)
        {
            pinMode(outputPins[column], OUTPUT);

            digitalWrite(outputPins[column], LOW);
            for (int row=0; row<countRows; ++row)
            {
                int pressed=!digitalRead(inputPins[row]);
                pressedState.update(row, column+offsetColumn, pressed!=0);
            }

            digitalWrite(outputPins[column], HIGH);
            pinMode(outputPins[column], INPUT_PULLUP);
        }
    }
} // namespace Native


namespace MCP23017
{

    const int IODIRA=0x00;
    const int IODIRB=0x01;
    const int IPOLA=0x02;
    const int IPOLB=0x03;
    const int GPPUA=0x0C;
    const int GPPUB=0x0D;
    const int GPIOA=0x12;
    const int GPIOB=0x13;

    const int I2CPort=0x20;

    const int baseRow=0;
    const int baseColumn=1;

    void writeRegister(uint8_t reg, uint8_t value)
    {
        int bytes=0, status=0;
        Wire.beginTransmission(I2CPort);
        bytes+=Wire.write(reg);
        bytes+=Wire.write(value);
        status=Wire.endTransmission();
    //    if (status!=bytes)
    //        Serial.println("error:write reg");
    }

    void setRegisterForRead(uint8_t reg)
    {
        Wire.beginTransmission(I2CPort);
        Wire.write(reg);
        Wire.endTransmission();
    }

    uint8_t readRegister(uint8_t reg)
    {
        Wire.beginTransmission(I2CPort);
        Wire.write(reg);
        Wire.endTransmission();
        // request one byte of data from MCP20317
        Wire.requestFrom(I2CPort, 1);
        return Wire.read();
    }

    void enableColumn(uint8_t column)
    {
        uint8_t value=1<<column;
        value=0xFF&(~value);

        writeRegister(IODIRA, value);
        writeRegister(GPPUA, value);
        writeRegister(GPIOA, 0x00);
    }

    void setup()
    {
        Wire.begin(); // wake up I2C bus

        writeRegister(IODIRA, 0xFF&(~0x80));
        writeRegister(GPPUA, 0xFF&(~0x80));

        writeRegister(IODIRB, 0xFF);
        writeRegister(GPPUB, 0xFF);
        writeRegister(IPOLB, 0xFF);
    }

    void iterate(PressedState &pressedState, int offsetColumn)
    {
        for (int8_t column=0; column<countColumns; ++column)
        {
            enableColumn(column+baseColumn);
            uint8_t value=readRegister(GPIOB);
            for (uint8_t ii=0; ii<baseRow; ++ii)
                value>>=1;

            for (uint8_t row=0; row<countRows; ++row)
            {
                pressedState.update(row, column+offsetColumn, (value&1)==1);
                value>>=1;
            }
        }
    }

} // namespace MCP23017

void setup()
{
    Native::setup();
    MCP23017::setup();

    Keyboard.begin();
}

int iterations=0;
unsigned long iterationTimeMS=0;
extern const uint8_t layoutTable[];

PressedState pressedState(layoutTable);

void loop()
{
    unsigned long currentTime=millis();
    pressedState.setCurrentTime(currentTime);
    iterations++;
    if (iterations%200==0)
    {
        Serial.print("iterations: ");
        Serial.print(iterations);
        Serial.print(" time: ");
        Serial.println(timeDifference(currentTime, iterationTimeMS));
        iterationTimeMS=currentTime;
    }
    Native::iterate(pressedState, 0);
    MCP23017::iterate(pressedState, 7);
}
