#define _CRTDBG_MAP_ALLOC
#include <cstdlib> // Include necessary libraries for debugging
#include <crtdbg.h> // Ditto
#ifdef _DEBUG // If the program is executed in debug mode (can be changed in VS to Release/Debug)
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) // define new to be debug new
#endif // Debug new shows in which file and on which line the memory leak happened

#include "stdafx.h"
#include "Environment.h"
//#include <crtdbg.h>

void sortEnvironmentByDistanceAnd1stPlayer(Environment& e, Player& p);

int main()// should it be case sensitive ?
{
	cout << "titi" << endl;
}