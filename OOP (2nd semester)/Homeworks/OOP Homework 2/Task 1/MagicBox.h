#pragma once
#include <iostream>
//#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
using namespace std;

template<class T>
class MagicBox {
private:

	T* arr; //works for: int , char , Rational

	int capacity; // space in the array

	int size; // number of elemets in the array

public:
	
	MagicBox();

	~MagicBox();

	void resize();

	void insert();

	void pop();

	void list();

};

template<typename T>
MagicBox<T>::MagicBox()
{
	arr = new T[2];
	capacity = 2;
	size = 0;
}

template<class T>
MagicBox<T>::~MagicBox()
{
	delete[] arr;
}

template<class T>
void MagicBox<T>::resize()
{
	T* arr2 = new T[capacity * 2];
	for (int i = 0; i <= size; i++)
	{
		arr2[i] = arr[i];
	}
	delete[] arr;
	arr = new T[capacity * 2];
	for (int i = 0; i <= size; i++)
	{
		arr[i] = arr2[i];
	}
	delete[] arr2;
	capacity *= 2;
}

template<class T>
void MagicBox<T>::insert()
{
	if (capacity == size+1)resize();
	T a;
	cin >> a;
	arr[size++] = a;
}

template<class T>
void MagicBox<T>::pop()
{
	if (size == 0)return;
	srand(time(0));
	int r = rand() % size;
	for (int i = r; i < size; i++)
	{
		arr[i] = arr[i + 1];
	}
	size--;
}

template<class T>
void MagicBox<T>::list()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////

class Rational {
private:

	int numer, denom;

public:

	friend ostream& operator<<(ostream&, const Rational&);

	friend istream& operator>>(istream&,  Rational&);

	Rational& operator= (const Rational&);

};

ostream & operator <<(ostream & os, const Rational & r)
{
	os << r.numer << "/" << r.denom;
	return os;
}

istream & operator >> (istream & os, Rational & r)
{
	os >> r.numer;
	cin.ignore();
	os >> r.denom;
	return os;
}

Rational & Rational::operator=(const Rational & r)
{
	this->denom = r.denom;
	this->numer = r.numer;
	return *this;
}