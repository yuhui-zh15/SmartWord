#include "SearchHandler.h"
#include "AddHandler.h"
#include "HistoryHandler.h"
#include "Word.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

SearchHandler::SearchHandler(Dictionary *dict, History *hist, History *mydic): Handler(dict, hist, mydic) { }
SearchHandler::~SearchHandler() { }

void SearchHandler::CallHelper()
{
	#if defined(WIN32)|defined(_WIN32)|defined(__WIN32) 
		system("cls");
	#else
		system("clear");
	#endif
	
	std::cout << "-----Welcome To SmartWord-----" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "-------------Search-----------" << std::endl;
	std::cout << "[1] History" << std::endl;
	std::cout << "[Q] Return" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Please input the word to search:" << std::endl;
	std::cout << std::endl ;
}

void SearchHandler::MainFunction() 
{
	CallHelper() ;
	while (OwnFunction())
	{
		CallHelper() ;
	}
}
bool SearchHandler::OwnFunction()
{
		std::string input;
		std::cin >> input;
		if(input.length() == 1 && (input.at(0) == 'Q' || input.at(0) == 'q'))
		{
			return false;
		}
		else if(input.length() == 1 && input.at(0) == '1')
		{
			HistoryHandler *hld = new HistoryHandler(dict, hist, mydic);
			hld->MainFunction();
			delete hld;
		}
		else {


			if (dict->isExisted(input))
			{
				Word searched = dict->getSearchWord(input) ;
				std::cout << searched ;
				std::cout << std::endl ;
				std::cout << "Press enter to continue." << std::endl;
				hist->addWordWithoutDuplicate(searched);
				getchar();
				getchar();
			}
			else 
			{
				std::cerr << "Can not find the word!" << std::endl;
				std::cout << std::endl ;
				std::cout << "Do you want to add this word? " << std::endl ;
				std::cout << "Press [Y] to add, [N] to return." << std::endl ;	
				std::string input2;
				std::cin >> input2;
				if(input2.length() == 1 && (input2[0] == 'y' || input2[0] == 'Y'))
				{
					AddHandler *adh = new AddHandler(dict, hist, mydic);
					adh -> AddWord(input) ;
					delete adh ;
				}
	        	return true ;
	        }
		}
		return true ;
} 


