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
	DCspells(){};
	
	void castRictusempra(DCplayer*, DCplayer*);
	void castConfringo(DCplayer*, DCplayer*);
	void castLocomotorMortis(DCplayer*, DCplayer*);
	void castStupify(DCplayer*, DCplayer*);
	void castMimblewimble(DCplayer*, DCplayer*);
	void castProtego(DCplayer*, DCplayer*);
	void castExpelliarmus(DCplayer*, DCplayer*);
	
private:
	bool hit();
	int damage(spell);

};
#endif