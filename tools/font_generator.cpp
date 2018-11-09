/// Tool used to generate font header file which can be used by the display_1306 code in thekbd.
/// This is based on the tool in the Adafruit GFX library.
/// It uses FreeType2 library.
/// It has been tested only on Linux!

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include <stdio.h>
#include <string>
#include <memory>

#include "display_font.h"

struct FTAutoLibraryDone
{
    explicit FTAutoLibraryDone(FT_Library library) : library(library)
    {
    }
    ~FTAutoLibraryDone()
    {
        FT_Done_FreeType(library);
    }
private:
    FT_Library library;
};
struct FTAutoFaceDone
{
    explicit FTAutoFaceDone(FT_Face face) : face(face)
    {
    }
    ~FTAutoFaceDone()
    {
        FT_Done_Face(face);
    }
private:
    FT_Face face;
};
struct FTAutoGlyphDone
{
    explicit FTAutoGlyphDone(FT_Glyph glyph) : glyph(glyph)
    {
    }
    ~FTAutoGlyphDone()
    {
        FT_Done_Glyph(glyph);
    }
private:
    FT_Glyph glyph;
};

int main(int argc, char *argv[])
{
    fprintf(stderr, "Font Generator!!!\n");

    if (argc < 3 || argc > 5)
    {
        fprintf(stderr, "Usage: %s path-to-font-file size(px) [first char] [last char]\n", argv[0]);
        return 1;
    }

    const int fontSizePixels = atoi(argv[2]);
    const char *fontPath = argv[1];
    std::string resultFontName;

    int firstChar = ' ';
    int lastChar = '~';
    if (argc >= 4)
        firstChar = atoi(argv[3]);
    if (argc >= 5)
        lastChar = atoi(argv[4]);
    if (lastChar < firstChar)
    {
        fprintf(stderr, "error: Last char '%c' must be smaller than first char '%c'!\n", lastChar,
                firstChar);
        return 1;
    }
    const int numGlyphs = lastChar - firstChar + 1;

    fprintf(stderr, "Converting '%s' to '%s' size %d ('%c' '%c')\n", fontPath, resultFontName.c_str(),
           fontSizePixels, firstChar, lastChar);

    FT_Library ftLibrary;
	// Init FreeType lib, load font
	int error = FT_Init_FreeType(&ftLibrary);
	if (error)
    {
		fprintf(stderr, "error: FreeType init failed with %d", error);
		return error;
	}
	FTAutoLibraryDone ftLibraryAutoDone(ftLibrary);

	FT_Face ftFace;
	error = FT_New_Face(ftLibrary, fontPath, 0, &ftFace);
	if(error) {
		fprintf(stderr, "error: Font '%s' failed to load. Error %d", fontPath, error);
		return error;
	}
	FTAutoFaceDone ftFaceAutoDone(ftFace);

	error = FT_Set_Pixel_Sizes(ftFace, 0, fontSizePixels);
	if (error)
    {
		fprintf(stderr, "error: Set pixel size %dx%d failed with %d", 0, fontSizePixels, error);
		return error;
    }

    fprintf(stdout, "// Genrated font\n\n");
    fprintf(stdout, "#include \"display_font.h\"\n\n");
    fprintf(stdout, "const uint8_t testFontBitmaps2[] PROGMEM = {\n");

    std::unique_ptr<Glyph[]> glyphTable(new Glyph[numGlyphs]);
    int bitmapOffset = 0;

    for (int glyphIdx = 0; glyphIdx < numGlyphs; ++glyphIdx) //charCode = firstChar; charCode <= lastChar; ++charCode)
    {
        const int charCode = firstChar + glyphIdx;

        error = FT_Load_Char(ftFace, charCode, FT_LOAD_TARGET_MONO);
        if (error)
        {
            fprintf(stderr, "error: Loading char '%c' failed with %d\n", charCode, error);
            return 1;
        }

        FT_GlyphSlot slot = ftFace->glyph;

        error = FT_Render_Glyph(slot, FT_RENDER_MODE_MONO);
        if (error)
        {
            fprintf(stderr, "error: Rendering char '%c' failed with %d\n", charCode, error);
            return 1;
        }

        FT_Glyph ftGlyph;

        error = FT_Get_Glyph(slot, &ftGlyph);
        if (error)
        {
            fprintf(stderr, "error: Getting glyph for char '%c' failed with %d\n", charCode, error);
            return 1;
        }
        FTAutoGlyphDone ftGlyphAutoDone(ftGlyph);

        FT_Bitmap bitmap = slot->bitmap;
        const FT_BitmapGlyphRec *bitmapGlyph = reinterpret_cast<FT_BitmapGlyphRec*>(ftGlyph);

        Glyph &glyph = glyphTable[glyphIdx];
        glyph.bitmapOffset = bitmapOffset;
        glyph.width = bitmap.width;
        glyph.height = bitmap.rows;
        glyph.numRows = bitmap.rows/8 + (bitmap.rows % 8 > 0 ? 1 : 0);
        glyph.xAdvance = slot->advance.x >> 6;
        glyph.xOffset = bitmapGlyph->left;
        glyph.yOffset = 1-bitmapGlyph->top;

        fprintf(stderr, "Glyph info: '%c' (%3d) bmpOffs: %5d; w: %3d; h: %3d; r: %3d; a: %3d; xoffs: %3d; yoffs: %3d\n",
                charCode, charCode, glyph.bitmapOffset, glyph.width, glyph.height, glyph.numRows,
                glyph.xAdvance, glyph.xOffset, glyph.yOffset);

        for (int row = 0; row < bitmap.rows; ++row)
        {
            fprintf(stderr, "row[%2d]: ", row);

            for (int ii = 0; ii < bitmap.pitch; ++ii)
                fprintf(stderr, "%2x ", bitmap.buffer[row * bitmap.pitch + ii]);

            for (int col = 0; col < bitmap.width; ++col)
            {
                const uint8_t byte = bitmap.buffer[row * bitmap.pitch + col / 8];
                const unsigned bitMask = 0x80 >> (col & 7);

                fprintf(stderr, "%c", ((byte & bitMask) == bitMask) ? '*' : '.');
            }
            fprintf(stderr, "\n");
        }

        fprintf(stderr, "\n");

        fprintf(stdout, "    // Data for '%c'\n", charCode);
        for (int col = 0; col < bitmap.width; ++col)
        {
            uint8_t columnByte = 0;
            int addedColumns = 0;

            bool first = true;
            for (int row = 0; row < bitmap.rows; ++row)
            {
                const uint8_t byte = bitmap.buffer[row * bitmap.pitch + col / 8];
                const unsigned bitMask = 0x80 >> (col & 7);

                uint8_t bitValue = (((byte & bitMask) == bitMask) ? 1 : 0);

                columnByte |= bitValue << addedColumns;
                addedColumns++;

                if (addedColumns == 8)
                {
                    if (first)
                    {
                        first = false;
                        fprintf(stdout, "    ");
                    }
                    else
                        fprintf(stdout, ", ");
                    fprintf(stdout, "0x%02x", columnByte);
                    ++bitmapOffset;

                    addedColumns = 0;
                    columnByte = 0;
                }
            }

            if (addedColumns > 0)
            {
                if (first)
                    fprintf(stdout, "    ");
                else
                    fprintf(stdout, ", ");
                fprintf(stdout, "0x%02x", columnByte);
                ++bitmapOffset;
            }
            if (glyphIdx == numGlyphs - 1 && col == bitmap.width - 1)
                fprintf(stdout, "\n");
            else
                fprintf(stdout, ",\n");

        }
        if (glyphIdx != numGlyphs - 1)
            fprintf(stdout, "\n");
    }

    fprintf(stdout, "};\n\n");
    fprintf(stdout, "const Glyph testFontGlyphs[] PROGMEM = {\n");

    for (int glyphIdx = 0; glyphIdx < numGlyphs; ++glyphIdx)
    {
        const Glyph &glyph = glyphTable[glyphIdx];
        fprintf(stdout, "    { %5d, %2d, %2d, %2d, %2d, %2d, %2d }",
                glyph.bitmapOffset, glyph.width, glyph.height, glyph.numRows,
                glyph.xAdvance, glyph.xOffset, glyph.yOffset);

        if (glyphIdx == numGlyphs - 1)
            fprintf(stdout, "  // '%c'\n", firstChar + glyphIdx);
        else
            fprintf(stdout, ", // '%c'\n", firstChar + glyphIdx);
    }
    fprintf(stdout, "};\n\n");

    fprintf(stdout, "const Font testFont PROGMEM = {\n");
    fprintf(stdout, "    testFontBitmaps2,\n");
    fprintf(stdout, "    testFontGlyphs,\n");

    int height;
    if (ftFace->size->metrics.height == 0)
        height = glyphTable[0].height;
    else
        height = ftFace->size->metrics.height >> 6;

    fprintf(stdout, "    %d, %d, %d\n", firstChar, lastChar, height);
    fprintf(stdout, "};\n");


    return 0;
}
