#pragma once
#ifndef STORE_H
#define STORE_H
#include <iostream>
#include "Product.h"
using namespace std;

class Store
{
public:

	Product* products;

	int size;

	int element;

	void resize();

public:
	Store();
	
	~Store();

	void addProduct(const Product&);

	void removeProduct(int);

	void changeProduct(int, const Product&);

	void printStore()const;

	int getElement() {return element;};
};
#endif // !STORE_H
