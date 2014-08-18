#include <Arduino.h>
#include <Wire.h>

const int countRows=7;
const int countColumns=7;

void print(bool released, int row, int column)
{
    Serial.print(released ? "released: " : "pressed: ");
    Serial.print(column);
    Serial.print(" ");
    Serial.println(row);
}

struct PressedState
{
    PressedState()
    {
        memset(state, 0, sizeof(int8_t)*countRows*2*countColumns);
    }
    int8_t get(int row, int column) const { return state[row*2*countColumns+column]; }
//    void set(int row, int column, int8_t newState) { state[row*2*countColumns+column]=newState; }

    void update(int row, int column, bool pressed)
    {
        int8_t &currState=state[row*2*countColumns+column];
        if (pressed)
        {
            currState++;
            if (currState==10)
            {
                currState=0;
                print(false, row, column);
            }
        }
        else if (currState>=10)
        {
            currState=0;
            print(true, row, column);
        }
    }
private:
    int8_t state[countRows*2*countColumns];
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
}

int iterations=0;

PressedState pressedState;

void loop()
{
    iterations++;
    if (iterations%200==0)
    {
        Serial.print("iterations: ");
        Serial.println(iterations);
    }
    Native::iterate(pressedState, 0);
    MCP23017::iterate(pressedState, 7);
}
