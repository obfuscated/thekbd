#pragma once

#include <stdint.h>

typedef volatile uint8_t PortReg;
typedef uint8_t PortMask;

#define BLACK 0
#define WHITE 1
#define INVERSE 2

struct SSD1306
{
    static constexpr uint8_t width = 128;
    static constexpr uint8_t height = 64;

    SSD1306(int8_t DC, int8_t RST, int8_t CS);
    void begin(bool reset=true);
    void display();
    void setContrast(uint8_t c);
    void setFont(const struct Font *font);

    void fillScreen(uint16_t color);
    void fillRect(int8_t x, int8_t y, int8_t w, int8_t h,uint16_t color);

    int8_t print(int8_t x, int8_t y, uint16_t color, const char *text);
    int8_t printNumber(int8_t x, int8_t y, uint16_t color, unsigned long n, uint8_t base = 10);

    int8_t drawChar(int8_t x, int8_t y, uint8_t glyphIdx, uint16_t color);
//private:
    void sendCommand(uint8_t c);
    void drawFastHLineInternal(int16_t x, int16_t y, int16_t w, uint16_t color);
    void drawFastVLineInternal(int16_t x, int16_t __y, int16_t __h, uint16_t color);
private:
    int8_t sclk, dc, rst, cs;
    PortReg *csport, *dcport;
    PortMask cspinmask, dcpinmask;

    const Font *font;
};
