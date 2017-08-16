#include "ReciteHandler.h"
#include "Recite.h"
#include <vector>
#include <string>
#include "Word.h"
#include "History.h"
#include "MyWordListHandler.h"
#include <cstdio>

ReciteHandler::ReciteHandler(Dictionary *dict, History *hist, History *mydic) : Handler(dict, hist, mydic) { }
ReciteHandler::~ReciteHandler() { }

void ReciteHandler::CallHelper()
{
#if defined(WIN32)|defined(_WIN32)|defined(__WIN32) 
	system("cls");
#else
	system("clear");
#endif

	std::cout << "-----Welcome To SmartWord-----" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "------------Recite------------" << std::endl;
	std::cout << "[M] My vocabulary list" << std::endl;
	std::cout << "[Q] Return" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Please enter the number of words you want to recite:" << std::endl;
	std::cout << std::endl;
}

void ReciteHandler::CallHelperInline()
{
#if defined(WIN32)|defined(_WIN32)|defined(__WIN32) 
	system("cls");
#else
	system("clear");
#endif

	std::cout << "-----Welcome To SmartWord-----" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "------------Recite------------" << std::endl;
	std::cout << "[1] Next" << std::endl;
	std::cout << "[2] Previous" << std::endl;
	std::cout << "[3] Add to my vocabulary list" << std::endl;
	std::cout << "[Q] Return" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Please enter a command:" << std::endl ; 
}

void ReciteHandler::MainFunction()
{
	CallHelper();
	while (OwnFunction())
	{
		CallHelper();
	}
}

bool ReciteHandler::OwnFunction()
{
	//make ReciteList
	std::string input;
	std::cin >> input;
	if (input.length() == 1 && (input[0] == 'Q' || input[0] == 'q'))
	{
		return false;
	}
	else if (input.length() == 1 && (input[0] == 'M' || input[0] == 'm'))
	{
		MyWordListHandler *mlh = new MyWordListHandler(dict, hist, mydic);
		mlh->MainFunction();
	}
	
	int num = std::atoi(input.c_str());
	if (num <= 0 || num > dict->getDictSize()) {
		std::cerr << "Please input a valid number:" << std::endl;
		return false;
	}
	Recite recite(dict, num);
	const std::vector<Word> &rec = recite.makeReciteList();
	//Recite!
	int cnt = 0;
	while (cnt < num) {
		CallHelperInline();
		Word word = rec.at(cnt);
		std::cout << word ;
		//hist->addWord(rec.at(cnt));
		std::string in;
		std::cin >> in;
		if ( in.length() == 1 )
		{
			if (in.at(0) == 'Q' || in.at(0) == 'q') {
				return true;
			}
			else if (in.at(0) == '1') {
				int tmp = word.getDegree()-1 ;
				if ( tmp < 1 ) tmp = 1 ;
				dict->setDegree(word.getWord(),tmp) ;
				cnt++;
				continue;
			}
			else if (in.at(0) == '2' && cnt != 0 ) {
				int tmp = word.getDegree()+1 ;
				if ( tmp > 5 ) tmp = 5 ;
				dict->setDegree(word.getWord(),tmp) ;
				cnt--;
				continue ;
			}
			else if (in.at(0) == '2' )
			{
				std::cout << "No previous wordfile!" << std::endl ;
			}
			else if (in.at(0) == '3') {
				if (mydic->addWordWithoutDuplicate(rec.at(cnt))) {
					dict->setDegree(word.getWord(),5 ) ;
					std::cout << "Add Success!" << std::endl;
				}
				else {
					dict->setDegree(word.getWord(),5 ) ;
					std::cout << "You have already added this word!" << std::endl;
				}
				std::cout << "Press enter to continue..." << std::endl;
				//std::cout << list.getAllWordString() << std::endl;
				cnt++;
			}
			else {
				std::cout << "' " << in << " ' command not found!" << std::endl ;
				std::cout << "Press enter to continue..." << std::endl;
			}
		}
		else
		{
			std::cout << "' " << in << " ' command not found!" << std::endl ;
			std::cout << "Press enter to continue..." << std::endl;
		}
		std::cin.get();
		std::cin.get();
	}
	return true;
}


