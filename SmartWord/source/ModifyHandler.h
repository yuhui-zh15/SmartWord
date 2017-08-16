#ifndef MODIFYHANDLER_H_
#define MODIFYHANDLER_H_

#include "Dictionary.h"
#include "Handler.h"

class ModifyHandler : public Handler 
{
public:
	ModifyHandler(Dictionary *dict, History *hist, History *mydic);
	~ModifyHandler();
	void CallHelper() ;	
	void MainFunction() ;
    bool OwnFunction() ;
	void ModifyWord(std::string word) ;
private:

};

#endif