
#pragma once

#include <random>
#include <vector>
#include <functional>

namespace generators {
    class wordGenerator {
    public:
        const std::string randomWord(const unsigned short);
        const std::vector<std::string> generateNRandomWords(const unsigned int, const unsigned short);
    } typedef words;
}