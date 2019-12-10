// Task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Users.h"
using namespace std;

int main()
{
	Admin user1("123.123", "Georgi", "Pass1", "Title1" ,0);
	PowerUser user3("111.111", "User3", "Pass3", "Title3", 0);
	user1.changePass("Pass1","PassUser1");
	Admin user2(user1);
	user2.changePass("PassUser1", "PassUser2");
	user2.setUs("User 2");
	user2.changeOtherUsername( user3 , "User 3 after changing from user 1");
	cout << user2.getUs() << endl << user3.getUs() << endl << "-----------------\n";// cout
	user1.giveReputation(user2);
	cout << user2.getRep() << endl;//cout

	return 0;
}

