#include "TestList.h"
#include "EnglishTest.h"
#include "ChineseTest.h"
#include "SpellTest.h"
#include "Random.h"

TestList::TestList(int num_ETOC, int num_CTOE, int num_SPEL, Dictionary *dict)
    : dict(dict), num_ETOC(num_ETOC), num_CTOE(num_CTOE), num_SPEL(num_SPEL) { }

TestList::~TestList() { }

bool TestList::clearList() {
    for (unsigned i = 0; i != testlist.size(); ++ i) {
        delete testlist.at(i);
    }
    return true;
}

bool TestList::makeTestList() {
    Random ran;
    int all = num_ETOC + num_CTOE + num_SPEL;
    int *rand = ran.getMultiRand(all + 4, 0, dict->getDictSize() - 4);
    for (int i = 0; i < num_ETOC; i++) {
        Test *new_test = new EnglishTest(dict, 4, rand[i]);
        testlist.push_back(new_test);
    }
    for (int i = 0; i < num_CTOE; i++) {
        Test *new_test = new ChineseTest(dict, 4, rand[i+num_ETOC]);
        testlist.push_back(new_test);
    }
    for (int i = 0; i < num_SPEL; i++) {
        Test *new_test = new SpellTest(dict, rand[i+num_ETOC+num_CTOE]);
        testlist.push_back(new_test);
    }
//    std::cerr << testlist.size() << std::endl;
    return true;
}

std::vector<Test *> TestList::getTestList() const {
    return testlist;
}
