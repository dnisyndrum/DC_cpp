//-----------------------------------------------------------------------------
//   File: Dueling Club
//   Class: Dcwager
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

using namespace std;

#ifndef DCWAGER_H
#define DCWAGER_H

class DCwager
{
public:
	//constructor
	DCwager(){
		displayPtr = new DCdisplay();
	};

	//for PvAI
	void singlePlayerWager(DCplayer*);
	//for PvP
	void twoPlayerWager(DCplayer*, DCplayer*);

	//retrun wagers after end of game
	int getPlayer1Wager() { return player1Wager; }
	int getPlayer2Wager() { return player2Wager; }

private:
	int player1Wager;
	int player2Wager;
	DCdisplay* displayPtr;
};
#endif