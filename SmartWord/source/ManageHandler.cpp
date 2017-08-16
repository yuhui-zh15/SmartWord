#include "ManageHandler.h"
#include "AddHandler.h"
#include "ModifyHandler.h" 
#include "ExampleHandler.h"
#include "Word.h"
#include <iostream>
#include <cstdlib>

ManageHandler::ManageHandler(Dictionary *dict, History *hist, History *mydic): Handler(dict, hist, mydic) { } ;
ManageHandler::~ManageHandler() { } ;

void ManageHandler::CallHelper()
{
	#if defined(WIN32)|defined(_WIN32)|defined(__WIN32) 
		system("cls");
	#else
		system("clear");
	#endif
	
	std::cout << "-----Welcome To SmartWord-----" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "-------------Menu-------------" << std::endl;
	std::cout << "[1] Add word" << std::endl;
	std::cout << "[2] Modify word" << std::endl;
	std::cout << "[3] Add example" << std::endl;
	std::cout << "[Q] Return" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Please enter a command:" << std::endl;
}

void ManageHandler::MainFunction() 
{
	managehandlers[1] = new AddHandler(dict, hist, mydic);
	managehandlers[2] = new ModifyHandler(dict, hist, mydic);
	managehandlers[3] = new ExampleHandler(dict, hist, mydic);
	CallHelper();
	while (OwnFunction())
	{
		CallHelper();
	}
}
bool ManageHandler::OwnFunction()
{
	std::string input;
	std::cin >> input;
	if(input.length() == 1 && (input[0] == 'Q' || input[0] == 'q'))
	{
		return false;
	}
	if(!(input.length()==1 && (input[0]>='1' || input[0]<='3')))
	{
		std::cout << "' " << input << " ' command not found!" << std::endl ;
		std::cout << "Press enter to continue." << std::endl;
		getchar();
		getchar();
		return true;
	}  
	else
	{
		managehandlers[input[0]-'0']->MainFunction();
	}
	
	getchar();
	return true;
} 



