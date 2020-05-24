#include "stdafx.h"
#include "Monitor.h"
#include <iostream>

using namespace std;

Monitor::Monitor(string const name, string const category, int const quantity,
	double const price, double const inches, string const resolution)
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

string Monitor::getResolution() const
{
	return this->resolution;
}

void Monitor::print() const
{
	Product::print();
	cout << ", inches: " << inches << ", resolution: " << resolution;
}