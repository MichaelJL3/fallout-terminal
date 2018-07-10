
#include "lineGenerator.hpp"

const double generators::lineGenerator::wordLengthWeights[] = {
    0, 0, 0, 0, //lengths 0 - 3 impossible
    5, 3, 2, .5, .5
};

const double generators::lineGenerator::numberOfWordsWeights[] = {
    0, 0, 0, 0, //number of words 0 - 3 impossible
    .3, .5, .8, 1, 1, 1, 1, 1, .8, .5, .3
};

generators::lineGenerator::lineGenerator() :
    wordSize(std::bind(
        std::discrete_distribution<>(
            std::begin(wordLengthWeights), 
            std::end(wordLengthWeights)
        ),
        std::mt19937(std::random_device{}())
    )()),
    numberOfWords(std::bind(
        std::discrete_distribution<>(
            std::begin(numberOfWordsWeights), 
            std::end(numberOfWordsWeights)
        ),
        std::mt19937(std::random_device{}())
    )()),
    words(generateNRandomWords(numberOfWords, wordSize))
{

}

generators::lineGenerator::lineGenerator(
    const unsigned short wordsize, const unsigned short numberofwords) : 
        wordSize(wordsize), 
        numberOfWords(numberofwords),
        words(generateNRandomWords(numberOfWords, wordSize))
{

}

const std::string generators::lineGenerator::randomLine(const unsigned short size) {
    return (shouldContainWord()) ? randomLineWithWord(size) : randomLineWithoutWord(size);
}

const std::string generators::lineGenerator::randomLineWithWord(const unsigned short size) {
    if (size < wordSize) throw "Word index out of bounds";

    std::stringstream stream;
    unsigned short index = beginningIndexOfWord(size - wordSize);
    
    stream << randomSequence(index) 
        << words[wordIndex++] 
        << randomSequence(size - index - wordSize);
    
    return stream.str();
}

const std::string generators::lineGenerator::randomLineWithoutWord(const unsigned short size) {
    return randomSequence(size);
}

const std::vector<std::string> generators::lineGenerator::generateNRandomLines(
    const unsigned int numberOfLines, const unsigned short lineSize) {
        std::vector<std::string> lines(numberOfLines);
        std::generate(lines.begin(), lines.end(), [this, lineSize](){ return randomLine(lineSize); });
        return lines;
}

const std::vector<std::string> generators::lineGenerator::generateNRandomShuffledLines(
    const unsigned int numberOfLines, const unsigned short lineSize) {
        std::vector<std::string> lines = generateNRandomLines(numberOfLines, lineSize);
        std::random_shuffle(lines.begin(), lines.end());
        return lines;
}

const unsigned short generators::lineGenerator::beginningIndexOfWord(const unsigned short limit) {
    return indexGen() % (limit + 1);
}

const bool generators::lineGenerator::shouldContainWord() {
    return wordIndex != numberOfWords;
}

std::ostream& generators::operator << (std::ostream &stream, const generators::lineGenerator &lg) {
    stream << "[" << std::endl
        << "\tnumber of words: " << lg.numberOfWords << std::endl
        << "\tsize of words: " << lg.wordSize << std::endl
        << "\twords: ";
        
    std::copy(lg.words.cbegin(), lg.words.cend() - 1, std::ostream_iterator<std::string>(stream, ", "));

    stream << lg.words.back() << std::endl << "]" << std::endl;

    return stream;
}