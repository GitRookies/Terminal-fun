/*
 * sprite.cpp
 */
#include "sprite.h"

#define MAKE_COPY_OF_BITMAP

// w -> width/Columns
// h -> height/Rows
Sprite :: Sprite(uint8_t *bitmap, int h, int w) {

#ifdef MAKE_COPY_OF_BITMAP

    m_bitmap = new uint8_t*[h];
    for(int i = 0; i < h; ++i)
        m_bitmap[i] = new uint8_t[w];
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            m_bitmap[i][j] = *((bitmap + i * w) + j);
        }
    }
#else

    m_bitmap = bitmap;

#endif

    m_width = w;
    m_height = h;

    m_bitmapAllocated = true;
}

void Sprite :: printRaw(void) {
    for(int i = 0; i < m_height; i++) {
        for(int j = 0; j < m_width; j++) {
            std::cout << "0x" << std::hex << (int)m_bitmap[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}
