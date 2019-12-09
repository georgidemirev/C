// Permutations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

void merge(char arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	////
	char* L = new char[n1 + 1];
	char* R = new char[n2 + 1];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	///
	R[n2] = '\0';
	L[n1] = '\0';

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}


	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] R;
	delete[] L;

}

void mergeSort(char arr[], int l, int r)
{
	if (l < r)
	{

		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

int main()
{
	int n; cin >> n;
	if (n < 0 || n > 150 * pow(10, 6)) {
		return 0;
	}
	///
	char* a1 = new char[n + 1];
	char* arr1 = new char[n + 1];
	cin >> a1;
	for (int i = 0; i < n; i++) {
		arr1[i] = a1[i];
	}
	arr1[n] = '\0';
	///
	char* a2 = new char[n + 1];
	char* arr2 = new char[n + 1];
	cin >> a2;
	for (int i = 0; i < n; i++) {
		arr2[i] = a2[i];
	}
	arr2[n] = '\0';

	mergeSort(arr1, 0, n - 1);
	mergeSort(arr2, 0, n - 1);

	bool check = true;
	for (int i = 0; i < n; i++) {
		if (arr1[i] != arr2[i])check = false;
	}
	if (check) {
		cout << "yes";
	}
	else {
		cout << "no";
	}
	return 0;
}

