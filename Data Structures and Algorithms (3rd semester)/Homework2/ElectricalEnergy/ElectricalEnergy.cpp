// ElectricalEnergy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
/*
int main() {
	int n; cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	int* arr = new int[n];
	for (int i = 0; i<n; i++) {
		cin >> arr[i];
	}
	int* counter = new int[n];
	counter[0] = 0;
	for (int i = 1; i<n; i++) {
		for (int t = 0; t <= i; t++) {
			if (arr[i] < arr[i - 1 - t]) {
				counter[i]++;
			}
		}
	}
	int result = 0;
	for (int i = 0; i<n; i++) {
		result += counter[i];
	}
	cout << result;
	return 0;
}*/

void merge(int arr[], int low, int mid, int high, int* counter) {
	int i = 0, j = 0, k = low;
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int* left = new int[n1];
	int* right = new int[n2];
	for (int i = 0; i<n1; i++) {
		left[i] = arr[low + i];
	}
	for (int i = 0; i<n2; i++) {
		right[i] = arr[mid + 1 + i];
	}
	i = 0;
	while (i < n1 && j < n2) {
		if (left[i] <= right[j]) {
			arr[k++] = left[i++];
		}
		else
		{
			arr[k++] = right[j++];
			*counter += n1 - i;
		}
	}
	while (i<n1) {
		arr[k++] = left[i++];
	}
	while (j<n2) {
		arr[k++] = right[j++];
	}
	delete[] left;
	delete[] right;
}

void mergeCountSortCrazyStuff(int arr[], int low, int high, int* counter) {
	if (low < high) {
		int mid = low + (high - low) / 2;

		mergeCountSortCrazyStuff(arr, low, mid, counter);
		mergeCountSortCrazyStuff(arr, mid + 1, high, counter);

		merge(arr, low, mid, high, counter);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	cin >> n;
	if (n <= 0) {
		cout << 0;
		return 0;
	}
	int* arr = new int[n];
	for (int i = 0; i<n; i++) {
		cin >> arr[i];
		if (arr[i] < 0) return 0;
	}
	int counter = 0;
	mergeCountSortCrazyStuff(arr, 0, n - 1, &counter);
	cout << counter;

	return 0;
}

