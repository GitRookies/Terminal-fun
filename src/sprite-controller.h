/*
 * sprite-controller.h
 * 
 * The class SpriteController here provides as a wrapper over the sprite
 * which controls how it will be displayed and where.
 */
#ifndef SPRITE_CONTROLLER_H
#define SPRITE_CONTROLLER_H

#include <iostream>
#include <cstdlib>
#include <exception>
#include <curses.h>
#include "sprite.h"

class SpriteController {
public:
    SpriteController(Sprite& sprite) : m_window(NULL), m_sprite(sprite) {}
    ~SpriteController() {
        if(m_window)
            delwin(m_window);
    }
    void initDisplay(int window_ht, int window_wd);
    void endDisplay(void);
    
    void drawSprite();

    typedef enum{LEFT, RIGHT, UP, DOWN} Direction;
    void scrollSprite(Direction direction);
    void simpleScroll(void);

    void moveSprite(int y_shifts, int x_shifts); // x = COL(H), y = ROW(V)
    
private:
    WINDOW *m_window;
    Sprite &m_sprite;
};

#endif