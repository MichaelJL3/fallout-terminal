
#pragma once

#include "window.hpp"

#include "../generators/hexGenerator.hpp"
#include "../generators/lineGenerator.hpp"
#include "../movement/position.hpp"
#include "../colors.hpp"

#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <iomanip>
#include <sstream>

namespace view {
    class termWin : public window {
        static const unsigned int HEAD_HEIGHT = 6;
        static const unsigned int BODY_WIDTH = 40;

        class headWin;
        class histWin;
        class bodyWin;

        headWin *head;
        histWin *hist;
        bodyWin *body;
    public:
        termWin(const unsigned int, const unsigned int, const unsigned int=0, const unsigned int=0);
        ~termWin();
        void print(const char*, const unsigned int=0, const unsigned int=0);
        void move(movement::position &);
        void move(const int=0, const int=0);
        void select();
        const bool attempts();
        const int get();
    };

    class termWin::headWin : public window {
        const char *welcome = "Welcome to ROBCO Industries (TM) Termlink";
        const char *auth = "Password Required";
        const char *remaining = "Attempts Remaining: ";

        class attemptWin;

        std::vector<attemptWin*> chances;
    public:
        headWin(window, const unsigned int, const unsigned int, const unsigned int=0, const unsigned int=0);
        ~headWin();
        void attempt();
        const bool attempts();
    };

    class termWin::headWin::attemptWin : public window {
    public:
        attemptWin(window, const unsigned int, const unsigned int, const unsigned int=0, const unsigned int=0);
        ~attemptWin();
    };

    class termWin::histWin : public window {
    public:
        histWin(window, const unsigned int, const unsigned int, const unsigned int=0, const unsigned int=0);
    };

    class termWin::bodyWin : public window {
        static const unsigned int HEX_WIDTH = 6;

        class contentWin;
    public:
        contentWin *left;
        contentWin *right;
        window* currWin;

        bodyWin(window, const unsigned int, const unsigned int, const unsigned int=0, const unsigned int=0);
        ~bodyWin();
        void switchWin();
        void move(movement::position &);
        void move(int=0, int=0);
    };

    class termWin::bodyWin::contentWin : public window {
    private:
        const unsigned int PRINT_DELAY = 15;

        generators::lines line;
        generators::hexs hex;
    public:
        window *hexWin;
        window *lineWin;

        contentWin(window, const unsigned int, const unsigned int, const unsigned int=0, const unsigned int=0);
        ~contentWin();
        window getLineWin();
        void fill(unsigned short &);
    };
}
