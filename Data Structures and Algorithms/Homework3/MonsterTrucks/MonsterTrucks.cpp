#include "stdafx.h"
#include <cmath>
#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int* k = new int[n];
	int* m = new int[n];
	for (int i = 0; i<n; i++) {
		cin >> k[i] >> m[i];
	}
	int max = -100000, min = 100000;
	for (int i = 0; i<n; i++) {
		if (k[i] > max)max = k[i];
		if (k[i] < min)min = k[i];
	}
	int monsters = 1000000000;
	while (min <= max) {
		int checker = 0;
		for (int i = 0; i<n; i++) {
			checker += abs(min - k[i]) * m[i];
		}
		if (checker < monsters) {
			monsters = checker;
		}
		min++;
	}
	cout << monsters;

	return 0;
}
