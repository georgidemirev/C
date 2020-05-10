#include "stdafx.h"

#include "Product.h"
#include <iostream>
using namespace std;


// This class stores all types of product, because where we need one type of product,
// there we need other types also.


// Implementation for Product

Product::Product() :name("default"), category("default"), quantity(0), price(0) {};

Product::Product(char* const name, char* const category, int const quantity, double const price) :
	name(name), category(category), quantity(quantity), price(price) {};

Product::~Product() {
};

Product::Product(const Product &other) :
	name(other.getName()), category(other.getCategory()),
	quantity(other.getQuantity()), price(other.getPrice()) {};

Product& Product::operator=(const Product& other)
{
	this->name = other.getName();
	this->category = other.getCategory();
	this->quantity = other.getQuantity();
	this->price = other.getPrice();
	return *this;
};

bool Product::operator==(const Product& o1) const// , const Product& o2)
{
	if (this->name == o1.getName())
	{
		return true;
	};
	return false;
};

void Product::print() const
{
	cout << name << ": " << category << ", " << quantity << ", " << price << endl;
}

char* Product::getName() const
{
	return this->name;
}

char* Product::getCategory() const
{
	return this->category;
}

int Product::getQuantity() const
{
	return this->quantity;
}

void Product::setQuantity(int const quantity)
{
	this->quantity = quantity;
}

double Product::getPrice() const
{
	return this->price;
}
