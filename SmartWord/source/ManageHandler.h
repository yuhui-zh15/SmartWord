#ifndef MANAGEHANDLER_H_
#define MANAGEHANDLER_H_

#include "Dictionary.h"
#include "Handler.h"

class ManageHandler : public Handler 
{
public:
	ManageHandler(Dictionary *dict, History *hist, History *mydic);
	~ManageHandler();
	void CallHelper() ;	
	void MainFunction() ;
	bool OwnFunction() ;
private:
	Handler *managehandlers[10] ;
};

#endif