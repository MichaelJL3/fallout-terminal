
#include "termWin.hpp"

view::termWin::bodyWin::bodyWin(view::window ptr, const unsigned int rows, const unsigned int cols, 
    const unsigned int x, const unsigned int y)
        : window(ptr, rows, cols, x, y) {
            int half = cols / 2;
            left = new contentWin(*this, rows, half, 0, 0);
            right = new contentWin(*this, rows, half, half, 0);

            unsigned short base = generators::hexs().randomHex();
            left->fill(base);
            right->fill(base);

            currWin = left->lineWin;
}

view::termWin::bodyWin::~bodyWin() {
    if (left != nullptr) delete left;
    if (right != nullptr) delete right;
}

void view::termWin::bodyWin::move(movement::position &pos) {
    if (pos.y < 0) {
        pos.y = 0;
    } else if (pos.y >= currWin->height) {
        pos.y = currWin->height - 1;
    }

    if (currWin == left->lineWin) {
        if (pos.x >= currWin->width) {
            switchWin();
            pos.x = 0;
        } else if (pos.x < 0) {
            pos.x = 0;
        }
    } else {
        if (pos.x < 0) {
            switchWin();
            pos.x = currWin->width - 1;
        } else if (pos.x >= currWin-> width) {
            pos.x = currWin-> width - 1;
        }
    }

    currWin->move(pos.x, pos.y);
}

void view::termWin::bodyWin::move(int x, int y) {
    if (y < 0) {
        y = 0;
    } else if (y >= currWin->height) {
        y = currWin->height - 1;
    }

    if (currWin == left->lineWin) {
        if (x >= currWin->width) {
            switchWin();
            x = 0;
        } else if (x < 0) {
            x = 0;
        }
    } else {
        if (x < 0) {
            switchWin();
            x = currWin->width - 1;
        } else if (x >= currWin-> width) {
            x = currWin-> width - 1;
        }
    }

    currWin->move(x, y);
}

void view::termWin::bodyWin::switchWin() {
    currWin = (currWin == left->lineWin) ? right->lineWin : left->lineWin;
}