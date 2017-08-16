#include "Dictionary.h"
#include "Word.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

std::vector<std::string> getSplitWord(std::string line) {
    int len = line.length();
    int pre = 0;
    std::vector<std::string> ret;
    for (int i = 0; i < len; ++i) {
        if(line[i] == '|') {
            std::string arg = line.substr(pre, i - pre);
            ret.push_back(arg);
            pre = i + 1;
        }
    }
    std::string arg = line.substr(pre, len - pre);
    ret.push_back(arg);
    return ret;
}

Dictionary::Dictionary() { }

Dictionary::~Dictionary() { }

bool Dictionary::importDict(const std::string& filename) {

    std::ifstream fin(filename.c_str());
    if(!fin) {
	//	std::cerr << "File can not open!" << std::endl;
		return false;
	}

    std::string line = "";
    while(getline(fin, line)) {
        const std::vector<std::string> &argv = getSplitWord(line);
        const std::string &word = argv.at(0);
        const std::string &meaning = argv.at(1);
        int degree;
        if(argv.size() > 2) {
            degree = argv.at(2)[0] - '0';
            if (degree == 0)
            {
                degree = (word.length() - 2) / 2;
                if (degree < 1) degree = 1;
                if (degree > 5) degree = 5;
            }
        }
        Dictionary::addWord(word, meaning, degree);
	}
    fin.close();
    return true;
}

bool Dictionary::exportDict(const std::string &filename) {

    std::ofstream fout(filename.c_str());
    if(!fout) {
    //    std::cerr << "File can not write!" << std::endl;
        return false;
    }

    std::set<Word>::iterator iter;
    for(iter = Dict.begin(); iter != Dict.end(); ++iter) {
        const Word &word_in_dict = *iter;
        fout << word_in_dict.getWord() << '|' << word_in_dict.getMeaning() << '|' << word_in_dict.getDegree() << std::endl;
    }
    fout.close();
    return true;
}

bool Dictionary::importExample(const std::string &filename) {

    std::ifstream fin(filename.c_str());
    if(!fin) {
      //  std::cerr << "File can not open!" << std::endl;
        return false;
    }

    std::string line = "";
    while(getline(fin, line)) {
        const std::vector<std::string> &argv = getSplitWord(line);
        const std::string &word = argv.at(0);
        int len = argv.size();
        for (int i = 1; i < len; i += 2) {
            const std::string &example = argv.at(i);
            const std::string &translation = argv.at(i+1);
            Dictionary::addExample(word, example, translation);
        }
    }
    fin.close();
    return true;
}

bool Dictionary::exportExample(const std::string &filename) {

    std::ofstream fout(filename.c_str());
    if(!fout) {
      //  std::cerr << "File can not write!" << std::endl;
        return false;
    }

    std::set<Word>::iterator iter;
    for(iter = Dict.begin(); iter != Dict.end(); ++iter) {
        const Word &word_in_dict = *iter;
        int len = word_in_dict.getNumOfExample();
        if(len > 0) {
            fout << word_in_dict.getWord();
            for (int i = 0; i < len; i ++) {
                fout << '|' << word_in_dict.getExample(i);
                fout << '|' << word_in_dict.getTranslation(i);
            }
            fout << std::endl ;
        }
    }
    fout.close();
    return true;
}

std::set<Word>::iterator Dictionary::searchWordWithIter(const std::string &word) const {
    const Word search_word(word);
    std::set<Word>::iterator iter;
    iter = Dict.find(search_word);
    return iter;
}

bool Dictionary::isExisted(const std::string &word) {
    std::set<Word>::iterator iter;
    iter = searchWordWithIter(word);
    if(iter != Dict.end()) {
        return true;
    }
    else {
        return false;
    }
}

Word Dictionary::getSearchWord(const std::string& word) const {

	std::set<Word>::iterator iter;
    iter = searchWordWithIter(word);

    if(iter != Dict.end()) {
        return *iter;
    }

    else {
       // std::cerr << "Can not find the word!" << std::endl;
        return Word("NULL", "Can't Find the Word!");
    }
}

int Dictionary::getDictSize() const {
    return Dict.size();
}

bool Dictionary::addWord(const std::string &word, const std::string &meaning, const int &degree)
{
    Word add_word(word, meaning);
    add_word.setDegree(degree);
    bool ret = Dict.insert(add_word).second;
    return ret;
}

bool Dictionary::addExample(const std::string &word, const std::string &example, const std::string &translation) {
    std::set<Word>::iterator iter = Dictionary::searchWordWithIter(word);

    if(iter == Dict.end()) {
        //std::cerr << "Word not exists!" << std::endl;
        return false;
    }
    else {
        Word search_word = *iter;
        search_word.addExample(example, translation);
        Dict.erase(iter);
        Dict.insert(search_word);
        return true;
    }
}

bool Dictionary::modifyWord(const std::string &word, const std::string &new_meaning, const int &new_degree) {
    std::set<Word>::iterator iter = Dictionary::searchWordWithIter(word);

    if(iter == Dict.end()) {
        //std::cerr << "Word not exists!" << std::endl;
        return false;
    }
    else {
        Word search_word = *iter;
        search_word.modifyWord(word, new_meaning);
        search_word.setDegree(new_degree);
        Dict.erase(iter);
        Dict.insert(search_word);
        return true;
    }
}

bool Dictionary::setDegree(const std::string &word, const int &new_degree) {
    
    std::set<Word>::iterator iter = Dictionary::searchWordWithIter(word);
    if(iter == Dict.end()) {
        //std::cerr << "Word not exists!" << std::endl;
        return false;
    }
    else {
        Word search_word = *iter;
        search_word.setDegree(new_degree);
        Dict.erase(iter);
        Dict.insert(search_word);
        return true;
    }
}

std::string Dictionary::getMeaning(const std::string &word) const {
    const Word &search_word = Dictionary::getSearchWord(word);
    return search_word.getMeaning();
}

std::string Dictionary::getExample(const std::string &word, const int &pos) const {
    const Word &search_word = Dictionary::getSearchWord(word);
    return search_word.getExample(pos);
}

std::string Dictionary::getTranslation(const std::string &word, const int &pos) const {
    const Word &search_word = Dictionary::getSearchWord(word);
    return search_word.getTranslation(pos);
}

int Dictionary::getDegree(const std::string &word) const {
    const Word &search_word = Dictionary::getSearchWord(word);
    return search_word.getDegree();
}

int Dictionary::getNumOfExample(const std::string &word) const {
    const Word &search_word = Dictionary::getSearchWord(word);
    return search_word.getNumOfExample();
}

std::string Dictionary::getAllWord() const {
    std::string ret = "";
    std::set<Word>::iterator iter;
    for(iter = Dict.begin(); iter != Dict.end(); ++iter) {
        const Word &word_in_dict = *iter;
        ret = ret + word_in_dict.getWord() + ' ' + word_in_dict.getMeaning() + '\n';
    }
    return ret;
}

std::string Dictionary::getAllExample(const std::string &word) const {
    const Word &search_word = Dictionary::getSearchWord(word);
    return search_word.getAllExample();
}

Word Dictionary::getSpecificWord(const int &pos) const {
    std::set<Word>::iterator iter;
    int cnt = 0;
    for(iter = Dict.begin(); iter != Dict.end(); ++iter) {
        if(cnt == pos) {
            break;
        }
        ++cnt;
    }
    return *iter;
}
