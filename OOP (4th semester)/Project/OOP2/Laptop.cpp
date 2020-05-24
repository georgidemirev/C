#include "stdafx.h"
#include "Laptop.h"
#include <iostream>

using namespace std;

Laptop::Laptop(string const name, string const category, int const quantity,
	double const price, double const inches, string const gpu, string const cpu)
	: Product(name, category, quantity, price), inches(inches), gpu(gpu), cpu(cpu) {}

Laptop::~Laptop() {};

Laptop::Laptop(const Laptop &other) : Product(other),
inches(other.getInches()), gpu(other.getGpu()), cpu(other.getCpu()) {};

Laptop& Laptop::operator=(const Laptop& other)
{
	this->inches = other.getInches();
	this->gpu = other.getGpu();
	this->cpu = other.getCpu();
	Product::operator=(other);
	return *this;
};

double Laptop::getInches() const
{
	return this->inches;
}

string Laptop::getCpu() const
{
	return this->cpu;
}

string Laptop::getGpu() const
{
	return this->gpu;
}

void Laptop::print() const
{
	Product::print();
	cout << ", inches: " << inches << ", gpu: " << gpu << ", cpu: " << cpu;
}