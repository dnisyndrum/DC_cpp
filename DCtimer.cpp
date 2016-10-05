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
#include "DCtimer.h"
using namespace std;

void DCtimer::timerWithCount(int length)
{
	chrono::steady_clock::time_point endTime = chrono::steady_clock::now() + chrono::seconds(length);
	while ((chrono::steady_clock::now() < endTime) || exitLoop)
	{
		cout << length << "  ";
		_sleep(1000);
		length--;
	}
}

void DCtimer::timerWithoutCount(int length)
{
	chrono::steady_clock::time_point endTime = chrono::steady_clock::now() + chrono::seconds(length);
	while (chrono::steady_clock::now() < endTime) 
	{ /*do nothing*/ }
}


/*
int count = 10;

cout << "begin\n";
chrono::steady_clock::time_point endTime = chrono::steady_clock::now() + chrono::seconds(10);
while (chrono::steady_clock::now() < endTime)
{
cout << count << "  ";
_sleep(1000);
count--;
}
std::cout << "\nend\n";
cin.get();
*/