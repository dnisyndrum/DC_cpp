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
	 bool selected = false;
	 char keyPress;
	 const int MIN = 1;
	 const int MAX = 3;
	 int badSpellNumber = (rand() % MAX) + MIN;
	 //display duel graphic at start of every turn set
	 displayPtr->displayNext(DCdisplay::displayOutput::clear);
	 displayPtr->displayNext(DCdisplay::displayOutput::duelGraphic);
	 if (isAI)
	 {
		 //select from list of spells depending on health and opponent's health
		 AISelectSpell();
		 timerPtr->timerWithoutCount(2);
	 }
	 else
	 {
		 displayPtr->printName(getName());
		 displayPtr->displayNext(DCdisplay::displayOutput::selectSpell);
		 chrono::steady_clock::time_point endTime = chrono::steady_clock::now() + chrono::seconds(turnTimeLimit);
		 cin.clear();	//clear buffer
		 while (chrono::steady_clock::now() < endTime)
		 {
			 keyPress = getch_noblock();
			 switch (keyPress)
			 {
			 case 'R':
				 if (isMimbled)
				 {
					 castMimbleRictus(badSpellNumber);
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 else
				 {
					 castRictus();
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 break;
			 case 'C':
				 if (isMimbled)
				 {
					 castMimbleConfringo(badSpellNumber);
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 else
				 {
					 castConfringo();
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 break;
			 case 'L':
				 if (isMimbled)
				 {
					 castMimbleLoco(badSpellNumber);
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 else
				 {
					 castLoco();
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 break;
			 case 'S':
				 if (isMimbled)
				 {
					 castMimbleStup(badSpellNumber);
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 else
				 {
					 castStup();
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 break;
			 case 'M':
				 if (isMimbled)
				 {
					 castMimbleMimble(badSpellNumber);
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 else
				 {
					 castMimble();
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 break;
			 case 'E':
				 if (isMimbled)
				 {
					 castMimbleExpel(badSpellNumber);
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 else
				 {
					 castExpel();
					 selected = true;
					 timerPtr->timerWithoutCount(2);
				 }
				 break;
			 case 'W':
				{
					drinkWiggenweld();
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
	int stamina = getStamina();
	const int MIN = 1;
	const int MAX = 3;
	int badSpellNumber = (rand() % MAX) + MIN;
		if (stamina < 100 && stamina > 90)
		{
			if (isMimbled)
			{
				castMimbleConfringo(badSpellNumber);
			}
			else
			{
				castConfringo();
			}
		}
		else if (stamina < 89 && stamina > 80)
		{
			if (isMimbled)
			{
				castMimbleExpel(badSpellNumber);
			}
			else
			{
				castExpel();
			}
		}
		else if (stamina < 79 && stamina > 70)
		{
			if (isMimbled)
			{
				castMimbleMimble(badSpellNumber);
			}
			else
			{
				castMimble();
			}
		}
		else if (stamina < 69 && stamina > 60)
		{
			spellsPtr->castStupify(this, myOpponent);
			if (isMimbled)
			{
				castMimbleStup(badSpellNumber);
			}
			else
			{
				castStup();
			}
		}
		else if (stamina < 49 && stamina > 40)
		{
			if (isMimbled)
			{
				castMimbleMimble(badSpellNumber);
			}
			else
			{
				castMimble();
			}
		}
		else if (stamina < 29 && stamina > 20)
		{
			if (isMimbled)
			{
				castMimbleConfringo(badSpellNumber);
			}
			else
			{
				castConfringo();
			}
		}
		else if (stamina < 20 && numWiggenwelds < 0)
		{
			drinkWiggenweld();
		}
		else
		{
			if (isMimbled)
			{
				castMimbleRictus(badSpellNumber);
			}
			else
			{
				castRictus();
			}
		}
}

void DCplayer::castMimbleRictus(int badSpellNumber)
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
	displayPtr->displayNext(DCdisplay::displayOutput::castTongueTiedSpell);
	
}

void DCplayer::castMimbleConfringo(int badSpellNumber)
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
	displayPtr->displayNext(DCdisplay::displayOutput::castTongueTiedSpell);
}

void DCplayer::castMimbleLoco(int badSpellNumber)
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
	displayPtr->displayNext(DCdisplay::displayOutput::castTongueTiedSpell);
}

void DCplayer::castMimbleStup(int badSpellNumber)
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
	displayPtr->displayNext(DCdisplay::displayOutput::castTongueTiedSpell);
}

void DCplayer::castMimbleMimble(int badSpellNumber)
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
	displayPtr->displayNext(DCdisplay::displayOutput::castTongueTiedSpell);
}

void DCplayer::castMimbleExpel(int badSpellNumber)
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
	displayPtr->displayNext(DCdisplay::displayOutput::castTongueTiedSpell);
}

void DCplayer::castRictus()
{
	bool hit = spellsPtr->castRictusempra(this, myOpponent);
	if (hit)
	{
		displayPtr->displayNext(DCdisplay::displayOutput::rictusHit);
	}
	else
	{
		displayPtr->displayNext(DCdisplay::displayOutput::rictusMiss);
	}
}

void DCplayer::castConfringo()
{
	bool hit = spellsPtr->castConfringo(this, myOpponent);
	if (hit)
	{
		displayPtr->displayNext(DCdisplay::displayOutput::confHit);
	}
	else
	{
		displayPtr->displayNext(DCdisplay::displayOutput::confMiss);
	}
}

void DCplayer::castLoco()
{
	bool hit = spellsPtr->castLocomotorMortis(this, myOpponent);
	if (hit)
	{
		cout << myOpponent->getName();
		displayPtr->displayNext(DCdisplay::displayOutput::locoHit);
		displayPtr->displayNext(DCdisplay::displayOutput::haveBeenLocoed);
	}
	else
	{
		displayPtr->displayNext(DCdisplay::displayOutput::locoMiss);
	}
}

void DCplayer::castStup()
{
	bool hit = spellsPtr->castStupify(this, myOpponent);
	if (hit)
	{
		cout << myOpponent->getName();
		displayPtr->displayNext(DCdisplay::displayOutput::stupHit);
		displayPtr->displayNext(DCdisplay::displayOutput::haveBeenExpelled);
	}
	else
	{
		displayPtr->displayNext(DCdisplay::displayOutput::stupMiss);
	}
}

void DCplayer::castMimble()
{
	bool hit = spellsPtr->castMimblewimble(this, myOpponent);
	if (hit)
	{
		displayPtr->displayNext(DCdisplay::displayOutput::mimbleHit);
	}
	else
	{
		displayPtr->displayNext(DCdisplay::displayOutput::mimbleMiss);
	}
}

void DCplayer::castExpel()
{
	bool hit = spellsPtr->castExpelliarmus(this, myOpponent);
	if (hit)
	{
		cout << myOpponent->getName();
		displayPtr->displayNext(DCdisplay::displayOutput::expelHit);
		displayPtr->displayNext(DCdisplay::displayOutput::haveBeenExpelled);
	}
	else
	{
		displayPtr->displayNext(DCdisplay::displayOutput::expelMiss);
	}
}

void DCplayer::drinkWiggenweld()
{
	if (numWiggenwelds > 0)
	{
		spellsPtr->drinkWiggenweld(this);
		displayPtr->displayNext(DCdisplay::displayOutput::drinkWiggenweld);
	}
	else
	{
		displayPtr->displayNext(DCdisplay::displayOutput::outofWiggenwelds);
	}
}
