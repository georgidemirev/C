/**
*
* Solution to homework task 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Georgi Demirev
* @idnumber 62296
* @task 2
* @compiler VC
*
*/
#include "stdafx.h"
#include <iostream>
using namespace std;
long long int SafelyInpunInteger(long long int LowerBound, long long int UpperBound)
{
	long long int number;
	do
	{
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
	long long int number, n;
	cout << "Enter an integer between -2^32 and 2^32." << endl;
	number = SafelyInpunInteger(-pow(2, 32), pow(2, 32) - 1);
	cout << "Now enter a digit." << endl;
	n = SafelyInpunInteger(0, 9);
	number = abs(number);
	int counter = 0;
	while (number != 0)
	{
		if (number % 10 == n)
		{
			counter++;
		}
		number /= 10;
	}
	if (number == 0 && n == 0)cout << 1 << endl;
	else cout << counter << endl;
	return 0;
}