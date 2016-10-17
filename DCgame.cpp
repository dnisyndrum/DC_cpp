//-----------------------------------------------------------------------------
//   File: Dueling Club
//   Class: DCgame
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//   Title: Dueling Club
//   Description: 
//   Programmer: Andrew Sales
//   
//     Properties:
//       
//     Methods:
//       
//        properties:
//         
//        Public Methods:
//           
//        Private Properties:
//            
//-----------------------------------------------------------------------------
#include "DCplayer.h"
#include "DCmusic.h"
#include "DCdisplay.h"
#include "DCspells.h"
#include "DCtimer.h"
#include "DCwager.h"
#include "DCgame.h"
#include <chrono>
#include <ctime>
#include <time.h>  
#include<conio.h>
using namespace std;

DCgame::DCgame()
{
	displayPtr = new DCdisplay();
	timerPtr = new DCtimer();
	wagerPtr = new DCwager();
	game();							
}

void DCgame::intro()
{
	displayPtr->displayNext(DCdisplay::displayOutput::titles1);
	timerPtr->timerWithoutCount(3);
	displayPtr->displayNext(DCdisplay::displayOutput::titles2);
	timerPtr->timerWithoutCount(3);
	displayPtr->displayNext(DCdisplay::displayOutput::fullScreen);
	cin.get();
	displayPtr->displayNext(DCdisplay::displayOutput::clear);
	displayPtr->displayNext(DCdisplay::displayOutput::intro1);
	cin.get();
	displayPtr->displayNext(DCdisplay::displayOutput::intro2);
	cin.get();
	displayPtr->displayNext(DCdisplay::displayOutput::clear);
}

void DCgame::readyToDuel()
{
	displayPtr->displayNext(DCdisplay::displayOutput::clear);
	displayPtr->displayNext(DCdisplay::displayOutput::readyToDuel);
	timerPtr->timerWithoutCount(1);
	displayPtr->displayNext(DCdisplay::displayOutput::count1);
	timerPtr->timerWithoutCount(1);
	displayPtr->displayNext(DCdisplay::displayOutput::count2);
	timerPtr->timerWithoutCount(1);
	displayPtr->displayNext(DCdisplay::displayOutput::count3);
	timerPtr->timerWithoutCount(1);
	displayPtr->displayNext(DCdisplay::displayOutput::count4);
	timerPtr->timerWithoutCount(1);
	displayPtr->displayNext(DCdisplay::displayOutput::clear);
}

void DCgame::setup()
{
	bool goodToGo = false;
	char keyPress;
	//display -> ask user for pvp or pvai game
	displayPtr->displayNext(DCdisplay::displayOutput::PvPorAI);
	//loop until acceptable response
	while(!goodToGo)
	{
		keyPress = getch();
		keyPress = toupper(keyPress);
		switch (keyPress)
		{
		case 'P':
			displayPtr->displayNext(DCdisplay::displayOutput::clear);
			player1 = new DCplayer(false);
			player2 = new DCplayer(false);
			goodToGo = true;
			break;
		case 'C':
			displayPtr->displayNext(DCdisplay::displayOutput::clear);
			player1 = new DCplayer(false);
			player2 = new DCplayer(true);
			goodToGo = true;
			break;
		case 'T':
			displayPtr->displayNext(DCdisplay::displayOutput::clear);
			player1 = new DCplayer(true);
			player2 = new DCplayer(true);
			goodToGo = true;
			break;
		}
	}
}

void DCgame::duel()
{
	bool exitDuel = false;
	static bool player1NextTurn = true;
	static bool player2NextTurn = true;
	while(!exitDuel)
	{
		//set player's health, name, stamina and beans before each turn set
		displayPtr->setStamina(player1->getStamina(), player2->getStamina());
		displayPtr->setName(player1->getName(), player2->getName());
		displayPtr->setHouse(player1->getHouse(), player2->getHouse());
		displayPtr->setBeans(player1->getBeans(), player2->getBeans());
		//display duel graphic at start of every turn set
		displayPtr->displayNext(DCdisplay::displayOutput::clear);
		displayPtr->displayNext(DCdisplay::displayOutput::duelGraphic);
		if (((player1->getStamina() > 0) || (player2->getStamina() > 0)) && player1NextTurn)
		{	
			player1NextTurn = player1->playerTurn();	//player 1 takes a turn if opponent and player still have stamina
		}
		displayPtr->displayNext(DCdisplay::displayOutput::clear);
		displayPtr->displayNext(DCdisplay::displayOutput::duelGraphic);
		if (((player1->getStamina() > 0) || (player2->getStamina() > 0)) && player2NextTurn)
		{

			player2NextTurn = player2->playerTurn();	//player 2 takes a turn if opponent and player still have stamina
		}
		if ((player1->getStamina() <= 0) || (player2->getStamina() <= 0))
		{
			exitDuel = true;		//exit duel if either player's stamina is less than/equal to 0
		}
		//clear screen before looping again
		displayPtr->displayNext(DCdisplay::displayOutput::clear);
	}
}

void DCgame::connectPlayers()
{
	player1->setOpponent(*player2);
	player2->setOpponent(*player1);
}

void DCgame::exit()
{

}

void DCgame::game()
{
	intro();
	setup();
	wager();
	connectPlayers();
	readyToDuel();
	duel();
}

void DCgame::setStaminaToDisplay()
{
	displayPtr->setStamina(player1->getStamina(), player2->getStamina());
}

void DCgame::setNameToDisplay()
{
	displayPtr->setName(player1->getName(), player2->getName());
}

void DCgame::setHouseToDisplay()
{
	displayPtr->setHouse(player1->getHouse(), player2->getHouse());
}

void DCgame::setBeansToDisplay()
{
	displayPtr->setBeans(player1->getBeans(), player2->getBeans());
}

void DCgame::wager()
{
	if (!player1->getIsAI() && player2->getIsAI())
	{
		wagerPtr->singlePlayerWager(player1);
	}
	else if (!player1->getIsAI() && !player2->getIsAI())
	{
		wagerPtr->twoPlayerWager(player1, player2);
	}
}

void clearInputBuffer()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}


/*
void runwait ( int seconds )
{
clock_t endwait;
endwait = clock () + seconds * CLOCKS_PER_SEC ;
while (clock() < endwait)
{
 Do stuff while waiting 
   }
}
*/

/*
int length = 10;
chrono::steady_clock::time_point endTime = chrono::steady_clock::now() + chrono::seconds(length);
while ((chrono::steady_clock::now() < endTime) || exitLoop)
{
cout << length << "  ";
_sleep(1000);
length--;
}
*/

