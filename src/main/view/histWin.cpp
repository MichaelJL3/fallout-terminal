
#include "termWin.hpp"

view::termWin::histWin::histWin(view::window ptr, const unsigned int rows, const unsigned int cols, 
    const unsigned int x, const unsigned int y)
        : window(ptr, rows, cols, x, y) {
}