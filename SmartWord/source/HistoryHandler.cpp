#include "HistoryHandler.h"
#include "Word.h"
#include <iostream>
#include <cstdlib>

HistoryHandler::HistoryHandler(Dictionary * dict, History * hist, History * mydic): Handler(dict, hist, mydic) { }
HistoryHandler::~HistoryHandler() { }

void HistoryHandler::CallHelper()
{
#if defined(WIN32)|defined(_WIN32)|defined(__WIN32) 
	system("cls");
#else
	system("clear");
#endif

	std::cout << "-----Welcome To SmartWord-----" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "---------History Menu---------" << std::endl;
	std::cout << "[1] Show History" << std::endl;
	std::cout << "[2] Delete history" << std::endl;
	std::cout << "[3] Delete all history" << std::endl;
	std::cout << "[Q] Return" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Please enter a command:" << std::endl ;
}

void HistoryHandler::MainFunction()
{
	CallHelper();
	while (OwnFunction())
	{
		CallHelper();
	}
}

bool HistoryHandler::OwnFunction()
{
	std::string input;
	std::cin >> input;
	if (input.length() == 1 && (input.at(0) == 'Q' || input.at(0) == 'q'))
	{
		return false;
	}
	else if (input.length() == 1 && input.at(0) == '1')
	{
		std::cout << hist->getAllWordString() << std::endl;
	//	hist->exportHistory(username + "_history.txt");		
	}
	else if (input.length() == 1 && input.at(0) == '2') 
	{
		std::cout << hist->getAllWordString() << std::endl;
		std::cout << "Please enter the number of the word you want to delete:" << std::endl;
		int num;
		std::cin >> num;
		if (hist->deleteWord(num)) 
		{
		//	hist->exportHistory(username + "_history.txt");
			std::cout << "Delete Success!" << std::endl;
		}
		else
		{
			std::cout << "Delete Failed! Please input correct index number" << std::endl;
		}
	}
	else if (input.length() == 1 && input.at(0) == '3')
	{
		if (hist->deleteAllWord())
		{
		//	hist->exportHistory(username + "_history.txt");
			std::cout << "Delete Success!" << std::endl;
		}
		else
		{
			std::cout << "Delete Failed!" << std::endl;
		}
	}
	std::cout << "Press enter to continue..." << std::endl;
	std::cin.get();
	std::cin.get();

	return true;
}


