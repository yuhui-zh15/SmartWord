#ifndef RECITEHANDLER_H_
#define RECITEHANDLER_H_

#include "Handler.h"
#include "Recite.h"
#include "History.h"

class ReciteHandler : public Handler
{
public:
	ReciteHandler(Dictionary *dict, History *hist, History *mydic);
	virtual ~ReciteHandler();
	void CallHelper();
	void CallHelperInline();
	void MainFunction();
	bool OwnFunction();
private:
};



#endif // !RECITEHANDLER_H_
