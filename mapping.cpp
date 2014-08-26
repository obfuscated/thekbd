#include "constants.h"
#include <stdint.h>
#include "Arduino.h"

extern const uint8_t layoutTable[keysTotalNumber]={
    0, 0, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, 0, 0, // row 0 right
    0, KEY_BACKSPACE, KEY_END, KEY_PAGE_DOWN, KEY_HOME, 0, 0,    // row 0 left

    KEY_RIGHT_ALT, 0,   0, KEY_UP_ARROW, 0, KEY_RETURN, KEY_DELETE, // row 1 right
    KEY_LEFT_GUI,  ' ', 0, KEY_PAGE_UP,  0, 0, KEY_LEFT_ALT,        // row 1 left

    KEY_RIGHT_CTRL, '/', '.', ',', 'm', 'n', 0, //  row 2 right
    0, 'b', 'v', 'c', 'x', 'z', KEY_LEFT_CTRL,  //  row 2 left

    KEY_RIGHT_SHIFT, ';', 'l', 'k', 'j', 'h', '\\',           // row 3 right
    '\'',            'g', 'f', 'd', 's', 'a', KEY_LEFT_SHIFT, // row 3 left

    0,   'p', 'o', 'i', 'u', 'y', ']',     // row 4 right
    '[', 't', 'r', 'e', 'w', 'q', KEY_TAB, // row 4 left

    0,   '=', '-', '0', '9', '8', '7', // row  5 right
    '6', '5', '4', '3', '2', '1', '`', // row 5  left

    KEY_INSERT, KEY_F12, KEY_F11, KEY_F10, KEY_F9, KEY_F8, KEY_F7,  // row 6 right
    KEY_F6,     KEY_F5,  KEY_F4,  KEY_F3,  KEY_F2, KEY_F1, KEY_ESC, // row 6 left
};
