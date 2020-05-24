#include "stdafx.h"

#include "Product.h"
#include <iostream>
using namespace std;

Product::Product() :name("default"), category("default"), quantity(0), price(0) {};

Product::Product(string const name, string const category, int const quantity, double const price) :
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

bool Product::operator==(const Product& o1) const
{
	if (this->name.compare(o1.getName()) == 0)
	{
		return true;
	};
	return false;
};

void Product::print() const
{
	cout << "name: " << name << ", category: " << category;
	cout << ", quantity: " << quantity << ", price: " << price;
}

string Product::getName() const
{
	return this->name;
}

string Product::getCategory() const
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
