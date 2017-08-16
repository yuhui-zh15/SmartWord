#ifndef RECITE_H
#define RECITE_H

#include <vector>
#include <string>
#include "Word.h"
#include "Dictionary.h"

class Recite
{
public:
    Recite(Dictionary *dict, const int &num);
    virtual ~Recite();
    std::vector<Word> makeReciteList();
private:
    Dictionary *dict;
    int num;
};

#endif // RECITE_H
