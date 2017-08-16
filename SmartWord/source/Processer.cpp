#include "Processer.h" 
#include "SearchHandler.h"
#include "ManageHandler.h"
#include "TestHandler.h"
#include "ReciteHandler.h"
#include "HistoryHandler.h"
#include "MyWordListHandler.h"
#include "TranslationHandler.h"
#include "History.h"
#include <iostream>
#include <cstdlib>

Processer::Processer(const std::string & username): username(username)
{
	std::string fullname = "" ;
#if defined(WIN32)|defined(_WIN32)|defined(__WIN32)
	fullname = "../lib/GBK_" + username ;
#else
	fullname = "../lib/UTF8_" + username ;
#endif
	dict = new Dictionary();
	hist = new History();
	mydic = new History();
	dict->importDict(fullname + "_dict.txt");
	dict->importExample(fullname + "_example.txt");
	hist->importHistory(fullname + "_history.txt");
	mydic->importHistory(fullname + "_mydic.txt");
	handlers[0] = NULL;
	handlers[1] = new SearchHandler(dict, hist, mydic);
	handlers[2] = new ReciteHandler(dict, hist, mydic);
	handlers[3] = new TestHandler(dict, hist, mydic);
	handlers[4] = new ManageHandler(dict, hist, mydic);
	handlers[5] = new HistoryHandler(dict, hist, mydic);
	handlers[6] = new MyWordListHandler(dict, hist, mydic);
	handlers[7] = new TranslationHandler(dict, hist, mydic);
}

Processer::~Processer()
{
	
}



void Processer::CallHelper()
{
#if defined(WIN32)|defined(_WIN32)|defined(__WIN32)
	system("cls");
#else
	system("clear");
#endif
	std::cout << "-----Welcome To SmartWord-----" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "----------Main Menu-----------" << std::endl;
	std::cout << "[1] Search" << std::endl;
	std::cout << "[2] Recite" << std::endl;
	std::cout << "[3] Test" << std::endl;
	std::cout << "[4] Edit" << std::endl;
	std::cout << "[5] History" << std::endl;
	std::cout << "[6] My Word List" << std::endl;
	std::cout << "[7] Translation" << std::endl;
	std::cout << "[Q] Quit" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Please enter a command:" << std::endl ;
}

void Processer::GotoHandler()
{
	CallHelper();
	std::string Dictname = "" ;
	std::string Examplename = "" ;
	
#if defined(WIN32)|defined(_WIN32)|defined(__WIN32)
	Dictname = "../lib/GBK_dict.txt" ;
	Examplename = "../lib/GBK_example.txt" ;
#else
	Dictname = "../lib/UTF8_dict.txt" ;
	Examplename = "../lib/UTF8_example.txt" ;
#endif 
	
	
	if(! dict->importDict(Dictname))
	{
		std::cout << "Dict can't open!" << std::endl;
		getchar();
		//return;
	}
	if(! dict->importExample(Examplename))
	{
		std::cout << "Example can't open!" << std::endl;
		
		//return;
	}
	
	while(true)
	{
		CallHelper(); 
		std::string choice;
		
		std::cin >> choice;
		if ( choice.length() == 1 )
		{
			if (choice[0] == 'q' || choice[0] =='Q' ) 
			{
				std::string fullname = "" ;
				#if defined(WIN32)|defined(_WIN32)|defined(__WIN32)
					fullname = "../lib/GBK_" + username ;
				#else
					fullname = "../lib/UTF8_" + username ;	
				#endif
				dict->exportDict(fullname + "_dict.txt");
				dict->exportExample(fullname + "_example.txt");
				hist->exportHistory(fullname + "_history.txt");
				mydic->exportHistory(fullname + "_mydic.txt");
				break;
			}
			else if ( choice[0] >= '1' && choice[0] <= '7' )
			{
				handlers[choice[0] - '0']->MainFunction();
			}	
			else
			{
				std::cout << "' " << choice << " ' command not found!" << std::endl ;
				std::cout<<"Press enter to continue."<<std::endl;
				getchar() ;
				getchar() ;
			}
		}
		else
		{
			std::cout << "' " << choice << " ' command not found!" << std::endl ;
			std::cout<<"Press enter to continue."<<std::endl;
			getchar() ;
			getchar() ;
		}
	}
}


