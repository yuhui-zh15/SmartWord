#ifndef HISTORY_H
#define HISTORY_H

#include "Word.h"
#include <vector>
#include <string>

class History
{
public:
    History();
    virtual ~History();
    bool addWord(const Word &word);
    bool isExisted(const Word &word) const;
    bool addWordWithoutDuplicate(const Word &word);
    bool deleteWord(const int &index);
    bool deleteAllWord();
    Word getWord(const int &index) const;
    std::vector<Word> getAllWord() const;
    std::string getAllWordString() const;
    int getHistorySize() const;
    bool importHistory(const std::string &filename);
    bool exportHistory(const std::string &filename);
private:
    std::vector<Word> history;
};

#endif // HISTORY_H
