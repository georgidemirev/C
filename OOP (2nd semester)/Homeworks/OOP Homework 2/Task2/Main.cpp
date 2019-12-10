// Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "GameCharacters.h"
using namespace std;

int main()
{
	Warrior warrior;
	warrior.print();
	warrior.getattacked(10);
	warrior.print();
    return 0;
}

