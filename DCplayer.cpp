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
#include<conio.h>
#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>
#include "DCplayer.h"
#include "DCdisplay.h"
#include "DCtimer.h"
#include "DCspells.h"
using namespace std;

int getch_noblock();

void DCplayer::setup()
{
	bool nameSelected = false;
	bool houseSelected = false;
	if (!isAI)
	{
		//setup for human player
		while (!nameSelected)
		{
			displayPtr->displayNext(DCdisplay::displayOutput::setupBanner);
			displayPtr->displayNext(DCdisplay::displayOutput::enterName);
			nameSelected = nameSelect(cin);
		}
		displayPtr->displayNext(DCdisplay::displayOutput::enterHouse);
		houseSelect();
	}
	else
	{
		//setup for computer, selects name and house
		AISelectName();
		AISelectHouse();
	}
}

void DCplayer::houseSelect()
{
	bool goodToGo = false;
	char keyPress;
	while (!goodToGo)
	{
		keyPress = _getch();
		keyPress = toupper(keyPress);
		switch(keyPress)
		{
		case 'G':
			setHouse(Gryffinfor);
			goodToGo = true;
			break;
		case 'H':
			setHouse(Hufflepuff);
			goodToGo = true;
			break;
		case 'R':
			setHouse(Ravenclaw);
			goodToGo = true;
			break;
		case 'S':
			setHouse(Slytherin);
			goodToGo = true;
			break;
		}
	}
	displayPtr->displayNext(DCdisplay::displayOutput::clear);
}

bool DCplayer::nameSelect(istream& sin)
{
	const int MAX_LENGTH = 24;
	bool goodToGo = false;
	string nameSelection;

	sin >> nameSelection;
	if (nameSelection.length() > MAX_LENGTH)
	{
		displayPtr->displayNext(DCdisplay::displayOutput::nameTooLong);
	}
	else 
	{
		setName(nameSelection);
		goodToGo = true;
	}
	return goodToGo;
}

 void DCplayer::playerTurn()
 {
	 int turnTimeLimit = 10;
	 char selectedSpell;
	 bool selected = false;
	 char keyPress;
	 const int MIN = 1;
	 const int MAX = 3;
	 int badSpellNumber = (rand() % MAX) + MIN;
	 if (isAI)
	 {
		 //select from list of spells depending on health and opponent's health
		 AISelectSpell();
		 //print out spell selected
	 }
	 else
	 {
		 displayPtr->displayNext(DCdisplay::displayOutput::clear);
		 if (playerNumber == 1)
		 {
			 displayPtr->updatePlayer1Stamina(getStamina());
		 }
		 else
		 {
			 displayPtr->updatePlayer2Stamina(getStamina());
		 }
		 //display duel graphic at start of every turn set
		 displayPtr->displayNext(DCdisplay::displayOutput::duelGraphic);
		 displayPtr->printName(getName());
		 displayPtr->displayNext(DCdisplay::displayOutput::selectSpell);
		 chrono::steady_clock::time_point endTime = chrono::steady_clock::now() + chrono::seconds(turnTimeLimit);
		 cin.clear();	//clear buffer
		 while (chrono::steady_clock::now() < endTime)
		 {
			 bool hit;
			 keyPress = getch_noblock();
			 switch (keyPress)
			 {
			 case 'R':
				 if (isMimbled)
				 {
					 switch (badSpellNumber)
					 {
					 case 1:
						 displayPtr->displayNext(DCdisplay::displayOutput::badRictus1);
						 break;
					 case 2:
						 displayPtr->displayNext(DCdisplay::displayOutput::badRictus2);
						 break;
					 case 3:
						 displayPtr->displayNext(DCdisplay::displayOutput::badRictus3);
						 break;
					 }
					 selected = true;
					 displayPtr->displayNext(DCdisplay::displayOutput::castTongueTiedSpell);
					 timerPtr->timerWithoutCount(2);
				 }
				 else
				 {
					 hit = spellsPtr->castRictusempra(this, myOpponent);
					 if (hit)
					 {
						 displayPtr->displayNext(DCdisplay::displayOutput::rictusHit);
					 }
					 else
					 {
						 displayPtr->displayNext(DCdisplay::displayOutput::rictusMiss);
					 }
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 break;
			 case 'C':
				 if (isMimbled)
				 {
					 switch (badSpellNumber)
					 {
					 case 1:
						 displayPtr->displayNext(DCdisplay::displayOutput::badConfringo1);
						 break;
					 case 2:
						 displayPtr->displayNext(DCdisplay::displayOutput::badConfringo2);
						 break;
					 case 3:
						 displayPtr->displayNext(DCdisplay::displayOutput::badConfringo3);
						 break;
					 }
					 selected = true;
					 displayPtr->displayNext(DCdisplay::displayOutput::castTongueTiedSpell);
					 timerPtr->timerWithoutCount(2);
				 }
				 else
				 {
					 hit = spellsPtr->castConfringo(this, myOpponent);
					 if (hit)
					 {
						 displayPtr->displayNext(DCdisplay::displayOutput::confHit);
					 }
					 else
					 {
						 displayPtr->displayNext(DCdisplay::displayOutput::confMiss);
					 }
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 break;
			 case 'L':
				 if (isMimbled)
				 {
					 switch (badSpellNumber)
					 {
					 case 1:
						 displayPtr->displayNext(DCdisplay::displayOutput::badLoco1);
						 break;
					 case 2:
						 displayPtr->displayNext(DCdisplay::displayOutput::badLoco2);
						 break;
					 case 3:
						 displayPtr->displayNext(DCdisplay::displayOutput::badLoco3);
						 break;
					 }
					 selected = true;
					 displayPtr->displayNext(DCdisplay::displayOutput::castTongueTiedSpell);
					 timerPtr->timerWithoutCount(2);
				 }
				 else
				 {
					 hit = spellsPtr->castLocomotorMortis(this, myOpponent);
					 if (hit)
					 {
						 displayPtr->displayNext(DCdisplay::displayOutput::locoHit);
					 }
					 else
					 {
						 displayPtr->displayNext(DCdisplay::displayOutput::locoMiss);
					 }
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 break;
			 case 'S':
				 if (isMimbled)
				 {
					 switch (badSpellNumber)
					 {
					 case 1:
						 displayPtr->displayNext(DCdisplay::displayOutput::badStup1);
						 break;
					 case 2:
						 displayPtr->displayNext(DCdisplay::displayOutput::badStup2);
						 break;
					 case 3:
						 displayPtr->displayNext(DCdisplay::displayOutput::badStup3);
						 break;
					 }
					 selected = true;
					 displayPtr->displayNext(DCdisplay::displayOutput::castTongueTiedSpell);
					 timerPtr->timerWithoutCount(2);
				 }
				 else
				 {
					 hit = spellsPtr->castStupify(this, myOpponent);
					 if (hit)
					 {
						 displayPtr->displayNext(DCdisplay::displayOutput::stupHit);
					 }
					 else
					 {
						 displayPtr->displayNext(DCdisplay::displayOutput::stupMiss);
					 }
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 break;
			 case 'M':
				 if (isMimbled)
				 {
					 switch (badSpellNumber)
					 {
					 case 1:
						 displayPtr->displayNext(DCdisplay::displayOutput::badMimble1);
						 break;
					 case 2:
						 displayPtr->displayNext(DCdisplay::displayOutput::badMimble2);
						 break;
					 case 3:
						 displayPtr->displayNext(DCdisplay::displayOutput::badMimble3);
						 break;
					 }
					 selected = true;
					 displayPtr->displayNext(DCdisplay::displayOutput::castTongueTiedSpell);
					 timerPtr->timerWithoutCount(2);
				 }
				 else
				 {
					 hit = spellsPtr->castMimblewimble(this, myOpponent);
					 if (hit)
					 {
						 displayPtr->displayNext(DCdisplay::displayOutput::mimbleHit);
					 }
					 else
					 {
						 displayPtr->displayNext(DCdisplay::displayOutput::mimbleMiss);
					 }
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 break;
			 case 'P':
				 if (isMimbled)
				 {
					 switch (badSpellNumber)
					 {
					 case 1:
						 displayPtr->displayNext(DCdisplay::displayOutput::badProtego1);
						 break;
					 case 2:
						 displayPtr->displayNext(DCdisplay::displayOutput::badProtego2);
						 break;
					 case 3:
						 displayPtr->displayNext(DCdisplay::displayOutput::badProtego3);
						 break;
					 }
					 selected = true;
					 displayPtr->displayNext(DCdisplay::displayOutput::castTongueTiedSpell);
					 timerPtr->timerWithoutCount(2);
				 }
				 else
				 {
					 hit = spellsPtr->castProtego(this, myOpponent);
					 if (hit)
					 {
						 displayPtr->displayNext(DCdisplay::displayOutput::protegoHit);
					 }
					 else
					 {
						 displayPtr->displayNext(DCdisplay::displayOutput::protegoMiss);
					 }
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 break;
			 case 'E':
				 if (isMimbled)
				 {
					 switch (badSpellNumber)
					 {
					 case 1:
						 displayPtr->displayNext(DCdisplay::displayOutput::badExpel1);
						 break;
					 case 2:
						 displayPtr->displayNext(DCdisplay::displayOutput::badExpel2);
						 break;
					 case 3:
						 displayPtr->displayNext(DCdisplay::displayOutput::badExpel3);
						 break;
					 }
					 selected = true;
					 displayPtr->displayNext(DCdisplay::displayOutput::castTongueTiedSpell);
					 timerPtr->timerWithoutCount(2);
				 }
				 else
				 {
					 hit = spellsPtr->castExpelliarmus(this, myOpponent);
					 if (hit)
					 {
						 displayPtr->displayNext(DCdisplay::displayOutput::expelHit);
					 }
					 else
					 {
						 displayPtr->displayNext(DCdisplay::displayOutput::expelMiss);
					 }
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 break;
			 }
			 if (selected){ break; }
		 }
	}
	displayPtr->displayNext(DCdisplay::displayOutput::clear);
}

 int getch_noblock() {
	 if (_kbhit())
		 return toupper(_getch());
	 else
		 return -1;
 }

string DCplayer::getHouse()
{
	switch (myHouse)
	{
	case Gryffinfor:
		return "Gryffindor";
		break;
	case Hufflepuff:
		return "Hufflepuff";
		break;
	case Ravenclaw:
		return "Ravenclaw";
		break;
	case Slytherin:
		return "Slytherin";
		break;
	default:
		return "No house selected";
		break;
	}
}

void DCplayer::AISelectName()
{
	const int NUM_OPPONENTS = 10;
	int randomNumber = rand() % NUM_OPPONENTS;
	switch (randomNumber)
	{
	case 0:
		setName("Taylor");
		break;
	case 1:
		setName("Davies");
		break;
	case 2:
		setName("James");
		break;
	case 3:
		setName("Watson");
		break;
	case 4:
		setName("Lee");
		break;
	case 5:
		setName("Foster");
		break;
	case 6:
		setName("Rogers");
		break;
	case 7:
		setName("Holmes");
		break;
	case 8:
		setName("Jenkins");
		break;
	case 9:
		setName("Murray");
		break;
	}
}

void DCplayer::AISelectHouse()
{
	const int NUM_HOUSES = 4;
	int randomNumber = rand() % NUM_HOUSES;
	switch (randomNumber)
	{
	case 0:
		myHouse = Gryffinfor;
		break;
	case 1:
		myHouse = Hufflepuff;
		break;
	case 2:
		myHouse = Ravenclaw;
		break;
	case 3:
		myHouse = Slytherin;
		break;
	}
}

void DCplayer::AISelectSpell()
{

}