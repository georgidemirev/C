/**
*
* Solution to homework task 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Georgi Demirev
* @idnumber 62296
* @task 4
* @compiler VC
*
*/
#include "stdafx.h"
#include <iostream>
using namespace std;
int SafelyInpunInteger(int LowerBound, int UpperBound)
{
	int number;
	do
	{
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Enter an integer between 1 and 13." << endl;
			continue;
		}
	} while ((number > UpperBound) || (number < LowerBound));
	return number;
}

int main()
{
	int size;
	char symbol;
	cout << "Enter an integer between 1 and 13." << endl;
	size = SafelyInpunInteger(1, 13);
	cout << "Please enter ONLY ONE symbol from the keyboard." << endl;
	cin >> symbol; // Must be between 1-13
	for (int i = 1; i < (13 - size); i++) // Za obrazuvane na ramkata 25x80 dobavq novi redove
	{
		cout << endl;
	}
	int numberOfSymbols = 1;
	for (int i = 1; i < size; i++)  // Cikul ot nachaloto do sredata 
	{
		int distance = 40 - i;
		do							// Za praznite mesta
		{
			cout << " ";
			distance--;
		} while (distance > 0);
		int p = numberOfSymbols;
		do							// Za simvolite
		{
			cout << symbol;
			p--;
		} while (p > 0);
		numberOfSymbols += 2;
		cout << endl;
	}
	for (int i = 0; i < size; i++) // Cikul za sled sredata
	{
		int distance = (40 - size) + i;
		do
		{
			cout << " ";
			distance--;
		} while (distance > 0);
		int p = numberOfSymbols;
		do
		{
			cout << symbol;
			p--;
		} while (p > 0);
		numberOfSymbols -= 2;
		cout << endl;
	}
	for (int i = 1; i < (13 - size); i++) // Za obrazuvane na ramka 25x80 dobavq novi redove
	{
		cout << endl;
	}
	return 0;
}
