#include "stdafx.h"
#include "ShoppingCart.h"
#include "Product.h"

ShoppingCart::ShoppingCart() {}

ShoppingCart::~ShoppingCart() {};

ShoppingCart::ShoppingCart(const ShoppingCart &other) {
	Vector<Product> vector(other.getProducts());
	this->products = vector;
};

ShoppingCart& ShoppingCart::operator=(const ShoppingCart& other)
{
	Vector<Product> vector(other.getProducts());
	this->products = vector;
	return *this;
};

Product* ShoppingCart::findProductByName(char* const name)
{
	for (int i = 0; i < products.size(); i++) {
		if (products[i].getName() == name)
		{
			return &products[i];
		}
	}
	return NULL;
}

Vector<Product> ShoppingCart::getProducts() const
{
	return this->products;
}

void ShoppingCart::addProduct(Product const product)
{
	products.push_back(product);
}

void ShoppingCart::removeProduct(char* name)
{
	Product product = *findProductByName(name);

	if (&product == NULL)return;

	products.remove(product);
}

void ShoppingCart::clearShoppingCart() {
	this->products.clear();
};

double ShoppingCart::getCartPrice() const
{
	double price = 0;

	for (int i = 0; i < products.size(); i++)
	{
		price += products[i].getPrice();
	}

	return price;
}