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
		displayPtr = new DCdisplay();
		timerPtr = new DCtimer();
		displayPtr->setSinglePlayerStamina(getStamina());
		displayPtr->setSinglePlayerName(getName());
		displayPtr->setSinglePlayerHouse(getHouse());
		displayPtr->setSinglePlayerBeans(getBeans());
		setup();
	};

	//getters and setters
	string getName() { return myName; }
	int getBeans() { return myBeans; }
	bool getIsAI() { return isAI; }
	string getHouse();
	int getStamina() { return myStamina; }

	void setBeans(int newBeans) { myBeans = newBeans; }
	void setIsAI(bool newAI) { isAI = newAI; }
	void setStamina(int newStamina) { myStamina = newStamina; }
	void setOpponent(DCplayer opponent) { myOpponent = &opponent; }

	//sets up player information via user input
	void setup();
	void playerTurn();

	//destructor
	~DCplayer(){};

private:
	void setName(string newName) { myName = newName; }
	void setHouse(house newHouse) { myHouse = newHouse; }

	//sets chosen name
	bool nameSelect(istream&);
	//ensure player selects a house (G, H, R, S)
	bool houseSelect(istream&);
	//select at random a name for an AI
	void AISelectName();
	//select at random a house for an AI
	void AISelectHouse();

	house myHouse;
	string myName;
	int myStamina;
	int myBeans;
	bool isAI;
	DCplayer* myOpponent;
	DCtimer* timerPtr;
	DCdisplay* displayPtr;

	//selects at random an AI player name
	string selectName();

};
#endif