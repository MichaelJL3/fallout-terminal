
#include "termWin.hpp"

view::termWin::headWin::attemptWin::attemptWin(view::window ptr, const unsigned int rows, 
    const unsigned int cols, const unsigned int x, const unsigned int y) : 
    window(ptr, rows, cols, x, y) {
        init_pair(2, COLOR_BRIGHT_GREEN, COLOR_BRIGHT_GREEN);
        background(COLOR_PAIR(2));
}

view::termWin::headWin::attemptWin::~attemptWin() {
    background(COLOR_BLACK);
}