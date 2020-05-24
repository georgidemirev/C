#pragma once
#include "Product.h"


class Laptop : public Product {
private:

	double inches;

	string gpu;

	string cpu;

public:

	Laptop(string const name, string const category, int const quantity,
		double const price, double const inches,
		string const gpu, string const cpu);

	virtual ~Laptop();

	Laptop(const Laptop &other);

	Laptop& operator=(const Laptop& other);

	double getInches() const;

	string getCpu() const;

	string getGpu() const;

	void print() const;
};