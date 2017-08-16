#include "History.h"
#include <fstream>
#include <sstream>
#include <iostream>

History::History() { }
History::~History() { }

bool History::addWord(const Word &word) {
    this->history.push_back(word);
    return true;
}

bool History::isExisted(const Word &word) const {
    for (unsigned i = 0; i != history.size(); ++ i) {
        if(word.getWord() == history.at(i).getWord()) {
            return true;
        }
    }
    return false;
}

bool History::addWordWithoutDuplicate(const Word &word) {
    if(!isExisted(word)) {
        this->history.push_back(word);
        return true;
    }
    else {
        return false;
    }
}

bool History::deleteWord(const int &index) {
    if((unsigned)index <= history.size()) {
        std::vector<Word>::iterator iter = history.begin() + (index - 1);
        this->history.erase(iter);
        return true;
    }
    else {
        //std::cerr << "Error: memory limit!" << std::endl;
        return false;
    }
}

bool History::deleteAllWord() {
    this->history.erase(history.begin(), history.end());
    return true;
}

Word History::getWord(const int &index) const {
    return this->history.at(index);
}

std::vector<Word> History::getAllWord() const {
    std::vector<Word> ret;
    for (unsigned i = 0; i != history.size(); ++ i) {
        ret.push_back(history.at(i));
    }
    return ret;
}

std::string History::getAllWordString() const {
    std::string ret = "";

    for (unsigned i = 0; i != history.size(); ++ i) {
        int tmp = 1 + i;
        std::stringstream in;
        in << tmp;
        std::string ss = in.str();
        ret = ret + "[" + ss + "]: " + history.at(i).getWord() + ' ' + history.at(i).getMeaning();
        ret = ret + '\n';
    }
    return ret;
}

int History::getHistorySize() const {
    return this->history.size();
}

extern std::vector<std::string> getSplitWord(std::string line);

bool History::importHistory(const std::string& filename) {

    std::ifstream fin(filename.c_str());
    if(!fin) {
        //std::cerr << "File can not open!" << std::endl;
        return false;
    }

    std::string line = "";
    while(getline(fin, line)) {
        const std::vector<std::string> &argv = getSplitWord(line);
        const std::string &word = argv.at(0);
        const std::string &meaning = argv.at(1);
        History::addWord(Word(word, meaning));
    }
    fin.close();
    return true;
}

bool History::exportHistory(const std::string &filename) {

    std::ofstream fout(filename.c_str());
    if(!fout) {
        //std::cerr << "File can not write!" << std::endl;
        return false;
    }

    for(unsigned i = 0; i != history.size(); ++ i) {
        const Word &word_in_history = history.at(i);
        fout << word_in_history.getWord() << '|' << word_in_history.getMeaning() << std::endl;
    }
    fout.close();
    return true;
}
