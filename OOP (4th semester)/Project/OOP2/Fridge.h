#pragma once
#include "Product.h"

class Fridge : public Product {
private:

	double height;

	double watConsumption;

public:

	Fridge(string const name, string const category, int const quantity,
		double const price, double const height, double const watConsumption);

	virtual ~Fridge();

	Fridge(const Fridge &other);

	Fridge& operator=(const Fridge& other);

	double getHeight() const;

	double getWatConsumption() const;

	void print() const;
};