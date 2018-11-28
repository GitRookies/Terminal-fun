#include <iostream>
#include <cstdlib>
#include "sprite.h"
#include "sprite-controller.h"

static uint8_t bmp_diamond[3][5] = {
    {0, 0, '*', 0, 0},
    {0, '*', 0, '*', 0},
    {0, 0, '*', 0, 0}
};

Sprite my_sprite((uint8_t*)bmp_diamond, 3, 5);
SpriteController controller(my_sprite);

int main(int argc, const char *argv[]) {
	
    controller.initDisplay(LINES, COLS);
    
    controller.drawSprite();
    
    controller.endDisplay();
    return 0;
}
