
#include "boundedPosition.hpp"

movement::boundedPosition::boundedPosition(const unsigned int x, const unsigned int y, const unsigned int w, const unsigned int h) : 
    position(x, y),
    width(w), 
    height(h){
        if (x > w || y > h) throw "Position out of bounds";
}

bool movement::boundedPosition::isOutOfBounds() {
    return x > width || y > height;
}

bool movement::boundedPosition::isOutOfBounds(const unsigned int x, const unsigned int y) {
    return x > width || y > height;
}