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
#include <string>
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
			else if (player1Wager < 0)
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
	bool allGoodToGo = false;
	bool p1GoodToGo = false;
	bool p2GoodToGo = false;
	while (!allGoodToGo)
	{
		while (!p1GoodToGo)
		{
			//prompt user to enter a number of beans to wager
			cout << player1->getName();
			displayPtr->displayNext(DCdisplay::displayOutput::twoPlayerWagerPrompt);
			try
			{
				cin >> player1Wager;
				if (player1Wager > player1->getBeans())
				{
					//player wagers more beans than player has
					displayPtr->displayNext(DCdisplay::displayOutput::invalidTooMany);
				}
				else if (player1Wager < 0)
				{
					//player wagers fewer beans than player has
					displayPtr->displayNext(DCdisplay::displayOutput::invalidTooFew);
				}
				else
				{
					p1GoodToGo = true;
				}
			}
			catch (exception)
			{
				//player enters a non-numeric input
				displayPtr->displayNext(DCdisplay::displayOutput::badInput);
			}
		}

		while (!p2GoodToGo)
		{
			//prompt user to enter a number of beans to wager
			cout << player2->getName();
			displayPtr->displayNext(DCdisplay::displayOutput::twoPlayerWagerPrompt);
			try
			{
				cin >> player1Wager;
				if (player1Wager > player2->getBeans())
				{
					//player wagers more beans than player has
					displayPtr->displayNext(DCdisplay::displayOutput::invalidTooMany);
				}
				else if (player1Wager < 0)
				{
					//player wagers fewer beans than player has
					displayPtr->displayNext(DCdisplay::displayOutput::invalidTooFew);
				}
				else
				{
					p2GoodToGo = true;
				}
			}
			catch (exception)
			{
				//player enters a non-numeric input
				displayPtr->displayNext(DCdisplay::displayOutput::badInput);
			}
		}
		displayPtr->displayNext(DCdisplay::displayOutput::wagerReady);
		cin.get();
		///exit nested loop
		allGoodToGo = true;
	}
}


