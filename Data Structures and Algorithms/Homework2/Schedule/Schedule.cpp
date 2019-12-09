#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r, int t[])
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];
	///////////
	int* tL = new int[n1];
	int* tR = new int[n2];

	for (i = 0; i < n1; i++) {
		L[i] = arr[l + i];
		tL[i] = t[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[m + 1 + j];
		tR[j] = t[m + 1 + j];
	}


	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			t[k] = tL[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			t[k] = tR[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		t[k] = tL[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		t[k] = tR[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}

void mergeSort(int arr[], int l, int r, int t[])
{
	if (l < r)
	{

		int m = l + (r - l) / 2;

		mergeSort(arr, l, m, t);
		mergeSort(arr, m + 1, r, t);

		merge(arr, l, m, r, t);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	int* bi = new int[n];
	int* ti = new int[n];
	int* finish = new int[n];
	for (int i = 0; i<n; i++) {
		cin >> bi[i];
		cin >> ti[i];
		finish[i] = bi[i] + ti[i];
	}

	mergeSort(finish, 0, n - 1, bi);

	int counter = 1;
	int i = 1;
	int now = finish[0];
	while (true) {
		if (finish[i] == finish[0]) {
			i++;
		}
		else {
			break;
		}
	}

	while (i<n) {
		if (bi[i] >= now) {
			if (i < n - 1) {
				while (finish[i] == finish[i + 1] && bi[i] >= now) {
					i++;
					if (i == n - 1)break;
				}
			}
			now = finish[i];
			counter++;
			i++;
		}
		else {
			i++;
		}
	}
	cout << counter << endl;

	return 0;
}
