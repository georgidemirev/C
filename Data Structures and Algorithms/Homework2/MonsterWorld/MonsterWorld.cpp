// MonsterWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int getMax(int arr[], int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max)max = arr[i];
	}
	return max;
}

int main()
{
	int n, x;
	cin >> n >> x;

	int counter = 0;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int max = getMax(arr, n);
	bool* count = new bool[max];
	for (int i = 0; i < max; i++) {
		count[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] <= 0)continue;
		count[arr[i] - 1] = true;
	}

	int p = 0;
	for (int i = 1; i < max; i++) {
		if (count[i] > 0) {
			count[i] = 1;
			p++;
		}
	}

	int* index = new int[p];
	p = 0;
	for (int i = 0; i < max; i++) {
		if (count[i] == true) {
			index[p++] = i + 1;
		}
	}

	for (int i = 1; i <= p; i++) {
		if (p == 1) {
			counter++;
			break;
		}
		if (p - 1 - i < 0)break;
		if ((index[p - 1 - i] - i*x) <= 0) {

			counter++;
			break;
		}
		if (p - 1 - i == 0)counter++;
		counter++;
	}
	cout << counter << endl;
	return 0;
}

