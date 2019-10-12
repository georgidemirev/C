/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Georgi Demirev
* @idnumber 62296
* @task 1
* @compiler VC
*
*/
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
} // For removing the cursor from the console

int main()
{
	char hello[5][39] = { 'H',' ',' ',' ','H',' ',' ',' ','E','E','E','E','E',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','O',' ',' ',' ',
						  'H',' ',' ',' ','H',' ',' ',' ','E',' ',' ',' ',' ',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ',' ','O',' ',' ',' ','O',' ',
						  'H','H','H','H','H',' ',' ',' ','E','E','E','E','E',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ','O',' ',' ',' ',' ',' ','O',
						  'H',' ',' ',' ','H',' ',' ',' ','E',' ',' ',' ',' ',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ',' ','O',' ',' ',' ','O',' ',
						  'H',' ',' ',' ','H',' ',' ',' ','E','E','E','E','E',' ',' ',' ','L','L','L','L','L',' ',' ',' ','L','L','L','L','L',' ',' ',' ',' ',' ',' ','O',' ',' ',' ' };
	int t = 1;
	Sleep(300);
	ShowConsoleCursor(false);// For removing the cursor from the console
	while (t <= 38)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << endl;
		}
		for (int i = t; i >= 0; i--)
		{
			cout << hello[0][38 - i];
		}
		cout << endl;
		for (int i = t; i >= 0; i--)
		{
			cout << hello[1][38 - i];
		}
		cout << endl;
		for (int i = t; i >= 0; i--)
		{
			cout << hello[2][38 - i];
		}
		cout << endl;
		for (int i = t; i >= 0; i--)
		{
			cout << hello[3][38 - i];
		}
		cout << endl;
		for (int i = t; i >= 0; i--)
		{
			cout << hello[4][38 - i];
		}
		for (int i = 0; i < 10; i++)
		{
			cout << endl;
		}
		Sleep(20);
		system("cls");
		t++;
	}
	for (int i = 0; i < 40; i++)
	{
		for (int m = 0; m < 10; m++)
		{
			cout << endl;
		}
		for (int t = 0; t < 5; t++)
		{
			for (int z = 0; z <= i; z++)cout << " ";
			for (int q = 0; q < 39 ; q++)
			{
				cout << hello[t][q];
			}
			cout << endl;
		}
		for (int m = 0; m < 9; m++)
		{
			cout << endl;
		}
		Sleep(20);
		system("cls");
	}
	t = 0;
	while (t <= 38)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << endl;
		}
		for (int z = 0; z <= 40+t; z++)cout << " ";
		for (int i = t; i < 39; i++)
		{
			cout << hello[0][i-t];
		}
		cout << endl;
		for (int z = 0; z <= 40 + t; z++)cout << " ";
		for (int i = t; i < 39; i++)
		{
			cout << hello[1][i - t];
		}
		cout << endl;
		for (int z = 0; z <= 40 + t; z++)cout << " ";
		for (int i = t; i < 39; i++)
		{
			cout << hello[2][i - t];
		}
		cout << endl;
		for (int z = 0; z <= 40 + t; z++)cout << " ";
		for (int i = t; i < 39; i++)
		{
			cout << hello[3][i - t];
		}
		cout << endl;
		for (int z = 0; z <= 40 + t; z++)cout << " ";
		for (int i = t; i < 39; i++)
		{
			cout << hello[4][i - t];
		}
		for (int i = 0; i < 10; i++)
		{
			cout << endl;
		}
		Sleep(20);
		system("cls");
		t++;
	}
    return 0;
}

