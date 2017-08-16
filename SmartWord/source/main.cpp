#include <iostream>
#include <cstdio>
#include <string>
#include "Login.h"
using namespace std;

int main(int argc, char** argv)
{
	Login *lg = new Login();
	lg->GotoProcessor();
	delete lg;
	return 0;
}