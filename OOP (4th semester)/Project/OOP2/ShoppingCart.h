#pragma once
#include "Product.h"
#include <vector>

class ShoppingCart {
private:

	vector<Product*> products;

public:

	ShoppingCart();

	virtual ~ShoppingCart();

	ShoppingCart(const ShoppingCart &other);

	ShoppingCart& operator=(const ShoppingCart& other);

	Product* findProductByName(string const name);

	void addProduct(Product* const product);

	void removeProduct(string const name);

	void clearShoppingCart();

	double getCartPrice() const;

	vector<Product*> getProducts() const;

	void printAllProducts() const;
};