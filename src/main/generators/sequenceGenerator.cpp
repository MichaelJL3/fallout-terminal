
#include "sequenceGenerator.hpp"

const double generators::sequenceGenerator::seqCharsDist[] = {
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 1, 1,
    1, 1, 0, 1, 1,
    1, 1, 1, 1, 1,
    1, 1, 1, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 1, 1,
    1, 1, 1, 1, 1,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 1,
    1, 1, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 
    1, 1,
};

generators::sequenceGenerator::sequenceGenerator() : 
    charGen(std::bind(
        std::discrete_distribution<>(
            std::begin(seqCharsDist), 
            std::end(seqCharsDist)
        ),
        std::mt19937(std::random_device{}())
    )) {}

const std::string generators::sequenceGenerator::randomSequence(const unsigned short size) {
    std::string sequence;
    sequence.resize(size);
    std::generate(sequence.begin(), sequence.end(), [this](){ return charGen(); });
    return sequence;
}

const unsigned char generators::sequenceGenerator::randomChar() {
    return charGen();
}