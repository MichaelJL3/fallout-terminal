
#pragma once

#include <random>
#include <sstream>
#include <iomanip>
#include <functional>

namespace generators {
    class hexGenerator {
        static const unsigned short HEX_INC = 12;
        static const unsigned short MAX_SHORT = 65100;
        const std::function<unsigned short()> hexGen;
        std::stringstream stream;
    public:
        hexGenerator();
        const std::string deterministicHexString(unsigned short &, const unsigned short = HEX_INC);
        const unsigned short deterministicHex(unsigned short &, const unsigned short = HEX_INC);
        const unsigned short randomHex();
    } typedef hexs;
}