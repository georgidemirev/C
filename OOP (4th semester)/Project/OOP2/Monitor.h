#pragma once
#include "Product.h"

class Monitor: public Product {
private:

	double inches;

	char* resolution;

public:

	Monitor(char* const name, char* const category,
		int const quantity, double const price,
		double const inches, char* const resolution);

	~Monitor();

	Monitor(const Monitor &other);

	Monitor& operator=(const Monitor& other);

	double getInches() const;

	char* getResolution() const;
};