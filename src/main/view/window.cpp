
#include "window.hpp"

view::window::window(const unsigned int rows, const unsigned int cols, 
    const unsigned int x, const unsigned int y) :
    winptr(newwin(rows, cols, y, x)),
    height(getmaxy(winptr)),
    width(getmaxx(winptr)) {
        refresh();
}

view::window::window(view::window &parent, const unsigned int rows, const unsigned int cols, 
    const unsigned int x, const unsigned int y) : 
    winptr(derwin(parent.winptr, rows, cols, y, x)),
    height(getmaxy(winptr)),
    width(getmaxx(winptr)) {
        refresh();
}

view::window::window(WINDOW* parent, const unsigned int rows, const unsigned int cols, 
    const unsigned int x, const unsigned int y) : 
    winptr(derwin(parent, rows, cols, y, x)),
    height(getmaxy(winptr)),
    width(getmaxx(winptr)) {
        if (parent == nullptr) throw "Initializing child window with no parent";
        refresh();
}

view::window::~window() {
    if (winptr != nullptr) {
        delwin(winptr);
    }
}

void view::window::nullCheck() {
    if (winptr == NULL || winptr == nullptr) {
        throw "window pointer null";
    }
}

void view::window::refresh() {
    nullCheck();
    wrefresh(winptr);
}

void view::window::keypadOn() {
    nullCheck();
    keypad(winptr, TRUE);
    refresh();
}

void view::window::keypadOff() {
    nullCheck();
    keypad(winptr, FALSE);
    refresh();
}

void view::window::background(const unsigned int pair) {
    nullCheck();
    wbkgd(winptr, pair);
    refresh();
}

void view::window::move(const unsigned int x, const unsigned int y) {
    nullCheck();
    wmove(winptr, y, x);
    refresh();
}

void view::window::print(const char *text, const unsigned int x, const unsigned int y) {
    nullCheck();
    mvwprintw(winptr, y, x, text);
    refresh();
}

const int view::window::get() {
    return wgetch(winptr);
}