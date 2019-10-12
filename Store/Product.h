#pragma once
#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
using namespace std;

class Product
{
private:

	int sku;

	char* brand = nullptr;

	char* model = nullptr;

	double price;

	int count;

public:

	Product();
	
	Product(int,char*,char*,double,int);

	Product& operator=(const Product&);

	~Product();
	
	void printP(int)const;
};
#endif // !PRODUCT_H
