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
using namespace std;

#ifndef DCGAME_H
#define DCGAME_H

class DCgame
{
public:
	//constructor
	DCgame();

	//encapsulates the dueling club game
	void game();

private:			
	void connectPlayers();		//connects the two players via their pointer properties
	void intro();				//procedurally displays intro text
	void setup();				//prompts for player's name, house, and PvAI or PvP
	void wager();				//prompts either one or both players to set bean wagers
	void duel();				//houses the main dueling game
	void exit();				//calls destructors and exits game
	void setStaminaToDisplay();
	void setNameToDisplay();
	void setHouseToDisplay();
	void setBeansToDisplay();

	DCtimer* timerPtr;
	DCdisplay* displayPtr;
	DCplayer* currentTurn;
	DCplayer* player1;
	DCplayer* player2;
	
};
#endif