/**
*
* Solution to homework task 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Georgi Demirev
* @idnumber 62296
* @task 1
* @compiler VC
*
*/
#include "stdafx.h"
#include <iostream>
#include <limits>
using namespace std;
int main()
{
	short number; //short - becouse in the taks, the number is said to be up to 2^16.
	int counter = 0;
	int min = 65535; // minimum value , 2^16 ,( max of short)
	int max = -1; //maximum value
	do
	{
		cin >> number;
		if (number > max)
		{
			max = number;
		}
		if (number<min && number > 0)
		{
			min = number;
		}
		counter++;
	} while (number >= 0);

	if (counter < 3)
	{
		cout << "Eror: You have entered less than two positive integers or bigger integer than 2^16 !" << endl;
	}
	else
	{
		cout << abs(min - max) << endl;
	}
	return 0;
}