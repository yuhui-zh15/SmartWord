#include "TranslationHandler.h"
#include "Translation.h"
#include <cstdio>

TranslationHandler::TranslationHandler(Dictionary *dict, History *hist, History *mydic): Handler(dict, hist, mydic) { }
TranslationHandler::~TranslationHandler() { }

void TranslationHandler::CallHelper()
{
#if defined(WIN32)|defined(_WIN32)|defined(__WIN32) 
	system("cls");
#else
	system("clear");
#endif

	std::cout << "-----Welcome To SmartWord-----" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "-------Translation Menu-------" << std::endl;
	std::cout << "[1] Translate from text" << std::endl;
	std::cout << "[2] Translate from file" << std::endl;
	std::cout << "[Q] Return" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Please choose the way to read your test:" <<std::endl ;
	std::cout << std::endl;
}

void TranslationHandler::MainFunction()
{
	CallHelper();
	while (OwnFunction())
	{
		CallHelper();
	}
}
bool TranslationHandler::OwnFunction()
{
	std::string input;
	std::cin >> input;
	if (input.length() == 1 && (input.at(0) == 'Q' || input.at(0) == 'q'))
	{
		return false;
	}
	else if(input.length() == 1 && input.at(0) == '1')
	{
		std::cout << "Please enter the text:" << std::endl;
		Translation trs(dict);
		std::string trans;
		getchar();
		getline(std::cin, trans);
		trs.setRawString(trans);
		std::cout << trs.getOutString() << std::endl;
	}
	else if (input.length() == 1 && input.at(0) == '2')
	{
		std::cout << "Please enter the filename:" << std::endl;
		Translation trs(dict);
		std::string filename;
		std::cin >> filename;
		trs.importFile(filename);
		std::cout << trs.getOutString() << std::endl;
	}
	else
	{
		std::cout << "' " << input << " ' command not found!" << std::endl ;
	}
	getchar();
	std::cout << "Press enter to continue..." << std::endl;
	getchar();
	return true;
}


