#ifndef TESTLIST_H_
#define TESTLIST_H_

#include "Test.h"
#include "Dictionary.h"
#include <vector>

class TestList
{
public:
    TestList(int num_ETOC, int num_CTOE, int num_SPEL, Dictionary *dict);
    virtual ~TestList();
    bool makeTestList();
    bool clearList();
    std::vector<Test *> getTestList() const;

private:
    std::vector<Test *> testlist;
    Dictionary* dict;
    int num_ETOC;
    int num_CTOE;
    int num_SPEL;
};

#endif // TESTLIST_H
