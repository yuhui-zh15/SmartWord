#ifndef ENGLISHTEST_H_
#define ENGLISHTEST_H_

#include "Test.h"
#include <vector>

class EnglishTest : public Test
{
public:
    EnglishTest(Dictionary *dict, const int &choicenum, const int &rand);
    ~EnglishTest();

    bool makeTest();

    std::string getChoice(const int &choice) const;
    int getAnswerChoice() const;
    std::string getTest() const;
    std::string getTestAns() const;

    bool isCorrect(const std::string &userans) const;

private:
    std::vector<std::string> all_choice;
    int choice_num;
    int answer_choice;
};

#endif // ENGLISHTEST_H_
