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
		cout << "Player 1:   " << player1Name << "\n";
		cout << "House:      " << player1House << "\n";
		cout << "Beans left: " << player1Beans << "\n";
		cout << "Stamina:    ";
		for (int i = 0; i < (player1Stamina / 10); i++)
		{
			cout << " |";
		}
		cout << " : " << player1Stamina << "\n";
		cout << "         _____________     \n";
		cout << "        |       O     |     \n";
		cout << "        |      -|-    |     \n";
		cout << "        |      /|     |     \n";
		cout << "        |      *      |     \n";
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
		cout << "        |      *      |     \n";
		cout << "        |       O     |     \n";
		cout << "        |      -|-    |     \n";
		cout << "        |______/|_____|     \n";
		cout << "Player 2:   " << player2Name << "\n";
		cout << "House:      " << player2House << "\n";
		cout << "Beans left: " << player2Beans << "\n";
		cout << "Stamina:    ";
		for (int i = 0; i < (player2Stamina / 10); i++)
		{
			cout << " |";
		}
		cout << " : " << player1Stamina << "\n\n";
		break;
	case selectSpell:
		cout << playerName << ", select a spell to cast:\n";
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