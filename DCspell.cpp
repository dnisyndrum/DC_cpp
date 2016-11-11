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
//     Methods:
//       
//        properties:
//         
//        Public Methods:
//           
//        Private Properties:
//            
//-----------------------------------------------------------------------------
#include "DCspells.h"
#include "DCplayer.h"
#include <cstdlib> 

using namespace std;

//causes damage
bool DCspells::castRictusempra(DCplayer* thisPlayer, DCplayer* player2)
{
	if (hit())
	{
		player2->setStamina(player2->getStamina() - damage(rictusempra));
		return true;
	}
	else 
	{
		return false;
	}
}

//more damage
bool DCspells::castConfringo(DCplayer* thisPlayer, DCplayer* player2)
{
	if (hit())
	{
		player2->setStamina(player2->getStamina() - damage(confringo));
		return true;
	}
	else
	{
		return false;
	}
}

//lose next turn, no damage
bool DCspells::castLocomotorMortis(DCplayer* thisPlayer, DCplayer* player2)
{
	if (hit())
	{
		player2->setIsMyTurn(false);
		return true;
	}
	else
	{
		return false;
	}
}

//damage, opponent next spell half power
bool DCspells::castStupify(DCplayer* thisPlayer, DCplayer* player2)
{
	if (hit())
	{
		player2->setStamina(player2->getStamina() - damage(stupify));
		return true;
	}
	else
	{
		return false;
	}
}

//tongue tied next turn
bool DCspells::castMimblewimble(DCplayer* thisPlayer, DCplayer* player2)
{
	if (hit())
	{
		player2->setStamina(player2->getStamina() - damage(mimblewimble));
		player2->setTongueTied(true);
		return true;
	}
	else
	{
		return false;
	}
}



//damage, opponent lose next turn
bool DCspells::castExpelliarmus(DCplayer* thisPlayer, DCplayer* player2)
{
	if (hit())
	{
		player2->setStamina(player2->getStamina() - damage(expelliarmus));
		player2->setIsMyTurn(false);
		return true;
	}
	else
	{
		return false;
	}
}

bool DCspells::drinkWiggenweld(DCplayer* thisPlayer)
{
	int stamina = thisPlayer->getStamina();
	int numPotions = thisPlayer->getNumWiggenwelds();
	thisPlayer->setStamina(stamina += 15);
	thisPlayer->setNumWiggenwelds(numPotions -= 1);
	return true;
}

bool DCspells::hit()
{
	const int MIN = 1;
	const int MAX = 100;
	const int CUTOFF = 66;
	int spellHit = (rand() % MAX) + MIN;

	if (spellHit < CUTOFF) { return true; }
	else { return false; }
}

int DCspells::damage(spell spellUsed)
{
	const int SPELL_MIN = 5;
	const int RICTUS_MAX = 10;
	const int CONFRINGO_MAX = 15;
	const int STUP_MAX = 6;
	const int EXPEL_MAX = 7;
	const int MIMBLE_MAX = 6;
	int spellDamage;

	switch (spellUsed)
	{
	case rictusempra:
		spellDamage = (rand() % RICTUS_MAX) + SPELL_MIN;
		break;
	case confringo:
		spellDamage = (rand() % CONFRINGO_MAX) + SPELL_MIN;
		break;
	case stupify:
		spellDamage = (rand() % STUP_MAX) + SPELL_MIN;
		break;
	case expelliarmus:
		spellDamage = (rand() % EXPEL_MAX) + SPELL_MIN;
		break;
	case mimblewimble:
		spellDamage = (rand() % MIMBLE_MAX) + SPELL_MIN;
		break;
	default:
		spellDamage = (rand() % MIMBLE_MAX) + SPELL_MIN;
		break;
	}
	if (halfDamage) 
	{
		spellDamage /= 2;
	}
	halfDamage = false;
	return spellDamage;
}


