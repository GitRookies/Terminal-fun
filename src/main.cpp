#include <iostream>
#include <cstdlib>
#include "sprite.h"
#include "sprite-controller.h"
#include "utils.h"
#include "bitmap.h"
#include "comm.h"
#include "cmdline.h"

#define SPRITE_WIDTH        20
#define SPRITE_HEIGHT       10

Sprite my_sprite((uint8_t*)bmp_aeroplane, SPRITE_HEIGHT, SPRITE_WIDTH);
SpriteController controller(my_sprite);


int main(int argc, char * const argv[]) {
    int ret = EXIT_SUCCESS;

    // If no args are provided then perform simple scrolling.
    if(argc == 1) {
        controller.initDisplay(SPRITE_HEIGHT, SPRITE_WIDTH);
        controller.simpleScroll();
        goto end_main;
    }
    // Else perform cooperative scrolling...

    // Parse command-line args.
    try {
        CommandLine::parse(argc, argv);
    } catch (std::invalid_argument &e) {
        std::cerr << "[Term-fun] Error: " << e.what() << std::endl;
        ret = EXIT_FAILURE;
    }

    // Check if the program can proceed further.
    if(!CommandLine::execCanProceed())
        goto end_main;
    
    // Initialize comm system.
    try{
        Communication::init();
    } catch(std::exception &e) {
        std::cerr << "\n[Term-fun] Error: " << e.what() << std::endl;
        SHOW_USAGE();
        goto end_main;
    }

    controller.initDisplay(SPRITE_HEIGHT, SPRITE_WIDTH);

end_main:
    Communication::end();
    controller.endDisplay();
    return ret;
}
