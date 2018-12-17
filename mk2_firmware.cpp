#if THEKBD_RELEASE==2
#include <Arduino.h>
#include <Wire.h>
#include <limits.h>

#include "constants.h"

#include "fonts/comic_neue_regular_16px.h"
#include "libraries/display_ssd1306.h"

#include "KeyboardioHID.h"

#include "pressed_state.h"

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

namespace Display
{
    const uint8_t cs=4;
    const uint8_t dc=5;
    const uint8_t rst=13;

    SSD1306 display(dc, rst, cs);

    void setup(void)
    {
        display.begin();
        display.setFont(&testFont);
    }

    /// This is a slow function which does a full draw.
    void fullDraw(int8_t layerNo)
    {
        display.fillScreen(BLACK);

        if (layerNo != 0 && layerNo != 1)
        {
            const char *str = "Layer error!";
            display.print(2, 20, WHITE, str);
        }
        else
        {
            int8_t xOffset = 2;
            xOffset += display.print(xOffset, 20, WHITE, "Layer ");
            xOffset += display.printNumber(xOffset, 20, WHITE, layerNo + 1);
            /*xOffset +=*/ display.print(xOffset, 20, WHITE, " active!");
        }

        display.drawFastHLineInternal(0, 22, 127, WHITE);
        display.display();
    }

} // namespace Display

uint32_t iterations=0;
int8_t fullDraws = 0;
unsigned long iterationTimeMS=0;
unsigned long lastDrawTimeMS=0;
extern const uint8_t layoutTable[] PROGMEM;

PressedState pressedState;

void setup()
{
    pressedState.init(layoutTable);

    Serial.begin(9600);
    Native::setup();
    MCP23017::setup();
    Display::setup();

    Keyboard.begin();
}

void loop()
{
    unsigned long currentTime=millis();
    pressedState.setCurrentTime(currentTime);
    iterations++;
    if (iterations%1000==0)
    {
        Serial.print(F("iterations: "));
        Serial.print(iterations);
        Serial.print(F(" time: "));
        Serial.print(timeDifference(currentTime, iterationTimeMS));
        Serial.print(F(" (errors: "));
        Serial.print(MCP23017::writeErrors);
        Serial.print(F(", "));
        Serial.print(MCP23017::readErrors);
        Serial.print(F(") full draws: "));
        Serial.println(fullDraws);

        iterationTimeMS=currentTime;
        fullDraws = 0;
    }
    Native::iterate(pressedState, 0);
    MCP23017::iterate(pressedState, 7);
    pressedState.sendReport();

    // Draw on the display every 100ms
    if (timeDifference(currentTime, lastDrawTimeMS) > 100)
    {
        Display::fullDraw(0);
        fullDraws++;
        lastDrawTimeMS = currentTime;
    }
}

#endif // THEKBD_RELEASE==2
