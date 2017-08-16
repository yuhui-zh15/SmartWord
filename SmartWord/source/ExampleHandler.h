#ifndef EXAMPLEHANDLER_H_
#define EXAMPLEHANDLER_H_

#include "Dictionary.h"
#include "Handler.h"

class ExampleHandler : public Handler 
{
public:
	ExampleHandler(Dictionary *dict, History *hist, History *mydic);
	~ExampleHandler();
	void CallHelper() ;	
	void MainFunction() ;
    bool OwnFunction();
private:

};

#endif