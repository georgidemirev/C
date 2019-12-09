// Darts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

int oneArrow(int n) { // one shot
	int counter = 0;
	for (int i = 1; i <= 21; i++)
	{
		if (i > n) break;
		if (i == 21) i = 25;
		if (2 * i == n) {
			counter++;
		}
	}
	return counter; 
}

int twoArrows(int n) { // two shots
	int counter = 0;
	for (int i = 0; i <= 21; i++) {
		if (i > n)break;
		for (int t = 1; t <= 21; t++) {
			if (i + 2*t > n)break;
			if (i == 21) i = 25;
			if (t == 21) t = 25;
			if ((i + 2 * t == n)
				|| (2 * i + 2 * t == n)
				|| (3 * i + 2 * t == n && i <= 20))
			{
				counter++;
			}
		}
	}
	return counter;
}

int threeArrows(int n) {
	int counter = 0;
	for (int i = 0; i <= 21; i++)
	{
		if (i > n)break;
		for (int t = 0; t <= 21; t++)
		{
			if (i + t > n)break;
			for (int p = 1; p <= 21; p++)
			{
				if (i + t + 2*p > n)break;
				if (i == 21) i = 25;
				if (t == 21) t = 25;
				if (p == 21) p = 25;

				if (i + t + 2 * p == n)
				{
					counter++;
				}
				if ((i + 2 * t + 2 * p == n) && t != 0)
				{
					counter++;
				}
				if ((i + 3 * t + 2 * p == n) && t != 0 && t <= 20)
				{
					counter++;
				}
				if ((2 * i + t + 2 * p == n) && i != 0)
				{
					counter++;
				}
				if ((2 * i + 2 * t + 2 * p == n) && i != 0 && t != 0)
				{
					counter++;
				}
				if ((2 * i + 3 * t + 2 * p == n) && i != 0 && t != 0 && t <= 20)
				{
					counter++;
				}
				if ((3 * i + t + 2 * p == n) && i != 0 && i <= 20)
				{
					counter++;
				}
				if ((3 * i + 2 * t + 2 * p == n) && i != 0 && t != 0 && i <= 20)
				{
					counter++;
				}
				if ((3 * i + 3 * t + 2 * p == n) && i != 0 && t != 0 && i <= 20 && t <= 20)
				{
					counter++;
				}

			}
		}
	}
	return counter;
}

int main() {
	int counter = 0;
	int n;
	cin >> n;
	if (n <= 1 || n > 170) {
		cout << 0 << endl;
		return 0;
	}
	counter += oneArrow(n);
	counter += twoArrows(n);
	counter += threeArrows(n);

	cout << counter << endl;;
	return 0;
}