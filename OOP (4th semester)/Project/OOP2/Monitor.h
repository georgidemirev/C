#pragma once
#include "Product.h"


class Monitor: public Product {
private:

	double inches;

	string resolution;

public:

	Monitor(string const name, string const category,
		int const quantity, double const price,
		double const inches, string const resolution);

	virtual ~Monitor();

	Monitor(const Monitor &other);

	Monitor& operator=(const Monitor& other);

	double getInches() const;

	string getResolution() const;

	void print() const;
};