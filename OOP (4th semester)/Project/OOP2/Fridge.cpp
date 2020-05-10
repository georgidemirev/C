#include "stdafx.h"
#include "Fridge.h"

Fridge::Fridge(char* const name, char* const category, int const quantity,
	double const price, double const height, double const watComwatConsumptionsumption)
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
