// CloningSocks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool checkIfPossible(int n, int m) {
	if (m < 1) {
		return 0;
	}
	//if (n == 0 && m == 0)return 1;
	if (m>n && m == n + 1) {
		return 1;
	}
	if (m>1&&n > m && (n - m) % 2 == 1) {
		return 1;
	}
	return 0;
}

int main()
{
	int t;
	cin >> t;
	if (t < 1 || t>10) {
		return 0;
	}
	vector<bool> arr;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		if (n < 0 || n > 1000000000 || m < 0 || m > 1000000000) {
			return 0;
		}
		arr.push_back(checkIfPossible(n, m));
	}
	for (int i = 0; i < arr.size(); i++) {
		if (arr.at(i) == 0) {
			cout << "no" << endl;
		}
		else {
			cout << "yes" << endl;
		}
	}

    return 0;
}

