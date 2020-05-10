#pragma once
#include "Product.h"

class Laptop : public Product {
private:

	double inches;

	char* gpu;

	char* cpu;

public:

	Laptop(char* const name, char* const category, int const quantity,
		double const price, double const inches,
		char* const gpu, char* const cpu);

	~Laptop();

	Laptop(const Laptop &other);

	Laptop& operator=(const Laptop& other);

	double getInches() const;

	char* getCpu() const;

	char* getGpu() const;
};