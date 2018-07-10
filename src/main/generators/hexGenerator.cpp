
#include "hexGenerator.hpp"

generators::hexGenerator::hexGenerator() : hexGen(std::bind(
    std::uniform_int_distribution<>(0, MAX_SHORT),
    std::mt19937(std::random_device{}()))
){}

const unsigned short generators::hexGenerator::randomHex() {
    return hexGen();
}

const unsigned short generators::hexGenerator::deterministicHex(unsigned short &base, const unsigned short incr) {
    base += incr;
    return base;
}

const std::string generators::hexGenerator::deterministicHexString(unsigned short &base, const unsigned short incr) {
    stream.str(std::string());
    stream << "0x" << std::setfill('0') << std::setw(4) 
            << std::hex << std::uppercase << deterministicHex(base, incr);

    return stream.str();
}