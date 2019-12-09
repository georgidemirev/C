#include <iostream>
#include "DNSRecord.h"
#include "DNSCache.h"
using namespace std;

void printMenu() {
	cout << "		             ________" << endl;
	cout << "		|------------| MENU |-------------|" << endl;
	cout << "		|To run Add, write 'A'.           |" << endl;
	cout << "		|To run Flush, write 'F'.         |" << endl;
	cout << "		|To run Lookup, write 'L'.        |" << endl;
	cout << "		|To run Print, write 'P'.         |" << endl;
	cout << "		|To close the program, write 'X'. |" << endl;
	cout << "		|---------------------------------|" << endl;
	cout << "		|Please be correct with input. :) |" << endl;
	cout << "		|---------------------------------|" << endl;
}

int main()
{
	DNSCache cache;
	printMenu();
	char a='\0';
	do {
		cin >> a;
		switch (a) {
		case 'A': {
			char* c = new char[30];// for this task we do not need more than 30 characters
			cout << "Write the domain name: ";
			cin >> c;
			char* b = new char[30];
			cout << "Write the IP address: ";
			cin >> b;
			cache.add(DNSRecord(c, b));
		}; break;
		case'F': {
			cache.flush();
		}; break;
		case 'L': {
			cout << "Write domain name: ";
			char* name = new char[30];
			cin >> name;
			cout <<"The IP of that domain name is: "<< cache.lookup(name)<<endl;
		}; break;
		case 'P': {
			cache.print();
		}; break;
		case 'X': {
			return 0;
		};
		default: cout << "Wrong input"<<endl;
		}
	} while (a != 'X');

	return 0;
}