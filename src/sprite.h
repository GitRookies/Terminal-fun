/*
 * sprite.h
 *
 */
#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <cstdlib>

// Maximum resolution of a sprite bitmap.
#define SPRITE_MAX_WIDTH        1024
#define SPRITE_MAX_HEIGHT       640

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
    
private:
	uint8_t **m_bitmap;
	int m_width, m_height;
	bool m_bitmapAllocated;
};

#endif
