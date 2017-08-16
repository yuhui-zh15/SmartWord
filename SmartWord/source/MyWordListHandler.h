#ifndef MYWORDLISTHANDLER_H_
#define MYWORDLISTHANDLER_H_

#include "History.h"
#include "Handler.h"

class MyWordListHandler : public Handler
{
public:
	MyWordListHandler(Dictionary *dict, History *hist, History *mydic);
	virtual ~MyWordListHandler();
	void CallHelper();
	void MainFunction();
	bool OwnFunction();
private:

};

#endif
