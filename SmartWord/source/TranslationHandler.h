#ifndef TRANSLATIONHANDLER_H_
#define TRANSLATIONHANDLER_H_

#include "Handler.h"

class TranslationHandler : public Handler
{
public:
	TranslationHandler(Dictionary *dict, History *hist, History *mydic);
	~TranslationHandler();
	void CallHelper();
	void MainFunction();
	bool OwnFunction();
private:

};




#endif // ! TRANSLATIONHANDLER_H_
