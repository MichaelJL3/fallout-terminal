
#pragma once

#include <random>
#include <vector>
#include <istream>
#include <sstream>
#include <iterator>
#include <functional>
#include "sequenceGenerator.hpp"
#include "wordGenerator.hpp"

namespace generators {
    class lineGenerator : wordGenerator, sequenceGenerator {
        //private variables
        static const unsigned short MIN_INDEX = 0;
        static const unsigned short MAX_INDEX = 65535;
        static const double wordLengthWeights[];
        static const double numberOfWordsWeights[];
        unsigned short wordIndex = 0;

        //private methods
        const bool shouldContainWord();
        const std::string randomLineWithWord(const unsigned short);
        const std::string randomLineWithoutWord(const unsigned short);
        const unsigned short beginningIndexOfWord(const unsigned short);
        const std::function<unsigned short()> indexGen = std::bind(
            std::uniform_int_distribution<>(MIN_INDEX, MAX_INDEX),
            std::mt19937(std::random_device{}())
        );
    public:
        //public variables
        const unsigned short wordSize;
        const unsigned short numberOfWords;
        const std::vector<std::string> words;

        //public methods
        lineGenerator();
        lineGenerator(const unsigned short, const unsigned short);
        const std::string randomLine(const unsigned short);
        const std::vector<std::string> generateNRandomLines(const unsigned int, const unsigned short);
        const std::vector<std::string> generateNRandomShuffledLines(const unsigned int, const unsigned short);
        friend std::ostream& operator << (std::ostream&, const lineGenerator&);
    } typedef lines;

    std::ostream& operator << (std::ostream &stream, const lineGenerator &lg);
}