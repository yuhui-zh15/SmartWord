#ifndef SPELLTESTHANDLER_H_
#define SPELLTESTHANDLER_H_

#include "Handler.h"

class SpellTestHandler : public Handler 
{
public:
	SpellTestHandler(Dictionary *dict, History *hist, History *mydic);
	~SpellTestHandler();
	void CallHelper();	
	void GetExamPaper(int probnum , int choicenum);
    void MainFunction();
	bool OwnFunction();
private:

};

#endif