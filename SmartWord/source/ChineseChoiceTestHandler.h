#ifndef ChineseChoiceTestHandler_H_
#define ChineseChoiceTestHandler_H_

#include "Handler.h"

class ChineseChoiceTestHandler : public Handler
{
public:
	ChineseChoiceTestHandler(Dictionary * dict, History * hist, History * mydic);
	~ChineseChoiceTestHandler();
	void CallHelper();	
	void GetExamPaper(int probnum , int choicenum);
    void MainFunction();
	bool OwnFunction();
private:

};

#endif