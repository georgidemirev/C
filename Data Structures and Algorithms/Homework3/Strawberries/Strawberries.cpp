// Homework3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int binarySearch(long long* arr, int l, int r, long long p) {
	if (r >= l) {
		int mid = l + (r - l) / 2; // 1
		if (mid == 0) {
			if (p <= arr[0])return 1;
			else mid++;
		}
		if (arr[mid] >= p && arr[mid - 1] < p) {
			return mid + 1;
		}
		if (arr[mid - 1] >= p) {
			return binarySearch(arr, l, mid - 1, p);
		}
		if (arr[mid] < p) {
			return binarySearch(arr, mid + 1, r, p);
		}

	}
	return -2;
}

int main() {
	int n; cin >> n;
	long long* a = new long long[n];
	cin >> a[0];
	for (int i = 1; i<n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	int m; cin >> m;
	long long* q = new long long[m];
	for (int i = 0; i<m; i++) {
		cin >> q[i];
	}
	for (int i = 0; i<m; i++) {
		cout << binarySearch(a, 0, n - 1, q[i]) << endl;
	}
	return 0;
}

