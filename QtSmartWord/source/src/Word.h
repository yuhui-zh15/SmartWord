#ifndef WORD_H_
#define WORD_H_

#include <string>
#include <iostream>
#include <vector>

class Word
{
public:

    Word(const std::string &word);
	Word(const std::string &word, const std::string &meaning);
    ~Word();

	std::string getWord() const;
	std::string getMeaning() const;
    std::string getExample(const int &pos) const;
    std::string getTranslation(const int &pos) const;
    std::string getAllExample() const;
    int getDegree() const;
    int getNumOfExample() const;

    bool setMeaning(const std::string &meaning);
    bool addExample(const std::string &example, const std::string &translation);
    bool modifyWord(const std::string &new_word, const std::string &new_meaning);
    bool setDegree(const int &degree);

	bool operator < (const Word& next) const;
	bool operator () (const Word& n1, const Word& n2) const;
    friend std::ostream &operator <<(std::ostream &out, Word& obj);

private:

	std::string word;
	std::string meaning;
    std::vector<std::string> example;
    std::vector<std::string> translation;
    int numOfExample;
	int degree;
};

#endif
