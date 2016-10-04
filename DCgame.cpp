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
using namespace std;

DCgame::DCgame()
{
	displayPtr = new DCdisplay();
	timerPtr = new DCtimer();
	game();							
}

void DCgame::intro()
{
	displayPtr->displayNext(DCdisplay::displayOutput::titles1);
	timerPtr->timerWithoutCount(3);
	displayPtr->displayNext(DCdisplay::displayOutput::titles2);
	timerPtr->timerWithoutCount(3);
	displayPtr->displayNext(DCdisplay::displayOutput::clear);
}

void DCgame::setup()
{
	bool goodToGo = false;
	char input;

	//loop until acceptable response
	while(!goodToGo)
	{
		try
		{
			//display -> ask user for pvp or pvai game
			displayPtr->displayNext(DCdisplay::displayOutput::PvPorAI);
			cin >> input;
			input = toupper(input);
			if (input == 'P' || input == 'C' || input == 'T')
			{
				goodToGo = true;
				switch (input)
				{
				case 'P':
					player1 = new DCplayer(false);
					player2 = new DCplayer(false);
					break;
				case 'C':
					player1 = new DCplayer(false);
					player2 = new DCplayer(true);
					break;
				case 'T':
					player1 = new DCplayer(true);
					player2 = new DCplayer(true);
					break;
				}
			}
			else
			{
				throw exception();
			}
		}
		catch (exception)
		{
			displayPtr->displayNext(DCdisplay::displayOutput::badInput);
		}
	}
	//if pvp, player1ai = false and player2ai = false, else player1ai = false and player2ai = true
	//set pvai to true/false, set pvp to true, false
	
}

void DCgame::duel()
{
	bool exitDuel = false;
	while(!exitDuel)
	{
		if ((player1->getStamina() > 0) || (player2->getStamina() > 0))
		{
			player1->playerTurn();	//player 1 takes a turn if opponent and player still have stamina
		}
		if ((player1->getStamina() > 0) || (player2->getStamina() > 0))
		{
			player2->playerTurn();	//player 2 takes a turn if opponent and player still have stamina
		}
		if ((player1->getStamina() <= 0) || (player2->getStamina() <= 0))
		{
			exitDuel = true;		//exit duel if either player's stamina is less than/equal to 0
		}
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
	//play intro
	intro();
	//setup players (name, house)
	setup();
	connectPlayers();
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

}

