
#include "termWin.hpp"

view::termWin::termWin(const unsigned int rows, const unsigned int cols, 
    const unsigned int x, const unsigned int y) 
        : window(rows, cols, x, y) {
            init_pair(1, COLOR_BRIGHT_GREEN, COLOR_BLACK);
            background(COLOR_PAIR(1));

            head = new headWin(*this, HEAD_HEIGHT, 0, 0, 0);
            body = new bodyWin(*this, 0, BODY_WIDTH, 0, HEAD_HEIGHT);
            hist = new histWin(*this, 0, 0, BODY_WIDTH, HEAD_HEIGHT);
            move();
}

view::termWin::~termWin() {
    if (head != nullptr) delete head;
    if (body != nullptr) delete body;
    if (hist != nullptr) delete hist;
}

void view::termWin::print(const char* text, const unsigned int x, const unsigned int y) {
    hist->print(text, x, y);
}

void view::termWin::select() {
    head->attempt();
}

void view::termWin::move(movement::position &pos) {
    body->move(pos);
}

void view::termWin::move(const int x, const int y) {
    body->move(x, y);
}

const bool view::termWin::attempts() {
    return head->attempts();
}

const int view::termWin::get() {
    return body->currWin->get();
}