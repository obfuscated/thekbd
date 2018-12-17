#ifndef _THEKBD_CONSTANT_H_
#define _THEKBD_CONSTANT_H_

#include <stdint.h>

#if THEKBD_RELEASE==1

const int8_t countRows=7;
const int8_t countColumns=7;

enum {
    keysTotalNumber=countRows*2*countColumns
};

#elif THEKBD_RELEASE==2

const int8_t countRows=6;
const int8_t countColumns=7;
const int8_t numLayers=2;

enum {
    keysTotalNumber=countRows*2*countColumns
};

#else
#   error "Unsupported release!"
#endif // THEKBD_RELEASE


// Constants for used in Mapping tables to mark the left/right layer select and switch keys.
// Use the reserved	range 0xA5-AF in the HID spec.
// Codes for switching the layer permanently.
const uint8_t KEY_LAYER_SWITCH_LEFT=0xA5;
const uint8_t KEY_LAYER_SWITCH_RIGHT=0xA6;
// Codes for switching the layer just while this particular key is pressed.
const uint8_t KEY_LAYER_SELECT_LEFT=0xA7;
const uint8_t KEY_LAYER_SELECT_RIGHT=0xA8;
// Constants to use in conditionals.
const uint8_t KEY_LAYER_MIN=KEY_LAYER_SWITCH_LEFT;
const uint8_t KEY_LAYER_MAX=KEY_LAYER_SELECT_RIGHT;

#endif // _THEKBD_CONSTANT_H_
