#include "stdafx.h"
#include "Fridge.h"
#include <iostream>

using namespace std;

Fridge::Fridge(string const name, string const category, int const quantity,
	double const price, double const height, double const watConsumption)
	: Product(name, category, quantity, price), height(height), watConsumption(watConsumption) {}

Fridge::~Fridge() {};

Fridge::Fridge(const Fridge &other) : Product(other),
height(other.getHeight()), watConsumption(other.getWatConsumption()) {};

Fridge& Fridge::operator=(const Fridge& other)
{
	this->height = other.getHeight();
	this->watConsumption = other.getWatConsumption();
	Product::operator=(other);
	return *this;
};

double Fridge::getHeight() const
{
	return this->height;
}

double Fridge::getWatConsumption() const
{
	return this->watConsumption;
}

void Fridge::print() const
{
	Product::print();
	cout << ", height: " << height << ", watConsumption: " << watConsumption;
}