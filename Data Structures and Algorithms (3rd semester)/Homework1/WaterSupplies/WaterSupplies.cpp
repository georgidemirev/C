// WaterSupplies.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;
	if (n <= 0 || n> 100000) {
		return 0;
	}
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		arr.push_back(p);
	}
	int s = 0;
	for (int i = 0; i < n-1; i++) {
		int wall = arr.at(i);
		for (int t = i+1; t < n; t++) {
			int area = 0;
			if (wall <= arr.at(t)) {
				area = wall*(t-i);
			}
			else {
				area = arr.at(t) * (t-i);
			}
			if (area > s) {
				s = area;
			}
		}
	}
	cout << s << endl;
    return 0;
}

