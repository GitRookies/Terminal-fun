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

    void initDisplay(int window_ht, int window_wd);
    void endDisplay(void);
    
    void drawSprite();

    
private:
    WINDOW *m_window;
    Sprite &m_sprite;
};

#endif