#include "stdafx.h"
#include "Stack.h"

bool IntStack::full() const
{
	return top == size-1;
}

void IntStack::grow()
{
	int* newArr =new int[size];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = new int[size * 2];
	for (int i = 0; i < top+1; i++)
	{
		arr[i] = newArr[i];
	}
	delete[] newArr;
	size *= 2;
}

IntStack::IntStack()
{
	size = 1;
	arr = new int [size];
	top = -1;
}

IntStack::~IntStack()
{
	delete[] arr;
}

IntStack::IntStack(const IntStack & copy)
{
	for (int i = 0; i < top + 1; i++)
	{
		arr[i] = copy.arr[i];
	}
	this->top = copy.top;
	this->size = copy.size;
}

bool IntStack::empty() const
{
	return top == -1 ;
}

void IntStack::push(int p)
{
	if (full())
	{
		grow();
	}
	arr[++top] = p;
}

int IntStack::pop()
{
	if (empty()) {
		cout << "Eror! Trying to pop from empty stack! \n";
		return 0;										
	}
	else return arr[top--];
}

void IntStack::print()
{
	if (empty()) {
		cout << "Eror! Trying to print empty stack! \n";
		return ;							
	}
	else {
		for (int i = top; i >= 0 ; i--)
		{
			cout << arr[i] << endl;
		}
	}
}
