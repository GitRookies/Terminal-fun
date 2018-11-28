#include "sprite-controller.h"

void SpriteController :: initDisplay(int window_ht, int window_wd) {
    initscr();
    m_window = newwin(window_ht, window_wd, 0, 0);
    if(!m_window) {
            std::cerr << "[Error]: SpriteController::SpriteController(): newwin() failed."
                << std::endl;
            throw std::exception();
    }
}

void SpriteController :: endDisplay(void) {
    getch();
    endwin();
}

void SpriteController :: drawSprite() {
    uint8_t **_bitmap = m_sprite.bitmap();
    //int row = 0, col = 0;
    for(int i = 0; i < m_sprite.height(); ++i) {
        for(int j = 0; j < m_sprite.width(); ++j) {
            if(_bitmap[i][j] != 0) {
                mvwaddch(m_window, i, j, (char)_bitmap[i][j]);
            }
        }
    }
}