/**
*
* Solution to homework task 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Georgi Demirev
* @idnumber 62296
* @task 3
* @compiler VC
*
*/
#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int operator_1;
	int operator_2;
	int operation;
	cout << "Enter two numbers between 0 and 15 and one number between 0 and 3 for chosing one of the operations:" << endl
		<< "0 - addition" << endl
		<< "1 - subtraction" << endl
		<< "2 - multiplication" << endl
		<< "3 - division" << endl;
	cin >> operator_1 >> operator_2 >> operation;
	bool wrong_input = operator_1 < 0 || operator_1>15 ||
		operator_2 < 0 || operator_2 >15 || operation > 3 ||
		operation < 0 || (operation == 3 && operator_2 == 0);
	if (wrong_input)cout << "Wrong input" << endl;
	else
	{
		switch (operation)
		{
		case 0:cout << (operator_1 + operator_2) % 16 << endl; break;
		case 1:cout << ((operator_1 - operator_2) + 16) % 16 << endl; break; //Dobavqm 16 zashtoto moje da stane otricatelno i suotvetno otgovora sushto otricatelen.
		case 2:cout << (operator_1 * operator_2) % 16 << endl; break;		// Dobavqneto na 16 ne promenq otgovora!
		case 3:cout << (operator_1 / operator_2) % 16 << endl; break;      // Celochisleno delenie
		}
	}
	return 0;
}
