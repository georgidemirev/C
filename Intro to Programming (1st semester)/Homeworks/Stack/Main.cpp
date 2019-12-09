#include "stdafx.h"
#include <iostream>
#include "Stack.h"
using namespace std;

void swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

void sortArr(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
} // sort an array

IntStack& sortStack(IntStack& a){  
	if (a.empty()) {
		cout << "Eror! Trying to sort an empty stack! \n";
	}
	sortArr(a.arr, (a.top) + 1);
	return a;
}

void printMenu() {
	cout << "		                   ________" << endl;
	cout << "		|------------------| MENU |------------------|" << endl;
	cout << "		|To add element to the stack, write 'A'.     |" << endl;
	cout << "		|To delete top element, write 'D'.           |" << endl;
	cout << "		|To print the stack, write 'P'.              |" << endl;
	cout << "		|To sort the stack, write 'S'.               |" << endl;
	cout << "		|To sort the stack and print it, write 'F'.  |" << endl;
	cout << "		|To exit the program, write 'X'.             |" << endl;
	cout << "		|--------------------------------------------|" << endl;
	cout << "		|Please be correct with the input. :)        |" << endl;
	cout << "		|--------------------------------------------|" << endl;
}

int main()
{
	IntStack stack;
	char a;
	printMenu();
	do {
		cin >> a;
		switch (a) {
		case 'A': { 
			int b;
			cout << "Now write integer to push in the stack: ";
			cin >> b;
			stack.push(b); 
		}; break;
		case 'S': {
			cout << "Stack sorted\n";
			stack = sortStack(stack);
		}; break;
		case'P': {
			stack.print();
		}; break;
		case 'F': {
			stack = sortStack(stack);
			stack.print();
		}; break;
		case 'D': {
			stack.pop();
		}; break;
		case 'X': {
			return 0;
		};
		default: cout << "Wrong input"<<endl;
		}
	} while (a != 'X');

	return 0;
}

