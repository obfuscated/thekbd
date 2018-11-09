#pragma once

#include <stdint.h>

/// File defining structures for fonts.
/// Used by the firmware and the font generator tool.

struct Glyph
{
    uint16_t bitmapOffset;
    uint8_t width, height;
    uint8_t numRows;
    uint8_t xAdvance;
    int8_t xOffset, yOffset;
};

struct Font
{
    const uint8_t *bitmap;
    const Glyph *glyph;
    uint8_t first, last;
    uint8_t yAdvance;
};
