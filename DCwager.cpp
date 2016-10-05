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
#include "DCwager.h"
#include "DCplayer.h"
#include "DCdisplay.h"
using namespace std;

void DCwager::singlePlayerWager(DCplayer* player)
{
	bool goodToGo = false;
	while (!goodToGo)
	{
		//prompt user to enter a number of beans to wager
		displayPtr->displayNext(DCdisplay::displayOutput::wagerPrompt);
		try
		{
			cin >> player1Wager;
			if (player1Wager > player->getBeans())
			{
				//player wagers more beans than player has
				displayPtr->displayNext(DCdisplay::displayOutput::invalidTooMany);
			}
			else if (player1Wager < player->getBeans())
			{
				//player wagers fewer beans than player has
				displayPtr->displayNext(DCdisplay::displayOutput::invalidTooFew);
			}
			else
			{
				displayPtr->displayNext(DCdisplay::displayOutput::wagerReady);
				goodToGo = true;
			}
		}
		catch (exception)
		{
			//player enters a non-numeric input
			displayPtr->displayNext(DCdisplay::displayOutput::badInput);
		}
	}
}

void DCwager::twoPlayerWager(DCplayer* player1, DCplayer* player2)
{
	bool goodToGo = false;
	while (!goodToGo)
	{

	}
}
