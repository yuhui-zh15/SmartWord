#ifndef HANDLER_H_
#define HANDLER_H_

#include "Dictionary.h"
#include "History.h"

class Handler
{
public:
	Handler(Dictionary *dict, History *hist, History *mydic);
    virtual ~Handler();
    virtual void CallHelper() = 0;
    virtual void MainFunction() = 0;
    virtual bool OwnFunction() = 0;
protected:
	Dictionary *dict;
	History *hist;
	History *mydic;
};

#endif