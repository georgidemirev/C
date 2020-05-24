#pragma once
#include <string>
using namespace std;

// This class is public so that there is option for a product to be 
// added and that product will not have category

class Product {
private:

	string name;

	string category;

	int quantity;

	double price;

public:

	Product();

	Product(string const name, string const category,
		int const quantity, double const price);

	virtual ~Product();

	Product(const Product &other);

	Product& operator=(const Product& other);

	bool operator==(const Product& o1) const;

	virtual void print() const;

	string getName() const;

	string getCategory() const;

	int getQuantity() const;

	void setQuantity(int const quantity);

	double getPrice() const;
};