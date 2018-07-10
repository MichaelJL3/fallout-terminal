
#include "termWin.hpp"

view::termWin::headWin::headWin(view::window ptr, const unsigned int rows, const unsigned int cols, 
    const unsigned int x, const unsigned int y)
        : window(ptr, rows, cols, x, y) { 
            print(welcome);
            print(auth, 0, 2);
            print(remaining, 0, 4);

        chances.push_back(new attemptWin(*this, 1, 1, 20, 4));
        chances.push_back(new attemptWin(*this, 1, 1, 22, 4));
        chances.push_back(new attemptWin(*this, 1, 1, 24, 4));
        chances.push_back(new attemptWin(*this, 1, 1, 26, 4));
        refresh();
}

view::termWin::headWin::~headWin() {
    for (auto win : chances) {
        delete win;
    }
    chances.clear();
}

void view::termWin::headWin::attempt() {
    if (chances.size()) {
        auto win = chances.back();
        chances.pop_back();
        delete win;
    }
}

const bool view::termWin::headWin::attempts() {
    return chances.size() ? true : false;
}