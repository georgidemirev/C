#include "stdafx.h"
#include "Monitor.h"

Monitor::Monitor(char* const name, char* const category, int const quantity,
	double const price, double const inches, char* const resolution)
	: Product(name, category, quantity, price), inches(inches), resolution(resolution) {}

Monitor::~Monitor() {
};

Monitor::Monitor(const Monitor &other): Product(other),
	inches(other.getInches()), resolution(other.getResolution()) {};

Monitor& Monitor::operator=(const Monitor& other)
{
	this->inches = other.getInches();
	this->resolution = other.getResolution();
	Product::operator=(other);
	return *this;
};

double Monitor::getInches() const
{
	return this->inches;
}

char* Monitor::getResolution() const
{
	return this->resolution;
}
