// SDA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string pass;
	cin >> pass;
	string cipher = "";

	if (pass.length() == 1) {
		cout << 1 << pass << endl;
	}

	for (int i = 0; i < pass.size() -1 ; i) {
		char checker = pass.at(i);
		int counter = 1;
		do {
			if (i == pass.size() - 1) {
				cipher += to_string(counter) + pass.at(i-1);
				break;
			}

			if (checker != pass.at(++i)) {
				cipher += to_string(counter) + checker;
				if (i == pass.size() - 1 ) {
				cipher += to_string(1) + pass.at(i);
				}
				break;
			}
			else {
				counter++;
			}
		} while (true);
	}
	cout << cipher << endl;

	return 0;
}

