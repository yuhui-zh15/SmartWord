#ifndef SEARCHHANDLER_H_
#define SEARCHHANDLER_H_

#include "Handler.h"

class SearchHandler : public Handler 
{
public:
	SearchHandler(Dictionary *dict, History *hist, History *mydic);
	~SearchHandler();
	void CallHelper();	
	void MainFunction();
	bool OwnFunction();
private:

};

#endif