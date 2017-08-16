#include "Handler.h" 
#include "Dictionary.h"

Handler::Handler(Dictionary * dict, History * hist, History * mydic) : dict(dict), hist(hist), mydic(mydic) {}

Handler::~Handler() {}

void Handler::CallHelper() {}

void Handler::MainFunction() {}

bool Handler::OwnFunction() { return true; }