#ifndef TESTHANDLER_H_
#define TESTHANDLER_H_

#include "Handler.h"

class TestHandler : public Handler 
{
public:
	TestHandler(Dictionary *dict, History *hist, History *mydic);
	~TestHandler();
	void CallHelper();	
	void MainFunction();
	bool OwnFunction();
private:
    Handler *testtype[10]; 
};

#endif