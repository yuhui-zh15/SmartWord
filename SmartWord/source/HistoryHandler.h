#ifndef HISTORYHANDLER_H_
#define HISTORYHANDLER_H_

#include "Handler.h"
#include "History.h"

class HistoryHandler: public Handler
{
public:
	HistoryHandler(Dictionary *dict, History *hist, History *mydic);
	~HistoryHandler();
	void CallHelper();
	void MainFunction();
	bool OwnFunction();
private:

};

#endif