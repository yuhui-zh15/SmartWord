#include "SpellTestHandler.h"
#include "SpellTest.h"
#include "Word.h"
#include "Random.h"
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstdio>

SpellTestHandler::SpellTestHandler(Dictionary *dict, History *hist, History *mydic): Handler(dict, hist, mydic) { }
SpellTestHandler::~SpellTestHandler() { }

void SpellTestHandler::CallHelper()
{
	#if defined(WIN32)|defined(_WIN32)|defined(__WIN32) 
		system("cls");
	#else
	 	system("clear");
	#endif
	
	std::cout << "-----Welcome To SmartWord-----" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "-------------Test-------------" << std::endl;
	//std::cout << std::endl;
	std::cout << "------------------------------" << std::endl;
}

void SpellTestHandler::GetExamPaper(int probnum , int choicenum) 
{
    int Right = 0 ;

	Random *ran = new Random ;
    int probcnt = 0 ;
	int *now = ran->getMultiRand(probnum,0,dict->getDictSize());
    for ( int cnt = 1 ; cnt <=probnum ; cnt++ )
    {
        CallHelper() ;
        std::cout << "Question " << cnt  << ":" << std::endl ;
        std::cout << std::endl ;
        int random = now[cnt-1];
        SpellTest *spt = new SpellTest(dict,random) ;
        std::cout << spt->getTest() ;
        std::cout << "Your answer:(Press [Q] to return):" << std::endl ;
        std::string userchoice ;
        std::cin >> userchoice ;
        if ( userchoice.length() == 1 && (userchoice[0] == 'Q'|| userchoice[0]=='q'))
        {
            delete spt ;
            break ;
        }
        probcnt++ ;
        if ( spt->isCorrect(userchoice) ) 
        {
            dict->setDegree(spt->getAnswer(),(dict->getSearchWord(spt->getAnswer())).getDegree()-1) ;
            Right++ ;
            std::cout << "Right!" << std::endl ;
        }
        else 
        {            
           std::string tmp = spt->getAnswer() ; 
           dict->setDegree(tmp,(dict->getSearchWord(tmp)).getDegree()+1) ;
           std::cout << "Wrong!" << std::endl  << spt->getTestAns() <<std::endl ;
        } ;
        getchar() ;
        getchar() ;  
        delete spt ;
    }
	delete ran ;
	delete[] now;

    std::cout << "You got " << Right << " out of " << probcnt << " !" << std::endl ;
    getchar() ;
    getchar() ;
}


void SpellTestHandler::MainFunction()
{
   int probnum = 0 ;
   std::cout << std::endl <<  "Please enter the number of questions:"  << std::endl ;
   std::cin >> probnum ;
   GetExamPaper(probnum , 1) ;
} 

bool SpellTestHandler::OwnFunction() { return true; };
    



