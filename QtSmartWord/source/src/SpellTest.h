#ifndef SPELLTEST_H_
#define SPELLTEST_H_

#include "Test.h"

class SpellTest : public Test
{
public:
    SpellTest(Dictionary *dict, const int &rand);
    ~SpellTest();

    bool makeTest();

    int getLength() const;
    std::string getTest() const;
    std::string getTestAns() const;

    bool isCorrect(const std::string &userans) const;

private:
    int length;
};

#endif // SPELLTEST_H_
