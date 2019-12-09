// MissionSDA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> m >> n;
	if (n <= 0 || m < 0 || n>1000 || m > 1000000) {
		cout << "no" << endl;
		return 0;
	}
	if (n == 0) {
		cout << "yes" << endl;
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p>2000000000) {
			cout << "no" << endl;
			return 0;
		}
		count += p;
	}
	count /= n;
	if (m > count) {
		cout << "no" << endl;
	}
	else {
		cout << "yes" << endl;
	}
	return 0;
}

