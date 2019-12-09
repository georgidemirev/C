// Kontrolno 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "header.h"
using namespace std;

int main()
{
	Person a("vanakat", nullptr, 11, 11);
	PersonWithAccount person("Ivan Ivanov", "1234567890" , 21,1998,1234,321,"7418529630");
	person.regToSpotify();
	person.CashOut(10);
	cout << person.PrintBalance() << endl;
	person.Pay(100);
	cout << person.PrintBalance() << endl;
	person.CashIn(1000);
	cout << person.PrintBalance() << endl;
    return 0;
}

