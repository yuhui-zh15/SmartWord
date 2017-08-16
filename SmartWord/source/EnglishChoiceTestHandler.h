#ifndef ENGLISHCHOICETESTHANDLER_H_
#define ENGLISHCHOICETESTHANDLER_H_

#include "Handler.h"

class EnglishChoiceTestHandler : public Handler 
{
public:
	EnglishChoiceTestHandler(Dictionary *dict, History *hist, History *mydic);
	~EnglishChoiceTestHandler();
	void CallHelper();	
	void GetExamPaper(int probnum , int choicenum );
    void MainFunction();
	bool OwnFunction();
private:

};

#endif