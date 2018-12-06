#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "sprite.h"
#include "sprite-controller.h"
#include "utils.h"
#include "bitmap.h"

#define SPRITE_WIDTH        20
#define SPRITE_HEIGHT       10

Sprite my_sprite((uint8_t*)bmp_aeroplane, SPRITE_HEIGHT, SPRITE_WIDTH);
SpriteController controller(my_sprite);

int main(int argc, const char *argv[]) {
	
    controller.initDisplay(SPRITE_HEIGHT, SPRITE_WIDTH);
    
    controller.moveSprite(getmaxy(stdscr)/2, COLS - my_sprite.width());
    controller.drawSprite();

    for(int col = COLS - my_sprite.width() - 1; col >= 0; col--) {
        controller.moveSprite(0, -1); // Move by 1 position to the right.
        controller.drawSprite();
        usleep(20000);
    }

    controller.endDisplay();
    return 0;
}
