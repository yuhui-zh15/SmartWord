#include "ModifyHandler.h"
#include "AddHandler.h" 
#include "ExampleHandler.h"
#include "Word.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

ModifyHandler::ModifyHandler(Dictionary *dict, History *hist, History *mydic): Handler(dict, hist, mydic) { };
ModifyHandler::~ModifyHandler() { };

void ModifyHandler::CallHelper()
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
	std::cout << "--------------------" << std::endl;
	std::cout << "Please enter the word you want to modify:" << std::endl;
}

void ModifyHandler::MainFunction() 
{
	CallHelper();
	while ( OwnFunction())
	{
		CallHelper();
	}
}

bool ModifyHandler::OwnFunction()
{
    std::string input;
	std::cin >> input;
	if(input.length() == 1 && (input[0] == 'Q' || input[0] == 'q'))
	{
		return false;
	}
    if (!dict->isExisted(input))
	{
		std::cout << "The word " << input << " doesn't exist!" << std::endl;
		std::cout << "Do you want to add this word? " << std::endl;
		std::cout << "Press [Y] to add, [N] to return." << std::endl;	
		std::string input2;
		std::cin >> input2;
		if(input2.length() == 1 && (input2[0] == 'y' || input2[0] == 'Y'))
		{
			AddHandler *adh = new AddHandler(dict, hist, mydic);
			adh -> AddWord(input);
			delete adh;
		}
        return true;
    }
    else 
    {
        ModifyWord(input);
        return true;
    }
} 

void ModifyHandler::ModifyWord(std::string word)
{
    std::cout << "Current entry: " << std::endl;
    Word tmp = dict->getSearchWord(word);
	std::cerr << tmp ;
    std::cout << "Please input the new meaning for " << word << ":" << std::endl;
	std::cout << "If you don't want to change the meaning, please press [N] or [n]." << std::endl;
    std::string input;
	std::cin >> input;
	if(input=="N"||input=="n")
	{
		input = tmp.getMeaning() ;
	}
    std::cout << "Please input a degree for " << word << ":(1~5)" << std::endl;
    std::string degree;
	std::cin >> degree;
	while ( degree.length() > 1 || degree[0] > '5' || degree[0] < '1' )
    {
		std::cout << "Please input a correct degree value!(1~5)" << std::endl ;
		std::cin >> degree ;
	}    	
    dict->modifyWord( word , input , degree[0]-'0' );
	
	std::cout << "Word modified successfully!" << std::endl;
	std::cout << "Current entry:" << std::endl<< std::endl ;
	tmp = dict->getSearchWord(word);
	std::cout << tmp; 
	std::cout << "Press enter to return." << std::endl;
	getchar();
	getchar();
}
    



