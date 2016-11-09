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
		lastSpellHit = true;
		player2->setStamina(player2->getStamina() - damage(rictusempra));
		return true;
	}
	else 
	{
		lastSpellHit = false;
		return false;
	}
}

//more damage
bool DCspells::castConfringo(DCplayer* thisPlayer, DCplayer* player2)
{
	if (hit())
	{
		lastSpellHit = true;
		player2->setStamina(player2->getStamina() - damage(confringo));
		return true;
	}
	else
	{
		lastSpellHit = false;
		return false;
	}
}

//lose next turn, no damage
bool DCspells::castLocomotorMortis(DCplayer* thisPlayer, DCplayer* player2)
{
	if (hit())
	{
		lastSpellHit = true;
		player2->setIsMyTurn(false);
		return true;
	}
	else
	{
		lastSpellHit = false;
		return false;
	}
}

//damage, opponent next spell half power
bool DCspells::castStupify(DCplayer* thisPlayer, DCplayer* player2)
{
	if (hit())
	{
		lastSpellHit = true;
		player2->setStamina(player2->getStamina() - damage(stupify));
		return true;
	}
	else
	{
		lastSpellHit = false;
		return false;
	}
}

//tongue tied next turn
bool DCspells::castMimblewimble(DCplayer* thisPlayer, DCplayer* player2)
{
	if (hit())
	{
		lastSpellHit = true;
		player2->setTongueTied(true);
		return true;
	}
	else
	{
		lastSpellHit = false;
		return false;
	}
}

//rebound last spell
bool DCspells::castProtego(DCplayer* thisPlayer, DCplayer* player2)
{
	if (hit())
	{
		lastSpellHit = true;
		int thisPlayerStamina = thisPlayer->getStamina();
		int player2Stamina = player2->getStamina();
		switch (lastSpell)
		{
		case rictusempra:
			thisPlayer->setStamina(thisPlayerStamina += lastSpellDamage);
			player2->setStamina(player2Stamina -= lastSpellDamage);
			break;
		case confringo:
			thisPlayer->setStamina(thisPlayerStamina += lastSpellDamage);
			player2->setStamina(player2Stamina -= lastSpellDamage);
			break;
		case locomotorMortis:

			break;
		case stupify:

			break;
		case mimblewimble:

			break;
		case protego:
			
			break;
		case expelliarmus:

			break;
		}
		return true;
	}
	else
	{
		lastSpellHit = false;
		return false;
	}
}

//damage, opponent lose next turn
bool DCspells::castExpelliarmus(DCplayer* thisPlayer, DCplayer* player2)
{
	if (hit())
	{
		lastSpellHit = true;
		player2->setStamina(player2->getStamina() - damage(expelliarmus));
		player2->setIsMyTurn(false);
		return true;
	}
	else
	{
		lastSpellHit = false;
		return false;
	}
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
	const int SPELL_MIN = 1;
	const int RICTUS_MAX = 10;
	const int CONFRINGO_MAX = 15;
	const int STUP_MAX = 6;
	const int EXPEL_MAX = 7;
	int spellDamage;

	switch (spellUsed)
	{
	case rictusempra:
		lastSpellDamage = spellDamage = (rand() % RICTUS_MAX) + SPELL_MIN;
		break;
	case confringo:
		lastSpellDamage = spellDamage = (rand() % CONFRINGO_MAX) + SPELL_MIN;
		break;
	case stupify:
		lastSpellDamage = spellDamage = (rand() % STUP_MAX) + SPELL_MIN;
		break;
	case expelliarmus:
		lastSpellDamage = spellDamage = (rand() % EXPEL_MAX) + SPELL_MIN;
		break;
	}
	if (halfDamage) 
	{
		lastSpellDamage = spellDamage /= 2;
	}
	halfDamage = false;
	return spellDamage;
}


