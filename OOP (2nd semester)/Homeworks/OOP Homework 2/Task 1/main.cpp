#include "stdafx.h"
#include <iostream>
#include "MagicBox.h"
using namespace std;



int main()
{
	//MagicBox<int> a;
	MagicBox<Rational> a;
	a.insert();
	a.insert();
	a.insert();
	a.insert();
	a.list();
	a.pop();
	a.list();
	a.insert();
	a.list();

	return 0;
}

