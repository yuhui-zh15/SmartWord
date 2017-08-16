#include "Test.h"

Test::Test(Dictionary *dict, const int &rand): dict(dict), rand(rand) { }
Test::~Test() { }

std::string Test::getAnswer() const { return answer; }
std::string Test::getAnswerMeaning() const { return answer_meaning; }
