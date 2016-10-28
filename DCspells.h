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
		protego,
		expelliarmus
	};

	//constructor
	DCspells(){ halfDamage = false; }
	
	bool castRictusempra(DCplayer*, DCplayer*);
	bool castConfringo(DCplayer*, DCplayer*);
	bool castLocomotorMortis(DCplayer*, DCplayer*);
	bool castStupify(DCplayer*, DCplayer*);
	bool castMimblewimble(DCplayer*, DCplayer*);
	bool castProtego(DCplayer*, DCplayer*);
	bool castExpelliarmus(DCplayer*, DCplayer*);
	
	void resetStupifyEffect(){ halfDamage = false; }

private:
	bool hit();
	int damage(spell);

	bool halfDamage;
};
#endif