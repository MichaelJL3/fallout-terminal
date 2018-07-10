
#pragma once

#include <random>
#include <algorithm>
#include <functional>

namespace generators {
    class sequenceGenerator {
        static const double seqCharsDist[];
        const std::function<unsigned char()> charGen;
    public:
        sequenceGenerator();
        const std::string randomSequence(const unsigned short);
        const unsigned char randomChar();
    } typedef sequences;
}