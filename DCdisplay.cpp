//-----------------------------------------------------------------------------
//   File: Dueling Club
//   Class: DCdisplay.cpp
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
using namespace std;
#include <stdio.h>
#include <iostream>
#include <string>
#include "DCdisplay.h"

void DCdisplay::displayNext(displayOutput display)
{
	switch (display)
	{
	case titles1:
		cout << "       __     __        __        _________    _________    ___    ___        \n";
		cout << "      |  |   |  |      |  |      |   ___   |  |   ___   |  |   |  |   |       \n";
		cout << "      |  |   |  |     |    |     |  |   |  |  |  |   |  |  |   |  |   |       \n";
		cout << "      |  |___|  |    |  __  |    |  |___|  |  |  |___|  |  |   |__|   |       \n";
		cout << "      |   ___   |   |  |__|  |   |       __|  |       __|  |___    ___|       \n";
		cout << "      |  |   |  |  |   ____   |  |   _  |     |   _  |         |  |           \n";
		cout << "      |  |   |  |  |  |    |  |  |  | |  |_   |  | |  |_       |  |           \n";
		cout << "      |__|   |__|  |__|    |__|  |__|  |___|  |__|  |___|      |__|           \n";
		cout << "   _________   __________   __________   __________   _________    __________ \n";
		cout << "  |   ___   | |   ____   | |___    ___| |___    ___| |   ______|  |   ____   |\n";
		cout << "  |  |   |  | |  |    |  |     |  |         |  |     |  |         |  |    |  |\n";
		cout << "  |  |___|  | |  |    |  |     |  |         |  |     |  |_____    |  |____|  |\n";
		cout << "  |   ______| |  |    |  |     |  |         |  |     |   _____|   |   __   __|\n";
		cout << "  |  |        |  |    |  |     |  |         |  |     |  |         |  |  | |   \n";
		cout << "  |  |        |  |____|  |     |  |         |  |     |  |_____    |  |   | |_ \n";
		cout << "  |__|        |__________|     |__|         |__|     |________|   |__|    |__|\n\n";
		break;
	case titles2:
		cout << "                                 DUELING CLUB                                 \n\n";
		break;
	case fullScreen:
		cout << "                (Please expand your window to fill the screen)";
		break;
	case intro1:
		cout << "Professor Lochhart:\n";
		cout << "Can everyone see me? Can you all hear me? Excellent!\n";
		cout << "I started Dueling Club to train you to defend yourselves.\n";
		cout << "Dueling Club meets every day in the antichamber just outside the Great Hall.\n";
		cout << "In wizard dueling, the object of the exercise is to incapacitate your opponent.\n";
		break;
	case intro2:
		cout << "There are several spells you can use in dueling:\n";
		cout << "   -Rictusempra -      tickling charm, inflicts damage\n";
		cout << "   -Confringo -        exploding spell, causes sizable damage\n";
		cout << "   -Locomotor Mortis - leg lock curse, opponent loses next turn\n";
		cout << "   -Stupify -          inflicts damage, opponent's next spell is less powerful\n";
		cout << "   -Mimblewimble -     your opponent is tongue-tied during next turn\n";
		cout << "   -Protego -          rebounds last cast spell back to your opponent\n";
		cout << "   -Expelliarmus -     causes damage, opponent loses next turn\n";
		break;
	case PvPorAI:
		cout << "Would you like to duel the computer or another player(P,C)?\n";
		break;
	case clear:
		system("CLS");
		break;
	case badInput:
		cout << "You have entered an invalid input, try again\n";
		break;
	case duelGraphic:
		cout << "         _____________     \n";
		cout << "        |       O     |     Player 1:   " << player1Name << "\n";
		cout << "        |      -|-    |     House:      " << player1House << "\n";
		cout << "        |      /|     |     Beans left: " << player1Beans << "\n";
		cout << "        |      *      |     Stamina:    " << player1Stamina << "\n";
		cout << "        |      |      |     \n";
		cout << "        |  |   |   |  |     \n";
		cout << "        |  |   |   |  |     \n";
		cout << "        |   |__|__|   |     \n";
		cout << "        |      |      |     \n";
		cout << "        | |    |    | |     \n";
		cout << "        | |    |    | |     \n";
		cout << "        |  |___|___|  |     \n";
		cout << "        |   ___|___   |     \n";
		cout << "        |  |   |   |  |     \n";
		cout << "        | |    |    | |     \n";
		cout << "        |  |___|___|  |     \n";
		cout << "        |   ___|___   |     \n";
		cout << "        |  |   |   |  |     \n";
		cout << "        | |    |    | |     \n";
		cout << "        |  |   |   |  |     \n";
		cout << "        |    __|__    |     \n";
		cout << "        |   |  |  |   |     \n";
		cout << "        |  |   |   |  |     \n";
		cout << "        |   |  |  |   |     \n";
		cout << "        |      |      |     \n";
		cout << "        |      *      |     Player 2:   " << player2Name << "\n";
		cout << "        |       O     |     House:      " << player2House << "\n";
		cout << "        |      -|-    |     Beans left: " << player2Beans << "\n";
		cout << "        |______/|_____|     Stamina:    " << player2Stamina << "\n\n";
		break;
	case setupBanner:
		cout << "\n-----------------------Dueling Club Setup-----------------------\n\n";
		break;
	case selectSpell:
		cout << ", select a spell to cast:\n";
		cout << "   -Rictusempra      (R)\n";
		cout << "   -Confringo        (C)\n";
		cout << "   -Locomotor Mortis (L)\n";
		cout << "   -Stupify          (S)\n";
		cout << "   -Mimblewimble     (M)\n";
		cout << "   -Protego          (P)\n";
		cout << "   -Expelliarmus     (E)\n";
		break;
	case readyToDuel:
		cout << "Wands at the ready!\n";
		break;
	case count1:
		cout << "1...\n";
		break;
	case count2:
		cout << "2...\n";
		break;
	case count3:
		cout << "3...\n";
		break;
	case count4:
		cout << "Duel!\n";
		break;
	case wagerPrompt:
		cout << "Enter the number of Bertie Bott's Beans you would like to wager: ";
		break;
	case invalidTooMany:
		cout << "You do not have that many Bertie Bott's Beans.\n";
		break;
	case invalidTooFew:
		cout << "You have entered too small of an amount.";
		break;
	case wagerReady:
		cout << "Bertie Bott's Bean wagers set.";
		break;
	case twoPlayerWagerPrompt:
		cout << ", enter the number of Bertie Bott's Beans you would like to wager: ";
		break;
	case enterName:
		cout << "Enter a name for your wizard:\n";
		break;
	case enterHouse:
		cout << "Select a Hogwarts house for your wizard (G, H, R, S):\n";
		break;
	case nameTooLong:
		cout << "Wizard's name cannot exceed 24 characters.\n";
		break;
	case badHouseSelect:
		cout << "Invalid selection. Please select your Hogwarts house (G, H, R, S).\n";
		break;
	case duelAgain:
		cout << "Would you like to duel again (Y,N)? ";
		break;
	case player1Win:
		cout << player1Name << " won the duel! ";
			break;
	case player2Win:
		cout << player2Name << "  won the duel! ";
			break;
	}
}


/*
rictusempra, mimblewimble,
expelliarmus, confringo, locomotorMortis, stupify, protego
Can everyone see me? Can you all hear me? Excellent!
I started Dueling Club to train you to defend yourselves. Dueling Club meets every day in the antichamber just outside the Great Hall.
In wizard dueling, the object of the exercise is to incapacitate your opponent.
There are several spells you can use in dueling:

To select a spell, enter the spell's identifying number when prompted.
To cast the selected spell on your opponent, press enter.
The longer you wait to cast your spell, the stronger it will be.
Note that jumping and potion drinking during duels are prohibited.
A pledge of Bertie Bott's Every Flavored Beans is required to duel. The victor wins the opponents beans.
Very well then. Wands at the ready! When I count to three?
One-two-three!
*/