#ifndef TEST_H_
#define TEST_H_

#include <string>
#include "Dictionary.h" 

class Test
{
public:
    Test(Dictionary *dict, const int &rand);
    virtual ~Test();
    virtual std::string getAnswer() const;
    virtual std::string getAnswerMeaning() const;

    virtual bool makeTest() = 0;
    virtual std::string getTest() const = 0;
    virtual std::string getTestAns() const = 0;
    virtual bool isCorrect(const std::string &userans) const = 0;

protected:
    Dictionary *dict;
    std::string answer_meaning;
    std::string answer;
    int rand;
};

#endif // TEST_H
