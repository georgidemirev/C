/**
*
* Solution to homework task 5
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Georgi Demirev
* @idnumber 62296
* @task 5
* @compiler VC
*
*/
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	double x, y;
	cout << "Enter x and y for coordinates." << endl;
	cin >> x >> y;
	bool undefined = ((x*x + (y - 3)*(y - 3) == 1) && (y > 0)) ||
		((x*x + (y + 3)*(y + 3) == 1) && (y < 0)) ||
		((x*x + (y - 3)*(y - 3) == 9) && x >= 0) ||
		((x*x + (y + 3)*(y + 3) == 9) && x <= 0) ||
		(x*x + y*y == 36);
	bool outside = (x*x + y*y > 36);
	bool black = (((x*x + (y - 3)*(y - 3) < 1) && y > 0) ||   //Nqma nujda da maham sluchaq kogato e border ili outside zashtoto gi podrejdam s else if.
		((x*x + (y - 3)*(y - 3) > 9) && x >= 0) ||			  // Trqbva da se mahne sluchaq kogato e white!
		((x*x + (y + 3)*(y + 3) < 9) && x <= 0) ||
		((x*x + (y + 3)*(y + 3) > 9) && x >= 0 && y<0)) &&
		(x*x + (y + 3)*(y + 3) > 1);					//Tuk maham white koito vliza v black.
	if (undefined)cout << "Undefined" << endl;
	else if (outside)cout << "Outside" << endl;
	else if (black)cout << "Black" << endl;
	else cout << "White" << endl;
	return 0;
}
