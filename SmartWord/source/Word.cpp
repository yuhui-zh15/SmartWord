#include "Word.h"

Word::Word(const std::string& word) 
    :word(word), numOfExample(0), degree(0) { }

Word::Word(const std::string &word, const std::string &meaning)
    :word(word), meaning(meaning), numOfExample(0), degree(0) { }

Word::~Word() { }

std::string Word::getWord() const { return this->word; }

std::string Word::getMeaning() const { return this->meaning; }

std::string Word::getExample(const int &pos) const { return this->example.at(pos); }

std::string Word::getTranslation(const int &pos) const { return this->translation.at(pos); }

std::string Word::getAllExample() const {
    int num = getNumOfExample();
    std::string output = "Examples:\n";
    for (int i = 0; i < num; i++) {
        char tmp = '1' + i ;
        output = output +'[' +tmp + "]:\n " ;
        output = output + getExample(i) + "\n ";
        output = output + getTranslation(i) + "\n ";
        output = output + "\n";
    }
    if ( num == 0 ) 
    {
        output = output + "No examples available!\n" ;
    }
    //std::cerr << output << std::endl;
    return output;
}

int Word::getDegree() const { return this->degree; }

int Word::getNumOfExample() const { return this->numOfExample; }

bool Word::setMeaning(const std::string &meaning) {
	this->meaning = meaning; 
    return true;
}

bool Word::setDegree(const int &degree) {
	this->degree = degree; 
    return true;
}

bool Word::addExample(const std::string &example, const std::string &translation) {
    this->example.push_back(example);
    this->translation.push_back(translation);
    this->numOfExample ++;
    //std::cerr << numOfExample << std::endl;
    return true;
}

bool Word::modifyWord(const std::string &new_word, const std::string &new_meaning) {
    this->word = new_word;
    this->meaning = new_meaning;
    return true;
}

bool Word::operator < (const Word &next) const {
	return word < next.word;
}

bool Word::operator () (const Word &n1, const Word &n2) const {
	return n1.word < n2.word; 
}

std::ostream& operator <<(std::ostream &out, Word &obj) {
	out << std::endl << "[" << obj.word << ", " << obj.meaning << "]   (Difficulty: " << obj.degree << " )" << std::endl
        << obj.getAllExample() << std::endl ;
	return out;
}
