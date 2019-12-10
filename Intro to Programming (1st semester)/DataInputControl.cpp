// Vhod na danni.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int SafelyInpunInteger(int LowerBound, int UpperBound)
{
	int number;
	do
	{
		cout << "Input a number between ";
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	} while ((number > UpperBound) || (number < LowerBound));
	return number;
}

int main()
{
    return 0;
}

