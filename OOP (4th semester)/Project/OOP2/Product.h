#pragma once


// This class is public so that there is option for a product to be added and that product will not have category
class Product {
private:

	char* name;

	char* category;

	int quantity;

	double price;

public:

	Product();

	Product(char* const name, char* const category,
		int const quantity, double const price);

	~Product();

	Product(const Product &other);

	Product& operator=(const Product& other);

	bool operator==(const Product& o1) const; // , const Product& o2);
	//inline bool operator==(const X& lhs, const X& rhs) { return cmp(lhs, rhs) == 0; }

	void print() const;

	char* getName() const;

	char* getCategory() const;

	int getQuantity() const;

	void setQuantity(int const quantity);

	double getPrice() const;
};