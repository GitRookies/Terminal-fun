#include <iostream>
#include <cstdlib>
#include "sprite.h"

static uint8_t my_bitmap[][3] = {
    {0xff, 0xef, 0xab},
    {0xff, 0xef, 0xab}
};

Sprite my_sprite((uint8_t*)my_bitmap, 2, 3);

int main(int argc, const char *argv[]) {

	std::cout << "Bitmap array:" << std::endl;
	
	my_sprite.printRaw();
	
    return 0;
}
