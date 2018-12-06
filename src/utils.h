/*
 * utils.h
 * 
 * Some utility routines.
 */

#include <cstdint>

/// XXX... Instead, use usleep(), nanosleep(), sleep(), etc.
#if 0
static inline void delay(uint64_t count) {
    while(count--);
}
#endif