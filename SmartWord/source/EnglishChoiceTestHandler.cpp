#include "EnglishChoiceTestHandler.h"
#include "EnglishTest.h"
#include "Word.h"
#include "Random.h" 
#include <iostream>
#include <cstdlib>
#include <cstdio>

EnglishChoiceTestHandler::EnglishChoiceTestHandler(Dictionary *dict, History *hist, History *mydic): Handler(dict, hist, mydic) { }
EnglishChoiceTestHandler::~EnglishChoiceTestHandler() { }

void EnglishChoiceTestHandler::CallHelper()
{
	#if defined(WIN32)|defined(_WIN32)|defined(__WIN32) 
		system("cls");
	#else
	 	system("clear");
	#endif
	
	std::cout << "-----Welcome To SmartWord-----" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "-------------Test-------------" << std::endl;
	std::cout << "------------------------------" << std::endl;
}

void EnglishChoiceTestHandler::GetExamPaper(int probnum , int choicenum) 
{
    int Right = 0 ;
	Random *ran = new Random;
	int *now = ran->getMultiRand(probnum, 0, dict->getDictSize());
    int probcnt = 0 ;
    for ( int cnt = 1 ; cnt <=probnum ; cnt++ )
    {
        CallHelper() ;
        std::cout << "Question " << cnt  << ":" << std::endl ;
        std::cout << std::endl ;
        EnglishTest *ent = new EnglishTest(dict,choicenum,now[cnt-1]) ;
        std::cout << ent->getTest() << std::endl;
        std::cout << "Your answer:(Press [Q] to return)" << std::endl ;
        std::string userchoice ;
        std::cin >> userchoice ;
        if ( userchoice.length() == 1 && (userchoice[0] == 'Q'|| userchoice[0]=='q'))
        {
            delete ent ;
            break ;
        }
        probcnt++ ;
        std::string ans = ent->getAnswerMeaning() ;
        if (ent -> isCorrect(userchoice)) 
        {
            dict->setDegree(ans,(dict->getSearchWord(ans)).getDegree()-1) ;
            Right++ ;
            std::cout << "Right!" << std::endl ;
        }
        else 
        {
            dict->setDegree(ans,(dict->getSearchWord(ans)).getDegree()+1) ;
            std::cout << "Wrong!" << std::endl << ent->getTestAns() << std::endl ;
        };    
        getchar() ;
        getchar() ;  
        delete ent ;  
         
    }
	delete ran ;
	delete[] now;
    std::cout << "You got " << Right << " out of " << probcnt << " !" << std::endl ;
    getchar() ;
    getchar() ;
}


void EnglishChoiceTestHandler::MainFunction()
{
   int choicenum = 0 ;
   int probnum = 0 ;
   std::cout << std::endl <<  "Please type in the number of questions:"  << std::endl ;
   std::cin >> probnum ;
   std::cout << std::endl <<  "Please type in the number of choices in each question:"  << std::endl ;
   std::cin >> choicenum ;
   GetExamPaper(probnum , choicenum) ;
} 

bool EnglishChoiceTestHandler::OwnFunction() { return true; };
    



