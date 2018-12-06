/*
 * utils.h
 * 
 * Some utility routines.
 */

#include <cstdint>
static inline void delay(uint64_t count) {
    while(count--);
}