
#pragma once 

#include <istream>

namespace movement {
    struct position {
        int y = 0;
        int x = 0;
        position(int=0, int=0);
        friend std::ostream& operator << (std::ostream&, const position&);
    };

    std::ostream& operator << (std::ostream&, const position&);
}