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
void DCspells::castRictusempra(DCplayer* thisPlayer, DCplayer* player2)
{
	if (hit())
	{
		player2->setStamina(player2->getStamina() - damage(rictusempra));
	}
}

//more damage
void DCspells::castConfringo(DCplayer* thisPlayer, DCplayer* player2)
{

}

//lose next turn, no damage
void DCspells::castLocomotorMortis(DCplayer* thisPlayer, DCplayer* player2)
{

}

//damage, opponent next spell half power
void DCspells::castStupify(DCplayer* thisPlayer, DCplayer* player2)
{

}

//tongue tied next turn
void DCspells::castMimblewimble(DCplayer* thisPlayer, DCplayer* player2)
{

}

//rebound last spell
void DCspells::castProtego(DCplayer* thisPlayer, DCplayer* player2)
{

}

//damage, opponent lose next turn
void DCspells::castExpelliarmus(DCplayer* thisPlayer, DCplayer* player2)
{

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
	}
	return spellDamage;
}


