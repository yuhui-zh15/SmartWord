#ifndef ADDHANDLER_H_
#define ADDHANDLER_H_

#include "Handler.h"

class AddHandler : public Handler 
{
public:
	AddHandler(Dictionary *dict, History *hist, History *mydic);
	~AddHandler();
	void CallHelper();	
	void MainFunction();
    bool OwnFunction();
	void AddWord(const std::string &word);
private:

};

#endif






