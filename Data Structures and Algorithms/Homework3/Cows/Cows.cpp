
#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;


bool possible(int* arr, int r, int cows, int maxDistance) {
	for (int i = 1; i <= r; i++) {
		//
		if (r - i + 1<cows)break;
		//
		int t = i;
		while (arr[t] - arr[i - 1] < maxDistance) {
			t++;
			if (t>r)break;
		}

		i = t;
		if (t>r)break;
		cows--;
	}
	if (cows <= 0)return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int cows; cin >> cows;
	int* arr = new int[n];
	for (int i = 0; i<n; i++) {
		cin >> arr[i];
	}
	if (n == cows) {
		int counter = arr[1] - arr[0];
		for (int i = 2; i<n; i++) {
			if (arr[i] - arr[i - 1] < counter) {
				counter = arr[i] - arr[i - 1];
			}
		}
		cout << counter;
		return 0;
	}
	sort(arr, arr + n);

	int max = (arr[n - 1] - arr[0]) / (cows - 1);
	int mid = max / 2;
	int min = 0;
	while (min < max) {

		mid = min + (max - min + 1) / 2;
		if (possible(arr, n - 1, cows - 1, mid)) {
			min = mid;
		}
		else {
			if (min + 1 == max) {
				if (possible(arr, n - 1, cows - 1, mid - 1)) {
					break;
				}
			}
			max = mid;
		}
	}
	cout << min << endl;

	return 0;
}
