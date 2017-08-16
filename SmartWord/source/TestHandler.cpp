#include "TestHandler.h"
#include "ChineseChoiceTestHandler.h"
#include "EnglishChoiceTestHandler.h"
#include "SpellTestHandler.h"
#include "Word.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

TestHandler::TestHandler(Dictionary *dict, History *hist, History *mydic): Handler(dict, hist, mydic)
{
	testtype[0] = NULL;
	testtype[1] = new EnglishChoiceTestHandler(dict, hist, mydic);
	testtype[2] = new ChineseChoiceTestHandler(dict, hist, mydic);
	testtype[3] = new SpellTestHandler(dict, hist, mydic);
}
TestHandler::~TestHandler() { }

void TestHandler::CallHelper()
{
	#if defined(WIN32)|defined(_WIN32)|defined(__WIN32) 
	 	system("cls");
	#else
		system("clear");
	#endif
	
	std::cout << "-----Welcome To SmartWord-----" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "----------Test Menu-----------" << std::endl;
	std::cout << "[1] English To Chinese" << std::endl;
	std::cout << "[2] Chinese To English" << std::endl;
	std::cout << "[3] Spelling" << std::endl;
	std::cout << "[Q] Return" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Please choose which type of test to take:" << std::endl ;
}


void TestHandler::MainFunction() 
{
	CallHelper() ;
	while (OwnFunction())
	{
		CallHelper() ;
	}
}
bool TestHandler::OwnFunction()
{
	std::string input;
	std::cin >> input;
	if(input.length() == 1 && (input[0] == 'Q' || input[0] == 'q'))
	{
		return false ;
	}
	if(!(input.length()==1 && (input[0]>='1' && input[0] <= '3')))
	{
		std::cout << "' " << input << " ' command not found!" << std::endl ;
		std::cout << "Press enter to continue." << std::endl;
		getchar() ;
		getchar() ;
		return true ;
	}  
    else
    {
        testtype[input[0]-'0'] -> MainFunction() ;
    }

	return true ;
} 



