#include "ExampleHandler.h"
#include "AddHandler.h"
#include "Word.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

ExampleHandler::ExampleHandler(Dictionary *dict, History *hist, History *mydic): Handler(dict, hist, mydic) { }
ExampleHandler::~ExampleHandler() { }

void ExampleHandler::CallHelper()
{
	#if defined(WIN32)|defined(_WIN32)|defined(__WIN32) 
		system("cls");
	#else
	 	system("clear");
	#endif
	
	std::cout << "-----Welcome To SmartWord-----" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "-------------Menu-------------" << std::endl;
	std::cout << "[Q] Return" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Please enter the word you want to add an example to:" << std::endl;
}

void ExampleHandler::MainFunction() 
{
	CallHelper() ;
	while ( OwnFunction())
	{
		CallHelper() ;
	}
}

bool ExampleHandler::OwnFunction()
{
    std::string input;
	std::cin >> input;
	if(input.length() == 1 && (input[0] == 'Q' || input[0] == 'q'))
	{
		return false ;
	}
    if (!dict->isExisted(input))
	{
		std::cout << "The word " << input << " doesn't exist!" << std::endl ;
		std::cout << "Do you want to add this word? " << std::endl ;
		std::cout << "Press [Y] to add, [N] to return." << std::endl ;	
		std::string input2;
		std::cin >> input2;
		if(input2.length() == 1 && (input2[0] == 'y' || input2[0] == 'Y'))
		{
			AddHandler *adh = new AddHandler(dict, hist, mydic) ;
			adh -> AddWord(input) ;
			delete adh ;
		}
        return true ;
    }
    else 
    {
       	std::cout << "Current word:" << std::endl ;
		Word tmp = dict->getSearchWord(input) ;
		std::cout << tmp << std::endl;
        std::cout << "Please enter its new example:" << std::endl ;
        std::string NewExample ;
        getchar() ;
        std::getline( std::cin , NewExample );
        std::cout << "Please enter its translation:" << std::endl ;
        std::string Translation ;
        std::getline( std::cin , Translation );
        dict->addExample(input,NewExample,Translation) ;
        std::cout << "Add Success!" << std::endl ;
        std::cout << "Press enter to continue." << std::endl ;
        getchar() ;
        return true ;
      }
} 

    
    



