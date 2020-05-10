#pragma once
#include "Product.h"
#include "Vector.h"


// removing of products is not available in this version of the project
class ShoppingCart {
private:

	Vector<Product> products;

public:

	ShoppingCart();

	~ShoppingCart();

	ShoppingCart(const ShoppingCart &other);

	ShoppingCart& operator=(const ShoppingCart& other);

	Product* findProductByName(char* const name);

	void addProduct(Product const product);

	void removeProduct(char* name);

	void clearShoppingCart();

	double getCartPrice() const;

	Vector<Product> getProducts() const;
};