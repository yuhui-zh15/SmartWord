#include "ChineseTest.h"

ChineseTest::ChineseTest(Dictionary *dict, const int &choice_num, const int &rand): Test(dict, rand), choice_num(choice_num) {
    makeTest();
}
ChineseTest::~ChineseTest() { }

bool ChineseTest::makeTest() {
    answer_choice = rand % choice_num;
    for (int i = 0; i < choice_num ; ++i) {
        Word choice = dict->getSpecificWord(rand + i);
        all_choice.push_back(choice.getWord());
        if ( i == answer_choice ) {
            answer = choice.getWord();
            answer_meaning = choice.getMeaning();
        }
    }
    return true;
}

std::string ChineseTest::getChoice(const int &choice) const {
    return all_choice.at(choice);
}

int ChineseTest::getAnswerChoice() const {
    return answer_choice;
}

std::string ChineseTest::getTest() const {
    std::string ret = "";
    ret = ret + getAnswerMeaning() + '\n';
    for(int i = 0; i < choice_num; i++) {
        char ans = i + 1 + '0';
        ret = ret + '[' + ans + ']' + ' ' + all_choice.at(i) + '\n';
    }
    return ret;
}

std::string ChineseTest::getTestAns() const {
    char ans = getAnswerChoice() + 1 + '0';
    std::string ret = "";
    ret = ret + "Correct Answer is [";
    ret = ret + ans;
    ret = ret + "]" + getAnswer() + " " + getAnswerMeaning() + "\n";
    return ret;
}

bool ChineseTest::isCorrect(const std::string &userans) const {
    int user_choice = userans.at(0) - '0';
    if(user_choice == (getAnswerChoice() + 1)) {
        return true;
    }
    else {
        return false;
    }
}
