#include "Translation.h"
#include <fstream>
#include <iostream>

Translation::Translation(Dictionary *dict): dict(dict) { }
Translation::~Translation() { }

bool Translation::importFile(const std::string &filename) {
    std::ifstream fin(filename.c_str());
    if(!fin) {
        //std::cerr << "File can't open!" << std::endl;
        return false;
    }
    std::string tmp;
    while(getline(fin, tmp)) {
        rawstring = rawstring + tmp;
    }
    processRawString();
    return true;
}

bool Translation::setRawString(const std::string &rawstring) { this->rawstring = rawstring; processRawString(); return true; }
std::string Translation::getRawString() const { return rawstring; }
std::vector<std::string> Translation::getSplitWord() const { return splitword; }
std::vector<std::string> Translation::getSplitMeaning () const { return splitmeaning; }
std::string Translation::getOutString () const { return outstring; }


bool Translation::processRawString() {
    if(rawstring.length() == 0) {
        //std::cerr << "Please import Raw String!";
        return false;
    }

    std::string word_in_string = "";
    int pre = 0;
    for(unsigned i = 0; i != rawstring.length(); ++ i) {
        if((rawstring.at(i) >= 'a' && rawstring.at(i) <= 'z') || (rawstring.at(i) >= 'A' && rawstring.at(i) <= 'Z')) {
            continue;
        }
        else {
            word_in_string = rawstring.substr(pre, i - pre);
            if(word_in_string.length() > 0) {
                splitword.push_back(word_in_string);
            }
            pre = i + 1;
        }
    }
    word_in_string = rawstring.substr(pre, rawstring.length() - pre);
    if(word_in_string.length() > 0) {
        splitword.push_back(word_in_string);
    }
		
    std::string meaning_in_splitword = "";
    for(unsigned i = 0; i != splitword.size(); ++ i) {
        meaning_in_splitword = dict->getMeaning(splitword.at(i));
        splitmeaning.push_back(meaning_in_splitword);
        outstring = outstring + '[' + splitword.at(i) + ',' + ' ' + splitmeaning.at(i) + ']' + '\n';
    }
    return true;
}
