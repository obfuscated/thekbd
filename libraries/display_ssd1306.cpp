#include "display_ssd1306.h"
#include <SPI.h>
#include "display_font.h"

#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF

#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA

#define SSD1306_SETVCOMDETECT 0xDB

#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9

#define SSD1306_SETMULTIPLEX 0xA8

#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10

#define SSD1306_SETSTARTLINE 0x40

#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22

#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8

#define SSD1306_SEGREMAP 0xA0

#define SSD1306_CHARGEPUMP 0x8D

#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

// Scrolling #defines
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A

template <typename T, int N>
constexpr int countof(T const (&)[N])
{
    return N;
}

static uint8_t buffer[SSD1306::height * (SSD1306::width / 8)] = {
    0
};

// constructor for hardware SPI - we indicate DataCommand, ChipSelect, Reset
SSD1306::SSD1306(int8_t DC, int8_t RST, int8_t CS) : font(nullptr)
{
    dc = DC;
    rst = RST;
    cs = CS;
}

void SSD1306::sendCommand(uint8_t c)
{
    *csport |= cspinmask; // cs -> HIGH
    *dcport &= ~dcpinmask; // dc -> LOW
    *csport &= ~cspinmask; // cs -> LOW

    SPI.transfer(c);

    *csport |= cspinmask; // cs -> HIGH
}

void SSD1306::begin(bool reset)
{
    // set pin directions
    pinMode(dc, OUTPUT);
    pinMode(cs, OUTPUT);
    csport = portOutputRegister(digitalPinToPort(cs));
    cspinmask = digitalPinToBitMask(cs);
    dcport = portOutputRegister(digitalPinToPort(dc));
    dcpinmask = digitalPinToBitMask(dc);
    pinMode(dc, OUTPUT);
    pinMode(cs, OUTPUT);
    csport = portOutputRegister(digitalPinToPort(cs));
    cspinmask = digitalPinToBitMask(cs);
    dcport = portOutputRegister(digitalPinToPort(dc));
    dcpinmask = digitalPinToBitMask(dc);
    SPI.begin();
#ifdef SPI_HAS_TRANSACTION
    SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));
#else
    SPI.setClockDivider (4);
#endif
    if ((reset) && (rst >= 0))
    {
        // Setup reset pin direction (used by both SPI and I2C)
        pinMode(rst, OUTPUT);
        digitalWrite(rst, HIGH);
        // VDD (3.3V) goes high at start, lets just chill for a ms
        delay(1);
        // bring reset low
        digitalWrite(rst, LOW);
        // wait 10ms
        delay(10);
        // bring out of reset
        digitalWrite(rst, HIGH);
        // turn on VCC (9V?)
    }

    // Init sequence
    sendCommand(SSD1306_DISPLAYOFF);                    // 0xAE
    sendCommand(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
    sendCommand(0x80);                                  // the suggested ratio 0x80

    sendCommand(SSD1306_SETMULTIPLEX);                  // 0xA8
    sendCommand(height - 1);

    sendCommand(SSD1306_SETDISPLAYOFFSET);              // 0xD3
    sendCommand(0x0);                                   // no offset
    sendCommand(SSD1306_SETSTARTLINE | 0x40);// | 0x0);            // line #0
    sendCommand(SSD1306_CHARGEPUMP);                    // 0x8D

    sendCommand(0x14);

    sendCommand(SSD1306_MEMORYMODE);                    // 0x20
    sendCommand(0x00);                                  // 0x0 act like ks0108
    sendCommand(SSD1306_SEGREMAP);// | 0x1);
    sendCommand(SSD1306_COMSCANDEC);

    sendCommand(SSD1306_SETCOMPINS);                    // 0xDA
    sendCommand(0x12);
    sendCommand(SSD1306_SETCONTRAST);                   // 0x81
    sendCommand(0xCF);

    sendCommand(SSD1306_SETPRECHARGE);                  // 0xd9
    sendCommand(0xF1);

    sendCommand(SSD1306_SETVCOMDETECT);                 // 0xDB
    sendCommand(0x40);
    sendCommand(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
    sendCommand(SSD1306_NORMALDISPLAY);                 // 0xA6

    sendCommand(SSD1306_DEACTIVATE_SCROLL);

    sendCommand(SSD1306_DISPLAYON);//--turn on oled panel
}

void SSD1306::display()
{
    sendCommand(SSD1306_COLUMNADDR);
    sendCommand(0);   // Column start address (0 = reset)
    sendCommand(width-1); // Column end address (127 = reset)

    sendCommand(SSD1306_PAGEADDR);
    sendCommand(0); // Page start address (0 = reset)
    sendCommand(7); // Page end address

    *csport |= cspinmask;
    *dcport |= dcpinmask;
    *csport &= ~cspinmask;

    static_assert(sizeof(buffer[0])*countof(buffer)==sizeof(buffer), "blabla");
    SPI.transfer(buffer, sizeof(buffer));
    *csport |= cspinmask;
}

void SSD1306::setContrast(uint8_t c)
{
    sendCommand(SSD1306_SETCONTRAST);
    sendCommand(c);
}

void SSD1306::setFont(const Font *font)
{
    this->font = font;
}

void SSD1306::fillScreen(uint16_t color)
{
    if (color == WHITE)
    {
        for (uint16_t i=0; i<countof(buffer); i++) {
            buffer[i] = 0xff;
        }
    }
    else if (color == BLACK)
    {
        for (uint16_t i=0; i<countof(buffer); i++) {
            buffer[i] = 0x00;
        }
    }
}

/// Fill a rectangle completely with one color. Update in subclasses if desired!
/// @param color 16-bit 5-6-5 Color to fill with
void SSD1306::fillRect(int8_t x, int8_t y, int8_t w, int8_t h, uint16_t color)
{
    for (int8_t i=x; i<x+w; i++)
    {
        drawFastVLineInternal(i, y, h, color);
    }
}

void SSD1306::drawFastHLineInternal(int16_t x, int16_t y, int16_t w, uint16_t color)
{
    // Do bounds/limit checks
    if (y < 0 || y >= height)
        return;
    // make sure we don't try to draw below 0
    if (x < 0)
    {
        w += x;
        x = 0;
    }

    // make sure we don't go off the edge of the display
    if ((x + w) > width)
        w = (width - x);

    // if our width is now negative, punt
    if (w <= 0)
        return;

    // set up the pointer for  movement through the buffer
    register uint8_t *pBuf = buffer;
    // adjust the buffer pointer for the current row
    pBuf += ((y/8) * width);
    // and offset x columns in
    pBuf += x;

    register uint8_t mask = 1 << (y&7);

    switch (color)
    {
        case WHITE:
            while(w--)
                *pBuf++ |= mask;
            break;
        case BLACK:
            mask = ~mask;
            while(w--)
                *pBuf++ &= mask;
            break;
        case INVERSE:
            while(w--)
                *pBuf++ ^= mask;
            break;
    }
}

void SSD1306::drawFastVLineInternal(int16_t x, int16_t __y, int16_t __h, uint16_t color)
{
    // do nothing if we're off the left or right side of the screen
    if (x < 0 || x >= width)
        return;

    // make sure we don't try to draw below 0
    if (__y < 0)
    {
        // __y is negative, this will subtract enough from __h to account for __y being 0
        __h += __y;
        __y = 0;
    }

    // make sure we don't go past the height of the display
    if ((__y + __h) > height)
        __h = (height - __y);

  // if our height is now negative, punt
    if (__h <= 0)
        return;

    // this display doesn't need ints for coordinates, use local byte registers for faster juggling
    register uint8_t y = __y;
    register uint8_t h = __h;

    // set up the pointer for fast movement through the buffer
    register uint8_t *pBuf = buffer;
    // adjust the buffer pointer for the current row
    pBuf += ((y/8) * width);
    // and offset x columns in
    pBuf += x;

    // do the first partial byte, if necessary - this requires some masking
    register uint8_t mod = (y&7);
    if (mod)
    {
        // mask off the high n bits we want to set
        mod = 8-mod;

        // note - lookup table results in a nearly 10% performance improvement in fill* functions
        // register uint8_t mask = ~(0xFF >> (mod));
        static uint8_t premask[8] = {0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE };
        register uint8_t mask = premask[mod];

        // adjust the mask if we're not going to reach the end of this byte
        if (h < mod)
            mask &= (0XFF >> (mod-h));

        switch (color)
        {
            case WHITE:   *pBuf |=  mask;  break;
            case BLACK:   *pBuf &= ~mask;  break;
            case INVERSE: *pBuf ^=  mask;  break;
        }

        // fast exit if we're done here!
        if (h<mod)
            return;

        h -= mod;

        pBuf += width;
    }

    // write solid bytes while we can - effectively doing 8 rows at a time
    if (h >= 8)
    {
        if (color == INVERSE)
        {
            // separate copy of the code so we don't impact performance of the black/white write version with an extra comparison per loop
            do
            {
                *pBuf=~(*pBuf);

                // adjust the buffer forward 8 rows worth of data
                pBuf += width;

                // adjust h & y (there's got to be a faster way for me to do this, but this should still help a fair bit for now)
                h -= 8;
            } while(h >= 8);
        }
        else
        {
            // store a local value to work with
            register uint8_t val = (color == WHITE) ? 255 : 0;

            do  {
                // write our value in
                *pBuf = val;

                // adjust the buffer forward 8 rows worth of data
                pBuf += width;

                // adjust h & y (there's got to be a faster way for me to do this, but this should still help a fair bit for now)
                h -= 8;
            } while(h >= 8);
        }
    }

    // now do the final partial byte, if necessary
    if (h)
    {
        mod = h & 7;
        // this time we want to mask the low bits of the byte, vs the high bits we did above
        // register uint8_t mask = (1 << mod) - 1;
        // note - lookup table results in a nearly 10% performance improvement in fill* functions
        static uint8_t postmask[8] = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F };
        register uint8_t mask = postmask[mod];
        switch (color)
        {
            case WHITE:   *pBuf |=  mask;  break;
            case BLACK:   *pBuf &= ~mask;  break;
            case INVERSE: *pBuf ^=  mask;  break;
        }
    }
}

int8_t SSD1306::print(int8_t x, int8_t y, uint16_t color, const char *text)
{
    if (font == nullptr)
        return 0;

    const uint8_t firstChar = pgm_read_byte(&font->first);
    const uint8_t lastChar = pgm_read_byte(&font->last);

    int8_t offset = 0;

    for (const char *currCh = text; *currCh != '\0'; ++currCh)
    {

        if (*currCh < firstChar || *currCh > lastChar)
            continue;

        int8_t charWidth = drawChar(x + offset, y, *currCh - firstChar, color);
        offset += charWidth;
    }
    return offset;
}

int8_t SSD1306::printNumber(int8_t x, int8_t y, uint16_t color, unsigned long n, uint8_t base)
{
  char buf[8 * sizeof(long) + 1]; // Assumes 8-bit chars plus zero byte.
  char *str = &buf[sizeof(buf) - 1];

  *str = '\0';

  // prevent crash if called with base == 1
  if (base < 2) base = 10;

  do {
    char c = n % base;
    n /= base;

    *--str = c < 10 ? c + '0' : c + 'A' - 10;
  } while(n);

  return print(x, y, color, str);
}

//#define PRINT_DEBUG

int8_t SSD1306::drawChar(int8_t x, int8_t y, uint8_t glyphIdx, uint16_t color) {
#ifdef PRINT_DEBUG
    Serial.println();
    Serial.print("drawChar(");
    Serial.print(glyphIdx);
    Serial.print(") x:");
    Serial.print(x);
    Serial.print(") y:");
    Serial.println(y);
#endif // PRINT_DEBUG

    const Glyph *fontGlyphs = reinterpret_cast<const Glyph*>(pgm_read_ptr(&font->glyph));

    const int8_t charOffset = pgm_read_byte(&fontGlyphs[glyphIdx].xAdvance);
    if (x >= width)
        return charOffset;

    const uint8_t fullCharWidth = pgm_read_byte(&fontGlyphs[glyphIdx].width);
    if (x + fullCharWidth < 0)
        return charOffset;

    int8_t startCol = 0;
    if (x < 0)
    {
        startCol = -x;
        x = 0;
    }

    const int8_t charYOffset = pgm_read_byte(&fontGlyphs[glyphIdx].yOffset);
    const int8_t numRows = pgm_read_byte(&fontGlyphs[glyphIdx].numRows);

    y += charYOffset;
    int8_t yInBytes = y / 8;
    int8_t yOffset = y % 8;
    int8_t startRow = abs(yInBytes);
    if (y < 0)
    {
        yInBytes = 0;
        yOffset = 8 + yOffset;
        if (startRow >= numRows)
            return charOffset;
    }
    else
        startRow = 0;

    uint8_t charWidth = width - uint8_t(x);
    if (charWidth > fullCharWidth)
        charWidth = fullCharWidth;

#ifdef PRINT_DEBUG
    Serial.print("cO:");
    Serial.println(charYOffset);
    Serial.print(" new y:");
    Serial.println(y);
    Serial.print(" sR:");
    Serial.print(startRow);
    Serial.print(" yInB:");
    Serial.print(yInBytes);
    Serial.print(" yOffs:");
    Serial.print(yOffset);
    Serial.print(" b:");
    Serial.println(uint16_t(buffer));
#endif // PRINT_DEBUG

    const uint8_t *charBitmapPtr = reinterpret_cast<const uint8_t*>(pgm_read_ptr(&font->bitmap));
    charBitmapPtr += pgm_read_word(&fontGlyphs[glyphIdx].bitmapOffset);

    if (yOffset == 0)
    {
        //uint8_t *bufferPtr = buffer + (width - x - 1);
        uint8_t *bufferPtr = buffer + (width - x - 1)  + uint16_t(yInBytes) * width;

#ifdef PRINT_DEBUG
        Serial.print(" bP:");
        Serial.println(uint16_t(bufferPtr));
#endif // PRINT_DEBUG

        if (bufferPtr >= buffer + sizeof(buffer))
            return charOffset;

#ifdef PRINT_DEBUG
        Serial.println("code1");
        Serial.print(" b:");
        Serial.println(uint16_t(bufferPtr));
#endif // PRINT_DEBUG

        for (int8_t row = startRow; row < numRows; ++row)
        {
            for (int8_t ii = startCol; ii < charWidth; ++ii)
            {
                const uint8_t charByte = pgm_read_byte(charBitmapPtr+ii*numRows+row);
                *bufferPtr |= charByte;

                bufferPtr--;
            }
            bufferPtr += width + charWidth;
            if (bufferPtr >= buffer + sizeof(buffer))
                return charOffset;
        }
    }
    else
    {
        uint8_t *bufferPtr = buffer + (width - x - 1)  + uint16_t(yInBytes) * width;

#ifdef PRINT_DEBUG
        Serial.print(" bP:");
        Serial.println(uint16_t(bufferPtr));
#endif // PRINT_DEBUG

        if (bufferPtr >= buffer + sizeof(buffer))
            return charOffset;

        if (y >= 0)
        {
#ifdef PRINT_DEBUG
            Serial.println("code2");
            Serial.print(" bP:");
            Serial.println(uint16_t(bufferPtr));
#endif // PRINT_DEBUG

            // Simpler computation for the first 8 rows of the character.
            for (int8_t ii = startCol; ii < charWidth; ++ii)
            {
                uint8_t charByte = pgm_read_byte(&charBitmapPtr[ii * numRows]);
                charByte = charByte << yOffset;
                *bufferPtr |= charByte;
                bufferPtr--;
            }
            bufferPtr += width + charWidth;
            if (bufferPtr >= buffer + sizeof(buffer))
                return charOffset;
        }

#ifdef PRINT_DEBUG
        Serial.println("code3");
        Serial.print(" bP:");
        Serial.println(uint16_t(bufferPtr));
#endif // PRINT_DEBUG

        // This loop blits the middle rows where we need to read two rows from the character and
        // merge them together.
        for (int8_t row = startRow + 1; row < numRows; ++row)
        {
            for (int8_t ii = startCol; ii < charWidth; ++ii)
            {
                const uint8_t charByte0 = pgm_read_byte(&charBitmapPtr[ii * numRows + row - 1]);
                const uint8_t charByte1 = pgm_read_byte(&charBitmapPtr[ii * numRows + row]);

                uint8_t charByte = (charByte1 << yOffset) + (charByte0 >> (8 - yOffset));

                *bufferPtr |= charByte;
                bufferPtr--;
            }

            bufferPtr += width + charWidth;
            if (bufferPtr >= buffer + sizeof(buffer))
                return charOffset;
        }

#ifdef PRINT_DEBUG
        Serial.println("code5");
        Serial.print(" bP:");
        Serial.println(uint16_t(bufferPtr));
#endif // PRINT_DEBUG

        // This loop blits the final row.
        for (int8_t ii = startCol; ii < charWidth; ++ii)
        {
            uint8_t charByte = pgm_read_byte(&charBitmapPtr[ii * numRows + numRows - 1]);
            charByte = charByte >> (8 - yOffset);
            *bufferPtr |= charByte;
            bufferPtr--;
        }
    }

    return charOffset;
}
