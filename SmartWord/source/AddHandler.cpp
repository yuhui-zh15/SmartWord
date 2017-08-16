#include "AddHandler.h"
#include "ModifyHandler.h"
#include "Word.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

AddHandler::AddHandler(Dictionary *dict, History *hist, History *mydic): Handler(dict, hist, mydic) { }
AddHandler::~AddHandler() { }

void AddHandler::CallHelper()
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
	std::cout << "Please enter the word you want to add:" << std::endl;
}

void AddHandler::MainFunction() 
{
	CallHelper() ;
	while (OwnFunction())
	{
		CallHelper();
	}
}

bool AddHandler::OwnFunction()
{
    std::string input;
	std::cin >> input;
	if(input.length() == 1 && (input[0] == 'Q' || input[0] == 'q'))
	{
		return false ;
	}
    if (dict->isExisted(input))
	{
		std::cout << "The word already exists:" << std::endl ;
		Word tmp = dict->getSearchWord(input) ;
		std::cerr << tmp ;
		std::cout << "Do you want to modify this entry? " << std::endl ;
		std::cout << "Press [Y] to modify, [N] to return." << std::endl ;	
		std::string input2;
		std::cin >> input2;
		if(input2.length() == 1 && (input2[0] == 'y' || input2[0] == 'Y'))
		{
			ModifyHandler *mdh = new ModifyHandler(dict, hist, mydic);
			mdh -> ModifyWord(input);
			delete mdh ;
		}
        return true ;
    }
    else 
    {
        AddWord(input) ;
        return true ;
    }
} 

void AddHandler::AddWord(const std::string &word)
{
    std::cout << "Please input the meaning for " << word << ":" << std::endl ;
    std::string meaning;
	getchar() ;
	getline(std::cin,meaning) ;
    std::cout << "Please input the degree for " << word << ":(1~5)" << std::endl ;
    std::string degree;
	std::cin >> degree ;
	while ( degree.length() > 1 || degree[0] > '5' || degree[0] < '1' )
    {
		std::cout << "Please input a correct degree value!(1~5)" << std::endl ;
		std::cin >> degree ;
	}    	
	dict->addWord( word , meaning , degree[0]-'0' ) ;
	std::cout << std::endl ;
	
	std::cout << "Word added successfully!" << std::endl ;
	std::cout << "Current entry:" << std::endl ;
	Word tmp = dict->getSearchWord(word) ;
	std::cout << tmp ; 
	std::cout << std::endl ;
	std::cout << "Press enter to return." << std::endl ;
	getchar() ;
	getchar() ;
}
    
    



