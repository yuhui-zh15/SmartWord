#include "Recite.h"
#include "Random.h"

Recite::Recite(Dictionary *dict, const int &num): dict(dict), num(num)
{ }

Recite::~Recite() { }

std::vector<Word> Recite::makeReciteList() {
    std::vector<Word> ret;
    Random random;
    int *ran = random.getMultiRand(num, 0, dict->getDictSize());
    for (int i = 0; i < num; i ++) {
        ret.push_back(dict->getSpecificWord(ran[i]));
    }
    return ret;
}
