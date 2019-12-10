#pragma once
#ifndef IME_H_
#define IME_H_
#include <iostream>
using namespace std;
//1
int modul(int a, int b)
{
	int c = a - b;
	if (c < 0)c = -c;
	return c;
}
double sqrt_a(double a, double eps)
{
	double x = a;
	double x1 = 0;
	do
	{
		x1 = x;
		x = 0.5*(x + a/x);
	} while (modul(x,x1)>eps);
	return x;
}
//2 
void func (char a[])
{
	int i = 0;
	int sizeofa = 0;
	while (a[i++] != '\0')
	{
		sizeofa++;
	}
	for (int i = 0; i < sizeofa; i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z')a[i] = (a[i] - ('a' - 'A'));
		else if (a[i] >= 'A' && a[i] <= 'Z')a[i] = (a[i] + ('a' - 'A'));
	}
}
//3
void func3(char a[])
{
	int month, day;
	if (strlen(a) != 5 || a[2] != '.' )
	{
		cout << "Wrong input!";
		return;
	}
	month = 10*(a[3]-'0') + a[4]-'0';
	day = 10 * (a[0]-'0') + a[1]-'0';
	if (day < 0 || month > 12 || month < 1) { cout << "Wrong input!"; return; }
	switch (month)
	{
	case 1:case 3:case 5:case 7:case 8 : case 10:case 12:
	{
		if(day>31){ cout << "Wrong input!"; return; }
	}break;
	case 2:
	{
		if(day>29) { cout << "Wrong input!"; return; }
	}break;
	case 4:case 6: case 9:case 11:
	{
		if (day>30) { cout << "Wrong input!"; return; }
	}break;
	}
	cout << "good" << endl;
}
//4
int digit_Pos(long num, int k) // one way of doing it.
{
	int number_digits = 0;
	long copy = num;
	while (copy >= 1)
	{
		number_digits++;
		copy /= 10;
	}
	int answer = 0;
	if (k > number_digits || k <=0)return -1;
	for (int i = 0; i < number_digits - k; i++)
	{
		num /= 10;
	}
	answer = num % 10;
	return answer;
}
//4 po vtori nachin
int digit_Pos2(long num, int k)
{

	int digit_counter = 0;
	long copy = num;
	while (copy >= 1)
	{
		digit_counter++;
		copy /= 10;
	}	if (k > digit_counter || k <= 0)return -1;
	int *arr;
	arr = new int[digit_counter];
	for (int i = digit_counter-1; i >= 0; i--)
	{
		arr[i] = num % 10;
		num /= 10;
	}
	return arr[k-1];
}
//5
bool doExist(char* symbols, char* word)
{
	for (int i = 0; i < strlen(symbols); i++)
	{
		if (symbols[i] == word[0])
		{
			int counter = 0;
			int p = 0;
			for (int j = i; j < strlen(word)+i; j++)
			{
				if (symbols[j] == word[p++])counter++;
			}
			if (counter == strlen(word))return 1;
		}
	}
	return 0;
}
//6
void shift(int *a, int i, int j)
{
	int c = a[i];
	a[i] = a[j];
	a[j] = c;
}
void sort(int *a,int b=4)
{
	int check = a[0];
	for (int i = 0; i < b; i++)
	{
		for (int j = i+1; j < b; j++)
		{
			if (a[i] > a[j])shift(a, i, j);
		}
	}
}
void func6(int *a, int size_a,int *b,int size_b)
{
	int *c;
	c = new int[size_a + size_b];
	int i = 0;
	for (i = 0; i < size_a; i++)
	{
		c[i] = a[i];
	}
	for (int j=0; j < size_b; j++)
	{
		c[i + j] = b[j];
	}
	sort(c, size_a + size_b);
	for (int j = 0; j < size_b+size_a; j++)
	{
		cout << c[j] << endl;;
	}
}
//7
struct point {
	int x; int y;
};
struct line {
	point x;
	point y;
};
void func7(line a, line b)
{
	bool uspuredni = (a.x.x == a.y.x ||
		a.y.x == a.y.y) &&
		(b.x.x == b.y.x ||
		b.y.x == b.y.y); cout << uspuredni << endl;
	if (a.x.x == 0 )cout << "eine" << endl;
}
//8
void figure(int n, int m, char symbol)
{
	if (n > 25 || n < 1 || m>80 || m < 1)return;
	for (int i = 0; i < 25 / 2 - n / 2; i++)cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 40 - m / 2; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < m; j++)
		{
			cout << symbol;
		}
		for (int j = 0; j < 40 - m / 2; j++)
		{
			cout << " ";
		}cout << endl;
	}
	for (int i = 0; i < 25 / 2 - n / 2; i++)cout << endl;
}
//9
void matrix_sum(int n, int *arr)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			cout << arr[i*n + j];
		}cout << endl;
	}

}
// ot minalata godina 1
int* funcc(int *a, int* b, int m)
{
	int *c = new int[m];
	for (int i = 0; i < m; i++)
	{
		c[i] = a[i] * b[i];
	}
	return c;
}
// ot minalata godina 3
bool  numCheck(int num)
{
	if (num < 0)num = -num;
	int arr[10] = {};
	int i = 0;
	int p[10] = {};
	int counter = 0;
	while (num >= 1)
	{
		counter++;
		arr[i] = num % 10;
		num/=10;
	}
	for (int i = 0; i < counter; i++)
	{
		p[arr[i]]++;
	}
	counter = 0;
	for (int i = 0; i < 10; i++)
	{
		if (p[i] > counter)counter = p[i];
	}
	if (counter >= 3)return 1;
	return 0;
}
// ot minalata godina 2
int modul(double a)
{
	if (a < 0)
	{
		return -a;
	}return a;
}
double calc(double a, double b, double eps, long end)
{
	double x0 = a, x1 = b, k = 3;
	double x2 = 0.2*(x0 + x0 / x1);
	do {
		if (k++ > end)
		{
			cout << "greshka " << endl; return -1;
		}
		x0 = x1; x1 = x2;
		x2 = 0.5*(x1+x1/x2);
	} while (modul(x2-x1)>=eps);
	return x2;

}
#endif // !IME_H_