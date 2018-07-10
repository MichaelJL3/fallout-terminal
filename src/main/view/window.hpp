
#include <ncurses.h>

namespace view {
    struct window {
        WINDOW* winptr;
        const unsigned int height;
        const unsigned int width;
        window(const unsigned int, const unsigned int, const unsigned int=0, const unsigned int=0);
        window(window& parent, const unsigned int, const unsigned int, const unsigned int=0, const unsigned int=0);
        window(WINDOW* parent, const unsigned int, const unsigned int, const unsigned int=0, const unsigned int=0);
        ~window();
        void refresh();
        void keypadOn();
        void keypadOff();
        void background(const unsigned int);
        void print(const char*, const unsigned int=0, const unsigned int=0);
        void move(const unsigned int=0, const unsigned int=0);
        const int get();
    private:
        void nullCheck();
    } typedef win;
}