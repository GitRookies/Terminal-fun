#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "sprite.h"
#include "sprite-controller.h"
#include "utils.h"

static uint8_t bmp_A[4][6] = {
    {0, 0, 0, '*', 0, 0},
    {0, 0, '*', 0, '*', 0},
    {0, '*', '*', '*', '*', 0},
    {'*',   0, 0, 0, 0, '*'}
};

Sprite my_sprite((uint8_t*)bmp_A, 4, 6);
SpriteController controller(my_sprite);

int main(int argc, const char *argv[]) {
	
    controller.initDisplay(4, 6);
    
    controller.moveSprite(getmaxy(stdscr)/2, 0);
    controller.drawSprite();

    for(int col = 0; col < 50; col++) {
        controller.moveSprite(0, col);
        controller.drawSprite();
        usleep(60000);
    }
    controller.endDisplay();
    return 0;
}
