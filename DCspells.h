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


using namespace std;

#ifndef DCSPELLS_H
#define DCSPELLS_H

class DCplayer;

class DCspells
{
public:
	enum spell{
		rictusempra,
		confringo,
		locomotorMortis,
		stupify,
		mimblewimble,
		expelliarmus,
		wiggenweld,
		none
	};

	enum badSpell{
		rictusrictus,
		emprarictus,
		rictusemprara,
		cafrigo,
		fringo,
		confreako,
		locococomotos,
		locolocomoto,
		locomotormortmort,
		stopmify,
		stupstupfy,
		stupfy,
		mimblywimbly,
		wimblemimble,
		wiblemible,
		protogo,
		pretoga,
		protoga,
		expeleramus,
		expelliamus,
		expellaratus
	};

	//constructor
	DCspells()
	{ 
		halfDamage = false; 
		tongueTwist = false; 
	}
	
	bool castRictusempra(DCplayer*, DCplayer*);
	bool castConfringo(DCplayer*, DCplayer*);
	bool castLocomotorMortis(DCplayer*, DCplayer*);
	bool castStupify(DCplayer*, DCplayer*);
	bool castMimblewimble(DCplayer*, DCplayer*);
	bool castProtego(DCplayer*, DCplayer*);
	bool castExpelliarmus(DCplayer*, DCplayer*);
	bool drinkWiggenweld(DCplayer*);
	
	void resetStupifyEffect(){ halfDamage = false; }
	void resetTongueTwist() { tongueTwist = false; }

private:
	bool hit();
	int damage(spell);

	bool halfDamage;
	bool tongueTwist;
	
};
#endif