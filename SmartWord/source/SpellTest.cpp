#include "SpellTest.h"
#include <cstdio>

SpellTest::SpellTest(Dictionary *dict, const int &rand): Test(dict, rand) {
    makeTest();
}
SpellTest::~SpellTest() { }

bool SpellTest::makeTest()
{
    Word choice = dict->getSpecificWord(rand) ;
    answer = choice.getWord() ;
    answer_meaning = choice.getMeaning() ;
    length = answer.length() ;
    return true;
}

int SpellTest::getLength() const {
    return length;
}

std::string SpellTest::getTest() const {
    std::string ret = "";
    ret = ret + getAnswerMeaning() + "\n";
    char len[5];
    sprintf(len, "%d", getLength());
    ret = ret + "Length = " + len + "\n";
    return ret;
}

std::string SpellTest::getTestAns() const {
    return ("Correct Answer is " + getAnswer() + " " + getAnswerMeaning() + "\n");
}

bool SpellTest::isCorrect(const std::string &userans) const {
    if(userans == getAnswer()) {
        
        return true;
    }
    else {
        return false;
    }
}
