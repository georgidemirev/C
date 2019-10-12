#pragma once
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class IntStack {
private:
	int* arr; // elementite na steka
	int top;  // indeksa na posledniq element
	int size; // razmer na masiva ot elementi

	bool full() const;

	bool empty() const;

	void grow();
public:
	IntStack();
	
	~IntStack();

	IntStack(const IntStack&);

	void push(int);

	int pop();
	
	void print();

	friend IntStack& sortStack(IntStack&);
};
#endif