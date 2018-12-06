/*
 * bitmap.h
 * 
 * Define the bitmap arrays in this file.
 */

static const uint8_t bmp_A[4][6] = {
    {0, 0, 0, '*', 0, 0},
    {0, 0, '*', 0, '*', 0},
    {0, '*', '*', '*', '*', 0},
    {'*',   0, 0, 0, 0, '*'}
};

static const uint8_t bmp_parallelLines[4][20] = {
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
};

static const uint8_t bmp_aeroplane[][20] = {
    {0, 0, 0, 0, 0, 0,    '*', '*', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0,    '*', 0, 0,'*', 0, 0, 0, 0, 0, 0, 0,   '*',   '*', 0, 0},
    {0, 0, 0, 0,     '*', 0, 0, 0, '*', 0, 0, 0, 0, 0,     '*', 0,  '*', 0, 0, 0},
    {0, '*', '*', '*', 0, 0, 0, 0,   '*', '*', '*', '*', '*', 0, 0, '*', 0, 0, 0, 0},
    {'*', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,                    '*', 0, 0, 0, 0, 0},
    {'*', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,                    '*', 0, 0, 0, 0, 0},
    {0, '*', '*', '*', 0, 0, 0, 0, '*', '*', '*', '*', '*', 0, 0,   '*', 0, 0, 0, 0},
    {0,   0, 0, 0,  '*', 0, 0, 0, '*', 0, 0, 0, 0, 0,    '*', 0,    '*', 0, 0, 0},
    {0,   0, 0, 0, 0, '*', 0, 0, '*', 0, 0, 0, 0, 0, 0, 0,   '*',   '*', 0, 0},
    {0, 0, 0, 0, 0, 0,  '*', '*', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};