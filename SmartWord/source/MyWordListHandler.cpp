#include "MyWordListHandler.h"
#include <string>
#include <iostream>
#include <cstdio>

MyWordListHandler::MyWordListHandler(Dictionary *dict, History *hist, History *mydic): Handler(dict, hist , mydic) { }

MyWordListHandler::~MyWordListHandler() { }

void MyWordListHandler::CallHelper()
{
#if defined(WIN32)|defined(_WIN32)|defined(__WIN32) 
	system("cls");
#else
	system("clear");
#endif

	std::cout << "-----Welcome To SmartWord-----" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "----Word List Command Menu----" << std::endl;
	std::cout << "[1] Show my word list" << std::endl;
	std::cout << "[2] Delete words from my word list" << std::endl;
	std::cout << "[3] Delete all words from my word list" << std::endl;
	std::cout << "[Q] Return" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Please enter a command:" << std::endl ;
	std::cout << std::endl;
}

void MyWordListHandler::MainFunction()
{
	CallHelper();
	while (OwnFunction())
	{
		CallHelper();
	}
}

bool MyWordListHandler::OwnFunction()
{
	std::string input;
	std::cin >> input;
	if (input.at(0) == 'Q' || input.at(0) == 'q') {
		return false;
	}
	else if (input.at(0) == '1') {
		std::cout << mydic->getAllWordString() << std::endl;
	//	mydic->exportHistory(username + "_mydic.txt");
	}
	else if (input.at(0) == '2') {
		std::cout << "Please enter the number of the word you want to delete..." << std::endl;
		std::cout << mydic->getAllWordString() << std::endl;
		int index;
		std::cin >> index;
		if (mydic->deleteWord(index-1)) {
			std::cout << "Delete Success!" << std::endl;
		//	mydic->exportHistory(username + "_mydic.txt");
		}
		else {
			std::cout << "Please enter a correct number!" << std::endl;
		}	
	}
	else if (input.at(0) == '3') {
		if (mydic->deleteAllWord()) {
			std::cout << "Delete Success!" << std::endl;
		//	mydic->exportHistory(username + "_mydic.txt");
		}
		else {
			std::cout << "Error!" << std::endl;
		}
	}
	std::cout << "Press enter to contine..." << std::endl;
	std::cin.get();
	std::cin.get();
	return true;
}
