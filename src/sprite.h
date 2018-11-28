/*
 * sprite.h
 *
 */
#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <cstdlib>

// Maximum resolution of a sprite bitmap.
#define SPRITE_MAX_WIDTH        80
#define SPRITE_MAX_HEIGHT       24

class Sprite {
public:
	Sprite(uint8_t *bitmap, int h, int w);
    
    ~Sprite() {
        if(m_bitmapAllocated) {
            for(int i = 0; i < m_height; ++i)
                delete[] m_bitmap[i];
        }
    }
    
    void printRaw(void);
    
    inline int width(void) { return m_width; }
    inline int height(void) { return m_height; }
    inline uint8_t** bitmap(void) { return m_bitmap; }

    //void render(void);

private:
	uint8_t **m_bitmap; // XXX... More like a bytemap. :)
	int m_width, m_height;
	bool m_bitmapAllocated; // Indicates whether the bitmap is allocated or not.
                            // Prevents destructor from accidentally freeing memory
                            // if not allocated at all.
};

#endif
