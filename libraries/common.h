#ifndef THEKBD_LIBRARIES_COMMON_H__
#define THEKBD_LIBRARIES_COMMON_H__

#include <limits.h>

template <typename T, int N>
constexpr int countof(T const (&)[N])
{
    return N;
}

inline unsigned long timeDifference(unsigned long a, unsigned long b)
{
    if (a>=b)
        return a-b;
    else
        return ULONG_MAX-a+b;
}


#endif // THEKBD_LIBRARIES_COMMON_H__

