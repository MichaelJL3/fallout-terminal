
#include "termWin.hpp"

view::termWin::bodyWin::contentWin::contentWin(view::window ptr, const unsigned int rows, const unsigned int cols, 
    const unsigned int x, const unsigned int y)
        : window(ptr, rows, cols, x, y) {
            hexWin = new window(*this, rows, HEX_WIDTH, 0, 0);
            lineWin = new window(*this, rows, 12, HEX_WIDTH + 1, 0);
            lineWin->keypadOn();
}

view::termWin::bodyWin::contentWin::~contentWin() {
    if (hexWin != nullptr) delete hexWin;
    if (lineWin != nullptr) delete lineWin;
}

void view::termWin::bodyWin::contentWin::fill(unsigned short &base) {
    std::string hexStr;
    std::string lineStr;

    for (int i = 0; i < height; ++i) {
        hexStr = hex.deterministicHexString(base);
        lineStr = line.randomLine(12);
        char c;

        for (int j = 0; j < hexStr.length(); ++j) {
            c = hexStr[j];
            std::this_thread::sleep_for(std::chrono::milliseconds(PRINT_DELAY));
            hexWin->print(&c, j, i);
        }

        for (int j = 0; j < lineStr.length(); ++j) {
            c = lineStr[j];
            std::this_thread::sleep_for(std::chrono::milliseconds(PRINT_DELAY));
            lineWin->print(&c, j, i);
        }
    }
}