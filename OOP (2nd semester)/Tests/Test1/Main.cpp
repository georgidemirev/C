// Kontrolna1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	WebPage first1("http/....", "100.010.001");// By default, the first webpage in the browser.
	Browser example(first1, 0);
	example.add();
	example.add();
	example.print(3); // 3 because the pages are 3;
	// the first page is made by default , the second and the third are from the user 
	// they all are stored in Browser example
	

	
    return 0;
}

