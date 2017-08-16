#ifndef TRANSLATION_H_
#define TRANSLATION_H_

#include <string>
#include <vector>
#include "Dictionary.h"

class Translation
{
public:
    Translation(Dictionary *dict);
    virtual ~Translation();
    bool importFile(const std::string &filename);
    bool setRawString(const std::string &rawstring);

    bool processRawString();

    std::string getRawString() const;
    std::vector<std::string> getSplitWord() const;
    std::vector<std::string> getSplitMeaning () const;
    std::string getOutString() const;

private:
    std::string rawstring;
    std::vector<std::string> splitword;
    std::vector<std::string> splitmeaning;
    std::string outstring;
    Dictionary *dict;
};

#endif // TRANSLATION_H
