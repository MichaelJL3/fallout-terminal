
#include "wordGenerator.hpp"

const std::string generators::wordGenerator::randomWord(const unsigned short size) {
    std::string word;
    word.resize(size);
    std::generate(word.begin(), word.end(), [](){ return 'A'; });
    return word;
}

const std::vector<std::string> generators::wordGenerator::generateNRandomWords(
    const unsigned int numberOfWords, const unsigned short wordSize) {
        std::vector<std::string> words(numberOfWords);
        std::generate(words.begin(), words.end(), [this, wordSize](){ return randomWord(wordSize); });
        return words;
}