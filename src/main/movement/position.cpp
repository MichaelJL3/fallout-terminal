
#include "position.hpp"

movement::position::position(int x, int y) : x(x), y(y){

}

std::ostream& movement::operator << (std::ostream &stream, const position &pos) {
    return stream << "(" << pos.x << ", " << pos.y << ")";
}