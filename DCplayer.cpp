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
}

bool DCplayer::houseSelect(istream& sin)
{
	bool goodToGo = false;
	char houseSelection = 'G';

	houseSelection = sin.get();
	if (toupper(houseSelection) != ('G' || 'H' || 'R' || 'S'))
	{
		cout << "Invalid selection. Please select your Hogwarts house (G, H, R, S): ";
	}
	else
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
		cout << myName << "'s house is " << myHouse << "\n";
		goodToGo = true;
	}
	return goodToGo;
}

bool DCplayer::nameSelect(istream& sin)
{
	const int MAX_LENGTH = 24;
	bool goodToGo = false;
	string nameSelection;

	getline(sin, nameSelection);
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
	if (isAI)
	{

	}
	else
	{
		//prompt player to select a spell to cast
		displayPtr->displayNext(DCdisplay::displayOutput::selectSpell);
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
	}
}

void DCplayer::AISelectName()
{

}