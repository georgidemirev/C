#include "stdafx.h"
#include "ShoppingCart.h"
#include "Product.h"
#include <algorithm>
#include <iostream>

using namespace std;

ShoppingCart::ShoppingCart() {}

ShoppingCart::~ShoppingCart() {};

ShoppingCart::ShoppingCart(const ShoppingCart &other) {
	vector<Product*> vector1(other.getProducts());
	this->products = vector1;
};

ShoppingCart& ShoppingCart::operator=(const ShoppingCart& other)
{
	vector<Product*> vector1(other.getProducts());
	this->products = vector1;
	return *this;
};

Product* ShoppingCart::findProductByName(string const name)
{
	for (int i = 0; i < products.size(); i++) {
		if ((*products[i]).getName() == name)
		{
			return products[i];
		}
	}
	return NULL;
}

vector<Product*> ShoppingCart::getProducts() const
{
	return this->products;
}

void ShoppingCart::addProduct(Product* const product)
{
	products.push_back(product);
}

void ShoppingCart::removeProduct(string const name)
{
	Product *product = findProductByName(name);

	if (product == NULL) return;

	products.erase(remove(products.begin(), products.end(), product), products.end());
}

void ShoppingCart::clearShoppingCart() {
	this->products.clear();
};

double ShoppingCart::getCartPrice() const
{
	double price = 0;

	for (int i = 0; i < products.size(); i++)
	{
		price += (*products[i]).getPrice();
	}

	return price;
}

void ShoppingCart::printAllProducts() const
{
	for (int i = 0; i < products.size(); i++)
	{
		(*products[i]).print();
		cout << endl;
	}
}