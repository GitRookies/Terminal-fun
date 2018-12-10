/*
 * utils.h
 * 
 * Some utility routines.
 */

#include <cstdint>

#ifndef UTILS_H_
#define UTILS_H_

/// XXX... Instead, use usleep(), nanosleep(), sleep(), etc.
#if 0
static inline void delay(uint64_t count) {
    while(count--);
}
#endif

#endif