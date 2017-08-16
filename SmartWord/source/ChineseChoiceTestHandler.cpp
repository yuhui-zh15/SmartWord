#include "ChineseChoiceTestHandler.h"
#include "ChineseTest.h"
#include "Word.h"
#include "Random.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

ChineseChoiceTestHandler::ChineseChoiceTestHandler(Dictionary *dict, History *hist, History *mydic): Handler(dict, hist, mydic) { }
ChineseChoiceTestHandler::~ChineseChoiceTestHandler() { }

void ChineseChoiceTestHandler::CallHelper()
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

void ChineseChoiceTestHandler::GetExamPaper(int probnum , int choicenum) 
{
    int Right = 0 ;
	Random *ran = new Random();
	int *now = ran->getMultiRand(probnum,0,dict->getDictSize());
    int probcnt = 0 ;
    for ( int cnt = 1 ; cnt <=probnum ; cnt++ )
    {
        CallHelper() ;
        std::cout << "Question " << cnt  << ":" << std::endl ;
        std::cout << std::endl ;
        ChineseTest *cht = new ChineseTest(dict,choicenum,now[cnt-1]) ;
        std::cout << cht->getTest() << std::endl;
        std::cout << "Your answer:(Press [Q] to return)" << std::endl ;
        std::string userchoice ;
        std::cin >> userchoice ;
        if ( userchoice.length() == 1 && (userchoice[0] == 'Q'|| userchoice[0]=='q'))
        {
            delete cht ;
            break ;
        }
        probcnt++ ;
        std::string ans = cht->getChoice(cht->getAnswerChoice()) ;
        if (cht -> isCorrect(userchoice)) 
        {
           dict->setDegree(ans,(dict->getSearchWord(ans)).getDegree()-1) ;
            Right++ ;
            std::cout << "Right!" << std::endl ;
        }
        else 
        {
            dict->setDegree(ans,(dict->getSearchWord(ans)).getDegree()+1) ;
            std::cout << "Wrong!" << std::endl << cht->getTestAns() << std::endl ;
        };
        getchar() ;
        getchar() ;  
        delete cht ;   
    }
	delete ran ;
	delete[] now;
    std::cout << "You got " << Right << " out of " << probcnt << " !" << std::endl ;
    getchar() ;
    getchar() ;
}

void ChineseChoiceTestHandler::MainFunction()
{
   int choicenum = 0 ;
   int probnum = 0 ;
   std::cout << std::endl << "Please type in the number of questions:" << std::endl ;
   std::cin >> probnum ;
   std::cout << std::endl << "Please type in the number of choices in each question:" << std::endl ;
   std::cin >> choicenum ;
   GetExamPaper(probnum , choicenum) ;
} 

bool ChineseChoiceTestHandler::OwnFunction() { return true; }
    



