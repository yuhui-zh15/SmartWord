#ifndef PROCESSER_H_
#define PROCESSER_H_

#include <string>
#include "Handler.h"
#include "Dictionary.h"
#include "History.h"

class Processer
{
private:
    Handler *handlers[10];
    Dictionary *dict;    
	History *hist;
	History *mydic;
	std::string username;
public:
    Processer(const std::string &username);
    ~Processer();
    void CallHelper();
	void GotoHandler();
};

#endif
