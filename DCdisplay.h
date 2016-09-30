//-----------------------------------------------------------------------------
//   File: Dueling Club
//   Class: DCdisplay.h
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

#ifndef DCDISPLAY_H
#define DCDISPLAY_H

class DCdisplay
{
public:
	//emnumerate each possible state for display output
	enum displayOutput {
		titles1,
		titles2, 
		intro1, 
		intro2, 
		PvPorAI, 
		duelGraphic, 
		rictusempra, 
		mimblewimble, 
		expelliarmus, 
		confringo, 
		locomotorMortis, 
		stupify, 
		protego, 
		win, 
		lose, 
		playAgain, 
		exit, 
		clear,
		badInput,
		selectSpell
	};

	//constructor
	DCdisplay(){};	//default
	DCdisplay(displayOutput display, ostream& sout) : displayScreen(display){};
	
	//displays the next output screen
	void displayNext(displayOutput);

	//set each player's house, stamina, name, and beams
	//for two player
	void setStamina(int player1NewStam, int player2NewStam)
	{
		player1Stamina = player1NewStam;
		player2Stamina = player2NewStam;
	};
	void setName(string player1NewName, string player2NewName)
	{
		player1Name = player1NewName;
		player2Name = player2NewName;
	}
	void setBeans(int player1NewBeans, int player2NewBeans)
	{
		player1Beans = player1NewBeans;
		player2Beans = player2NewBeans;
	}
	void setHouse(string player1NewHouse, string player2NewHouse)
	{
		player1House = player1NewHouse;
		player2House = player2NewHouse;
	}

	//for single player, computer duel
	void setSinglePlayerName(string name)
	{
		playerName = name;
	}

	void setSinglePlayerHouse(string house)
	{
		playerHouse = house;
	}
	void setSinglePlayerBeans(int beans)
	{
		playerBeans = beans;
	}
	void setSinglePlayerStamina(int stamina)
	{
		playerStamina = stamina;
	}

	//destructor
	~DCdisplay(){};
	
private:
	//for DCgame class
	displayOutput displayScreen;
	int player1Stamina;
	int player2Stamina;
	string player1Name;
	string player2Name;
	string player1House;
	string player2House;
	int player1Beans;
	int player2Beans;

	//for DCplayer class
	string playerName;
	int playerStamina;
	int playerBeans;
	string playerHouse;
	
};
#endif

