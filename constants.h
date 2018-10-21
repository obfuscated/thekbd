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

enum {
    keysTotalNumber=countRows*2*countColumns
};

#else
#   error "Unsupported release!"
#endif // THEKBD_RELEASE

#endif // _THEKBD_CONSTANT_H_

