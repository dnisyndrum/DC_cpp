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
	displayPtr->displayNext(DCdisplay::displayOutput::setupBanner);
	//display -> ask user for pvp or pvai game
	displayPtr->displayNext(DCdisplay::displayOutput::PvPorAI);
	//loop until acceptable response
	while(!goodToGo)
	{
		keyPress = _getch();
		keyPress = toupper(keyPress);
		switch (keyPress)
		{
		case 'P':
			displayPtr->displayNext(DCdisplay::displayOutput::clear);
			player1 = new DCplayer(false);
			player2 = new DCplayer(false);
			player1->setPlayerNumber(1);
			player2->setPlayerNumber(2);
			setDisplayPtrs();
			goodToGo = true;
			break;
		case 'C':
			displayPtr->displayNext(DCdisplay::displayOutput::clear);
			player1 = new DCplayer(false);
			player2 = new DCplayer(true);
			player1->setPlayerNumber(1);
			player2->setPlayerNumber(2);
			setDisplayPtrs();
			goodToGo = true;
			break;
		case 'T':
			displayPtr->displayNext(DCdisplay::displayOutput::clear);
			player1 = new DCplayer(true);
			player2 = new DCplayer(true);
			player1->setPlayerNumber(1);
			player2->setPlayerNumber(2);
			setDisplayPtrs();
			goodToGo = true;
			break;
		}
	}
}

void DCgame::setDisplayPtrs()
{
	player1->setDisplayPtr(displayPtr);
	player2->setDisplayPtr(displayPtr);
}

void DCgame::duel()
{
	bool goodToGo = false;
	char keyPress;
	bool exitDuel = false;
	bool exitGame = false;
	readyToDuel();
	while (!exitGame)
	{
		//set player's health, name, stamina and beans before each turn set
		displayPtr->setName(player1->getName(), player2->getName());
		displayPtr->setHouse(player1->getHouse(), player2->getHouse());
		displayPtr->setBeans(player1->getBeans(), player2->getBeans());
		displayPtr->setStamina(player1->getStamina(), player2->getStamina());
		while (!exitDuel)
		{
			if (((player1->getStamina() > 0) || (player2->getStamina() > 0)) && (player1->getIsMyTurn()))
			{
				player1->playerTurn();	//player 1 takes a turn if opponent and player still have stamina
			}
			player1->setIsMyTurn(true);
			player1->resetStupify();
			player1->resetMimble();
			if (((player1->getStamina() > 0) || (player2->getStamina() > 0)) && (player2->getIsMyTurn()))
			{
				player2->playerTurn();	//player 2 takes a turn if opponent and player still have stamina
			}
			player2->setIsMyTurn(true);
			player2->resetStupify();
			player2->resetMimble();
			if ((player1->getStamina() <= 0) || (player2->getStamina() <= 0))
			{
				exitDuel = true;		//exit duel if either player's stamina is less than/equal to 0
			}
			//clear screen before looping again
			displayPtr->displayNext(DCdisplay::displayOutput::clear);
		}
		//display winner
		int player1Beans = player1->getBeans();
		int player2Beans = player2->getBeans();
		int player1Wager = wagerPtr->getPlayer1Wager();
		int player2Wager = wagerPtr->getPlayer2Wager();
		if (player1->getStamina() > player2->getStamina())
		{
			//award beans to winner from loser
			player1->setBeans(player1Beans += player1Wager);
			//take beans from losing player if player is not an AI
			if (!player2->getIsAI())
			{
				player2->setBeans(player2Beans -= player1Wager);
			}
			displayPtr->displayNext(DCdisplay::displayOutput::player1Win);
		}
		else
		{
			//award beans to winner from loser
			player2->setBeans(player2Beans += player2Wager);
			//take beans from losing player if player is not an AI
			if (!player2->getIsAI())
			{
				player1->setBeans(player1Beans -= player2Wager);
			}
			displayPtr->displayNext(DCdisplay::displayOutput::player2Win);
		}
		timerPtr->timerWithoutCount(2);
		//ask if player would like to duel again
		displayPtr->displayNext(DCdisplay::displayOutput::duelAgain);
		//prompt player to player again or quit
		while (!goodToGo)
		{
			keyPress = _getch();
			keyPress = toupper(keyPress);
			switch (keyPress)
			{
			case 'Y':
				//call reset
				reset();
				goodToGo = true;
				exitDuel = false;
				break;
			case 'N':
				delete player1;
				delete player2;
				exitGame = true;
				goodToGo = true;
				break;
			}
		}
	}
}

void DCgame::reset()
{
	//both players are not AI
	if (player1->getIsAI() == false && player2->getIsAI() == false)
	{
		player1->setStamina(100);
		player2->setStamina(100);
	}
	//player 1 is not AI and player 2 is AI
	else if (player1->getIsAI() == false && player2->getIsAI() == true)
	{
		player1->setStamina(100);
		delete player2;
		player2 = new DCplayer(true);
	}
	//both players are AI
	else
	{
		delete player1;
		delete player2;
		player1 = new DCplayer(true);
		player2 = new DCplayer(true);
	}
}

void DCgame::connectPlayers()
{
	player1->setOpponent(player2);
	player2->setOpponent(player1);
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
	duel();
	//exit();
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
	displayPtr->displayNext(DCdisplay::displayOutput::setupBanner);
	if (!player1->getIsAI() && player2->getIsAI())
	{
		wagerPtr->singlePlayerWager(player1);
	}
	else if (!player1->getIsAI() && !player2->getIsAI())
	{
		wagerPtr->twoPlayerWager(player1, player2);
	}
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

