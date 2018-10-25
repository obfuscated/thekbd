#if THEKBD_RELEASE==2
#include <Arduino.h>
#include <Wire.h>
#include <limits.h>

#include "constants.h"

#include "KeyboardioHID.h"

template <typename T, int N>
constexpr int countof(T const (&)[N])
{
    return N;
}

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
    PressedState(const uint8_t *layoutTable) :
        currentTime(0),
        layoutTable(layoutTable),
        hasChanges(false)
    {
        memset(state, 0, sizeof(int8_t)*keysTotalNumber);
        memset(changeTime, 0, sizeof(unsigned long)*keysTotalNumber);
    }
    int8_t get(uint8_t row, uint8_t column) const { return state[row*2*countColumns+column]; }
//    void set(int row, int column, int8_t newState) { state[row*2*countColumns+column]=newState; }

    void setCurrentTime(unsigned long time) { currentTime=time; }

    void update(uint8_t row, uint8_t column, bool pressed)
    {
        const uint8_t index=row*2*countColumns+column;
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

    void stateChange(bool pressed, uint8_t row, uint8_t column)
    {
        uint8_t scanCode=layoutTable[row*2*countColumns+column];
        if (scanCode>0)
        {
            Serial.print(pressed ? "pressed key:" : "released key:");
            Serial.print(row);
            Serial.print(" ");
            Serial.print(column);
            Serial.print(" ");
            Serial.println(scanCode);
            if (pressed)
                Keyboard.press(scanCode);
            else
                Keyboard.release(scanCode);
            hasChanges=true;
        }
        else
            print(!pressed, row, column);
    }
    void sendReport()
    {
        if (hasChanges)
        {
            Keyboard.sendReport();
            hasChanges=false;
        }

    }
private:
    int8_t state[keysTotalNumber];
    unsigned long changeTime[keysTotalNumber];
    unsigned long currentTime;
    const uint8_t * const layoutTable;
    bool hasChanges;
};

namespace Native
{
    const uint8_t rowPins[countRows]={A0, A1, A2, A3, A4, A5};
    const uint8_t columnPins[countColumns]={6, 7, 8,  9, 10, 11, 12};

    void setup()
    {
        for (uint8_t ii=0; ii<countof(columnPins); ++ii)
            pinMode(columnPins[ii], INPUT_PULLUP);
        for (uint8_t ii=0; ii<countof(rowPins); ++ii)
            pinMode(rowPins[ii], INPUT_PULLUP);

        static_assert(countof(columnPins)==countColumns, "diff");
        static_assert(countof(rowPins)==countRows, "diff");
    }

    void iterate(PressedState &pressedState, uint8_t offsetColumn)
    {
        uint8_t row=countRows-1;
        do
        {
            pinMode(rowPins[row], OUTPUT);

            digitalWrite(rowPins[row], LOW);
            uint8_t column=countColumns-1;
            do
            {
                bool pressed=(digitalRead(columnPins[column])==0);
                pressedState.update(row, column+offsetColumn, pressed);
            }
            while (column--);

            digitalWrite(rowPins[row], HIGH);
            pinMode(rowPins[row], INPUT_PULLUP);
        }
        while (row--);
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

    uint32_t writeErrors=0;
    uint32_t readErrors=0;

    void writeRegister(uint8_t reg, uint8_t value)
    {
        uint8_t bytes=0, status=0;
        Wire.beginTransmission(I2CPort);
        bytes+=Wire.write(reg);
        bytes+=Wire.write(value);
        status=Wire.endTransmission();
        if (status!=0)
            writeErrors++;
    //    if (status!=bytes)
    //        Serial.println("error:write reg");
    }

    uint8_t readRegister(uint8_t reg)
    {
        Wire.beginTransmission(I2CPort);
        Wire.write(reg);
        uint8_t status=Wire.endTransmission();
        if (status!=0)
            writeErrors++;
        // request one byte of data from MCP20317
        uint8_t bytes=Wire.requestFrom(I2CPort, 1);
        if (bytes!=1)
            readErrors++;
        return Wire.read();
    }

    void enableRow(uint8_t row)
    {
        uint8_t value=1<<row;
        value=0xFF&(~value);

        writeRegister(GPIOB, value);
    }

    void setup()
    {
        Wire.begin(); // wake up I2C bus

        writeRegister(IODIRB, 0x00); // output B (Rows)

        writeRegister(IODIRA, 0xFF); // input A (Columns)
        // Enable pull up resistors (100k). This causes the circuits for open switches to register
        // as 1 before the reversal of polarity.
        writeRegister(GPPUA, 0xFF);
        writeRegister(IPOLA, 0xFF); // reverse the polarity of the input
    }

    void iterate(PressedState &pressedState, uint8_t offsetColumn)
    {
        uint8_t row=countRows-1;
        do
        {
            enableRow(row);
            uint8_t value=readRegister(GPIOA);

            uint8_t column=countColumns-1;
            do
            {
                pressedState.update(countRows-1-row, countColumns-1-column+offsetColumn, (value&1)==1);
                value>>=1;
            }
            while (column--);
        }
        while (row--);
    }

} // namespace MCP23017

void setup()
{
    Native::setup();
    MCP23017::setup();

    Keyboard.begin();
}

uint32_t iterations=0;
unsigned long iterationTimeMS=0;
extern const uint8_t layoutTable[];

PressedState pressedState(layoutTable);

void loop()
{
    unsigned long currentTime=millis();
    pressedState.setCurrentTime(currentTime);
    iterations++;
    if (iterations%1000==0)
    {
        Serial.print("iterations: ");
        Serial.print(iterations);
        Serial.print(" time: ");
        Serial.print(timeDifference(currentTime, iterationTimeMS));
        Serial.print(" (errors: ");
        Serial.print(MCP23017::writeErrors);
        Serial.print(", ");
        Serial.print(MCP23017::readErrors);
        Serial.println(")");

        iterationTimeMS=currentTime;
    }
    Native::iterate(pressedState, 0);
    //MCP23017::iterate(pressedState, 7);
    pressedState.sendReport();
}

#endif // THEKBD_RELEASE==2
