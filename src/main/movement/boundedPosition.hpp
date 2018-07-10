
#pragma once 

#include "position.hpp"

namespace movement {
    struct boundedPosition : position {
        const unsigned int width;
        const unsigned int height;
        boundedPosition(const unsigned int, const unsigned int, const unsigned int=0, const unsigned int=0);
        bool isOutOfBounds();
        bool isOutOfBounds(const unsigned int x, const unsigned int y);
    };
}