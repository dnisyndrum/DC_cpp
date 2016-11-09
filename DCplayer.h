//-----------------------------------------------------------------------------
//   File: Dueling Club
//   Class: 
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//   Title:
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
#include <cstdlib>
#include <iostream>
#include "DCdisplay.h"
#include "DCtimer.h"
#include "DCspells.h"

using namespace std;

#ifndef DCPLAYER_H
#define DCPLAYER_H

class DCplayer
{
public:
	//enum for each of the four houses
	enum house {
		Gryffinfor,
		Hufflepuff,
		Ravenclaw,
		Slytherin
	};


	//constructor
	DCplayer(bool duelPC = true) : myStamina(100), myBeans(100), isAI(duelPC)
	{
		//displayPtr = new DCdisplay();
		timerPtr = new DCtimer();
		spellsPtr  = new DCspells();
		isMimbled = false;
		setup();
	};

	//getters and setters
	string getName() { return myName; }
	int getBeans() { return myBeans; }
	bool getIsAI() { return isAI; }
	string getHouse();
	int getStamina() { return myStamina; }
	bool getIsMyTurn() {return isMyTurn;}

	void setBeans(int newBeans) { myBeans = newBeans; }
	void setIsAI(bool newAI) { isAI = newAI; }
	void setStamina(int newStamina) { myStamina = newStamina; }
	void setOpponent(DCplayer* opponent) { myOpponent = opponent; }
	void setDisplayPtr(DCdisplay* display) { displayPtr = display; }	//new function to help use a single DCdisplay object
	void setIsMyTurn(bool nextTurn) { isMyTurn = nextTurn; }
	void setPlayerNumber(int number) { playerNumber = number; }
	void setTongueTied(bool tongueTied) { isMimbled = tongueTied; }

	//sets up player information via user input
	void setup();
	//called when it is this player's turn, displays duel graphic and allows player to select a spell
	void playerTurn();
	//reset stupify effect
	void resetStupify() { spellsPtr->resetStupifyEffect(); }
	void resetMimble() { isMimbled = false; }
	
private:
	void setName(string newName) { myName = newName; }
	void setHouse(house newHouse) { myHouse = newHouse; }

	//sets chosen name
	bool nameSelect(istream&);
	//ensure player selects a house (G, H, R, S)
	void houseSelect();
	//select at random a name for an AI
	void AISelectName();
	//select at random a house for an AI
	void AISelectHouse();
	//selects at random an AI player name
	string selectName();
	//AI will select a spell to cast depend on their stamina and opponent's stamina
	void AISelectSpell();

	house myHouse;
	string myName;
	int myStamina;
	int myBeans;
	bool isAI;
	bool isMyTurn;
	bool isMimbled;
	int playerNumber;
	DCspells* spellsPtr;
	DCplayer* myOpponent;
	DCtimer* timerPtr;
	DCdisplay* displayPtr;

};
#endif