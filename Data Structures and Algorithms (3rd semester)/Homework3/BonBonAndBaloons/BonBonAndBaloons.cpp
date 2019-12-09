#include "stdafx.h"
#include <cmath>
#include <iostream>
using namespace std;

bool isPossible(long long* a, long long* b, long long n, long long int mid, long long m) {
	long long usedBaloons = 0;
	for (long long i = 0; i< n; i++) {
		long long counter = a[i] - mid / b[i];
		if (counter > 0) {
			usedBaloons += counter;
		}
		if (usedBaloons > m) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m; cin >> n >> m;
	long long* a = new long long[n];
	long long* b = new long long[n];
	long long* arr = new long long[n];
	long long int max = 0;// try long long int ! // no need 10^18 is maximum 

	for (long long i = 0; i<n; i++) {
		cin >> a[i];
	}
	for (long long i = 0; i<n; i++) {
		cin >> b[i];
		long long check = 0;
		check = a[i] * b[i];
		if (check > max)max = check;
	}

	long long int mid = max / 2;
	long long int min = 0;
	while (min < max) {
		mid = min + (max - min) / 2;
		if (isPossible(a, b, n, mid, m)) {
			max = mid;
		}
		else {
			min = mid + 1;
		}
	}
	cout << min;

	return 0;
}