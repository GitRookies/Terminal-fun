#include <unistd.h>
#include "sprite-controller.h"

void SpriteController :: initDisplay(int window_ht, int window_wd) {
    initscr();
    //raw();
    cbreak();
    noecho();
    
#ifdef USE_COLOR
    // Color mode on.
    if(has_colors() == FALSE) {
        endwin();
        std::cerr << "Your terminal does not support color" << std::endl;
        exit(1);
    }
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLUE);
    attron(COLOR_PAIR(1));
#endif

    m_window = newwin(window_ht, window_wd, 0, 0);
    if(!m_window) {
            std::cerr << "[Error]: SpriteController::SpriteController(): newwin() failed."
                << std::endl;
            throw std::exception();
    }
    refresh(); // Clear the initial window.
                // For some reason not doing this step prevents any other
                // output chars to be displayed.
    wrefresh(m_window);
}

void SpriteController :: endDisplay(void) {
    getch();
    endwin();
}

void SpriteController :: drawSprite() {
    uint8_t **_bitmap = m_sprite.bitmap();
    //int row = 0, col = 0;
    //attron(COLOR_PAIR(1));
    for(int i = 0; i < m_sprite.height(); ++i) {
        for(int j = 0; j < m_sprite.width(); ++j) {
            if(_bitmap[i][j] != 0) {
                mvwaddch(m_window, i, j, ACS_CKBOARD);   // ACS_BULLET
            }
        }
    }
    wrefresh(m_window);
    //attroff(COLOR_PAIR(1));
}

void SpriteController :: moveSprite(int y_shifts, int x_shifts) {
    werase(m_window);
    wrefresh(m_window);
    //int check;
    mvwin(m_window, m_window->_begy + y_shifts, m_window->_begx + x_shifts);
    wrefresh(m_window);
    //printw("(%d, %d)", check, m_window->_begx);
    //refresh();
    #if 0
    if( (m_window->_begx > 0) )//&& (m_window->_begx < m) )
        m_window->_begx += x_shifts;
    if( (m_window->_begy > 0) )//&& (m_window->_begy < m) )
        m_window->_begy += y_shifts;
    #endif
}

// Move the sprite window in the direction provided by arg1.
void SpriteController :: scrollSprite(Direction direction) {
    switch (direction) {
        case LEFT:
            moveSprite(-1, 0);
            break;
        case RIGHT:
            moveSprite(1, 0);
            break;
        case UP:
            moveSprite(0, -1);
            break;
        case DOWN:
            moveSprite(0, 1);
            break;
    }
}

void SpriteController :: simpleScroll(void) {
    moveSprite(getmaxy(stdscr)/2, COLS - m_sprite.width());
    drawSprite();
    for(int col = COLS - m_sprite.width() - 1; col >= 0; col--) {
        moveSprite(0, -1); // Move by 1 position to the right.
        drawSprite();
        usleep(20000);
    }
}