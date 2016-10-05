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
#include <string>
#include <thread>
#include "DCplayer.h"
#include "DCdisplay.h"
#include "DCtimer.h"
using namespace std;

void DCplayer::setup()
{
	bool nameSelected = false;
	bool houseSelected = false;
	if (!isAI)
	{
		//setup for human player
		while (!nameSelected)
		{
			cout << "Enter a name for your wizard:\n";
			nameSelected = nameSelect(cin);
		}
		while (!houseSelected)
		{
			cout << "Select a Hogwarts house for your wizard (G, H, R, S):\n";
			houseSelected = houseSelect(cin);
		}
	}
	else
	{
		//setup for computer, selects name and house
		AISelectName();
		AISelectHouse();
	}
}

bool DCplayer::houseSelect(istream& sin)
{
	bool goodToGo = false;
	char houseSelection = 'G';

	sin >> houseSelection;
	houseSelection = toupper(houseSelection);
	if ((houseSelection == 'G') || (houseSelection == 'H') || (houseSelection == 'R') || (houseSelection == 'S'))
	{
		
		switch (houseSelection)
		{
		case 'G':
			setHouse(Gryffinfor);
			break;
		case 'H':
			setHouse(Hufflepuff);
			break;
		case 'R':
			setHouse(Ravenclaw);
			break;
		case 'S':
			setHouse(Slytherin);
			break;
		}
		cout << myName << "'s house is " << getHouse() << "\n";
		goodToGo = true;
	}
	else
	{
		cout << "Invalid selection. Please select your Hogwarts house (G, H, R, S): ";
	}
	return goodToGo;
}

bool DCplayer::nameSelect(istream& sin)
{
	const int MAX_LENGTH = 24;
	bool goodToGo = false;
	string nameSelection;

	sin >> nameSelection;
	if (nameSelection.length() > MAX_LENGTH)
	{
		cout << "Wizard's name cannot exceed 24 characters. Please enter a new name: ";
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
	bool spellSelected = false;
	if (isAI)
	{
		//select from list of spells depending on health and opponent's health

	}
	else
	{
		//prompt player to select a spell to cast, set player attributes
		displayPtr->setSinglePlayerName(getName());
		displayPtr->setSinglePlayerHouse(getHouse());
		displayPtr->setSinglePlayerBeans(getBeans());
		displayPtr->setSinglePlayerStamina(getStamina());
		displayPtr->displayNext(DCdisplay::displayOutput::selectSpell);
		while (!spellSelected)
		{

		}
	}
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