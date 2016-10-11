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
#include <windows.h>
#include <cstdlib>
#include <future>
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
			displayPtr->displayNext(DCdisplay::displayOutput::enterName);
			nameSelected = nameSelect(cin);
		}
		while (!houseSelected)
		{
			displayPtr->displayNext(DCdisplay::displayOutput::enterHouse);
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
		goodToGo = true;
	}
	else
	{
		displayPtr->displayNext(DCdisplay::displayOutput::badHouseSelect);
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
		displayPtr->displayNext(DCdisplay::displayOutput::nameTooLong);
	}
	else 
	{
		setName(nameSelection);
		goodToGo = true;
	}
	return goodToGo;
}

 char safeSpell()
{
	char input;
	try
	{
		input = toupper(cin.get());
	}
	catch (exception)
	{
		cout << "Bad spell selection.\n";
	}
	return input;
}

 bool DCplayer::playerTurn()
 {
	 int turnTimeLimit = 10;
	 char selectedSpell = 'N';
	 bool selected = false;
	 bool doNotSkipNextTurn = true;

	 if (isAI)
	 {
		 //select from list of spells depending on health and opponent's health

	 }
	 else
	 {
		 //prompt player to select a spell to cast, set player stamina
		 displayPtr->setSinglePlayerName(getName());
		 displayPtr->setSinglePlayerStamina(getStamina());
		 displayPtr->displayNext(DCdisplay::displayOutput::selectSpell);
		 chrono::steady_clock::time_point endTime = chrono::steady_clock::now() + chrono::seconds(turnTimeLimit);
		 cin.clear();	//clear buffer
		 while ((chrono::steady_clock::now() < endTime))
		 {
			 if (GetAsyncKeyState(VkKeyScan(114)))
			 {
				 cout << "selected r";
				 _sleep(1000);
				 break;
			 }
			 else if (GetAsyncKeyState(VkKeyScan(99)))
			 {
				 cout << "selected c";
				 _sleep(1000);
				 break;
			 }
			 else if (GetAsyncKeyState(VkKeyScan(108)))
			 {
				 cout << "selected l";
				 _sleep(1000);
				 break;
			 }
			 else if (GetAsyncKeyState(VkKeyScan(115)))
			 {
				 cout << "selected s";
			 _sleep(1000);
				 break;
			 }
			 else if (GetAsyncKeyState(VkKeyScan(109)))
			 {
				 cout << "selected m";
				 _sleep(1000);
				 break;
			 }
			 else if (GetAsyncKeyState(VkKeyScan(112)))
			 {
				 cout << "selected p";
				 _sleep(1000);
				 break;
			 }
			 else if (GetAsyncKeyState(VkKeyScan(101)))
			 {
				 cout << "selected e";
				 _sleep(1000);
				 break;
			 }
		 }

 
	}
	displayPtr->displayNext(DCdisplay::displayOutput::clear);
	return doNotSkipNextTurn;
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