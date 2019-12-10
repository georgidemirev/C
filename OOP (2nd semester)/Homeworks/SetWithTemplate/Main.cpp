// Mnojestva.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Set.h"

using namespace std;

int main()
{
	int b[2] = { 1,2 };

	Set<int> a(b , 2);
	a.insert(55);
	Set<int> c(b, 2);
	c.insert(6);
	c.insert(77);
	Set<int> d;
	d.Union(a, c);

	cout << d.getSet()[6] << endl;
	
    return 0;
}

