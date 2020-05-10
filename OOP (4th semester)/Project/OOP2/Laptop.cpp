#include "stdafx.h"
#include "Laptop.h"

Laptop::Laptop(char* const name, char* const category, int const quantity,
	double const price, double const inches, char* const gpu, char* const cpu)
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

char* Laptop::getCpu() const
{
	return this->cpu;
}

char* Laptop::getGpu() const
{
	return this->gpu;
}