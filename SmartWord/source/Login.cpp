#include "Login.h"
#include <iostream>
#include "Processer.h"

Login::Login()
{

}

Login::~Login()
{

}

void Login::CallHelper()
{
#if defined(WIN32)|defined(_WIN32)|defined(__WIN32) 
	system("cls");
#else
	system("clear");
#endif
	std::cout << "Welcome To SmartWord" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "--------Login-------" << std::endl;
	std::cout << "[Q] Quit" << std::endl;
	std::cout << "--------------------" << std::endl;
}

void Login::GotoProcessor()
{
	CallHelper();
	std::cout << "Please input your name:" << std::endl;
	getline(std::cin , user_name_);
	if (user_name_.length() == 1 && (user_name_.at(0) == 'Q' || user_name_.at(0) == 'q')) {
		return;
	}
	Processer *pro = new Processer(user_name_);
	pro->GotoHandler();
	delete pro;
}

