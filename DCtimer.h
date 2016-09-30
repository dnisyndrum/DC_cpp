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
//        properties:
//         
//        Public Methods:
//           
//        Private Properties:
//            
//-----------------------------------------------------------------------------
#include <iostream>
#include <chrono>
#include <ctime>
#include <time.h>  
using namespace std;

#ifndef DCTIMER_H
#define DCTIMER_H

class DCtimer
{
public:
	DCtimer(){};
	DCtimer(int length) : timerLength(length){};
	void timerWithCount(int length);		//shows countdown
	void timerWithoutCount(int length);		//no countdown shown

private:
	//length of timer, used for delay or countdown between displays
	int timerLength;
};
#endif



