// OOP2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Store.h"
#include "Monitor.h"

using namespace std;

int main()
{
	Vector<Product> vector;

	User user("username", "password", 1);
	//vector.push_back(user);
	//vector.push_back(user);

	//Product product1("username", "password", 1, 1);
	Monitor product1("name", "description", 1, 2, 3, "180x120");
	Monitor product2("name1", "description", 1, 2, 3, "180x120");

	//Product product2("username1", "password", 1, 1);
	vector.push_back(product1);
	vector.push_back(product2);

	bool a = vector.at(0) == vector.at(1);

	cout << a << endl;

	//vector.remove(product2);
	//vector.remove(product1);

	cout << vector.at(1).getCategory() << endl;


	//vector.clear();

	//cout << vector.at(0).getPassword() << endl;
	//cout << vector.at(0).getWallet().getMoney() << endl;
	//cout << vector.at(0).getMoneyInWallet() << endl;

	//vector.clear();


	//Monitor product("name", "description", 1, 2, 3, "180x120");
	//Monitor product2 = product;

	//cout << product2.getCategory() << endl;

	return 0;
}