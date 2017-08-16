#ifndef CHINESETEST_H
#define CHINESETEST_H

#include "Test.h"
#include <vector>

class ChineseTest : public Test
{
public:
    ChineseTest(Dictionary *dict, const int &choice_num, const int &rand);
    ~ChineseTest();

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

#endif // ChineseTest_H
