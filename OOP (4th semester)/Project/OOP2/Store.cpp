#include "stdafx.h"
#include "User.h"
#include "Product.h"
#include "Store.h"
#include <iostream>

using namespace std;

Store::Store(char* const name) :name(name) {}

Store::~Store() {
};

Store::Store(const Store &other) : name(other.getName()) {
	Vector<User> vectorUsers(users);
	this->users = vectorUsers;
	Vector<Product> vectorProducts(products);
	this->products = vectorProducts;
};

Store& Store::operator=(const Store& other)
{
	this->name = other.getName();
	Vector<User> vectorUsers(other.getUsers());
	this->users = vectorUsers;
	Vector<Product> vectorProducts(other.getProducts());
	this->products = vectorProducts;
	return *this;
};

void Store::addProduct(Product const product)
{
	products.push_back(product);
}

User* Store::findUserByUsername(char* const username)
{
	for (int i = 0; i < users.size(); i++) {
		if (users[i].getUsername() == username)
		{
			return &users[i];
		}
	}
	return NULL; 
}

Product* Store::findProductByName(char* const name)
{
	for (int i = 0; i < products.size(); i++) {
		if (products[i].getName() == name)
		{
			return &products[i];
		}
	}
	return NULL;
}

bool Store::doesUserExistByUsername(char* const username) 
{
	for (int i = 0; i < users.size(); i++) {
		if (this->users[i].getUsername() == username)
		{
			return true;
		}
	}
	return false;
}

bool Store::doesUserExistById(int id)
{
	for (int i = 0; i < users.size(); i++) {
		if (this->users[i].getId() == id)
		{
			return true;
		}
	}
	return false;
}

bool Store::doesProductExistByName(char* const name) 
{
	for (int i = 0; i < users.size(); i++) {
		if (this->products[i].getName() == name)
		{
			return true;
		}
	}
	return false;
}

bool Store::hasEnoughMoney(User const user, double const money)
{
	if (user.getMoneyInWallet() >= money) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Store::registerUser(char* const username, char* const password, int const id)
{
	User newUser(username, password, id);

	for (int i = 0; i < users.size(); i++)
	{
		users.push_back(newUser);
	}
}

void Store::logIn(char* const username, char* const password)
{
	//security will be implemented in the last version
}

void Store::logOut()
{
	//security will be implemented in the last version
}

void Store::addProductToCart(User const user, char* const product, int const quantity)
{
	// pass user by username and find it afterwards in the last version
	// validate if that product exists in the Products of the store
	Product product1 = *findProductByName(product);
	if (&product == NULL)return;

	Product productForCart = product1;
	productForCart.setQuantity(quantity);

	ShoppingCart cart = user.getShoppingCart();

	user.getShoppingCart().addProduct(productForCart);
}

void Store::removeProductFromCart(User const user, char* const product)
{
	// next logic will be implemented in the next version
	// should do this function in the CART !

	Product product1 = *findProductByName(product);
	if (&product == NULL)return;

	user.getShoppingCart().removeProduct(product);
}

void Store::printCart(User const user) const
{
	int numberOfProductsInCart = user.getShoppingCart().getProducts().size();

	for (int i = 0; i < numberOfProductsInCart; i++)
	{
		products[i].print();
	}
}

void Store::buyEverythingFromCart(User const user)
{
	double cartPrice = user.getShoppingCart().getCartPrice();

	if (hasEnoughMoney(user, cartPrice))
	{
		double availableMoney = user.getWallet().getMoney();
		user.getWallet().setMoney(availableMoney - cartPrice);
		user.getShoppingCart().clearShoppingCart();
	}
}


void Store::printAllProducts() const
{
	for (int i = 0; i < products.size(); i++)
	{
		products[i].print();
	}
}

void Store::printProductsByCategory(char* const category) const
{
	for (int i = 0; i < products.size(); i++)
	{
		if (products[i].getCategory() == category)
		{
			products[i].print();
		}
	}
}

void Store::printProductsByPrice(double const price) const
{
	for (int i = 0; i < products.size(); i++)
	{
		if (products[i].getPrice() == price)
		{
			products[i].print();
		}
	}
}

void Store::printProductsByName(char* const name) const
{
	for (int i = 0; i < products.size(); i++)
	{
		if (products[i].getName() == name)
		{
			products[i].print();
		}
	}
}

char* Store::getName() const
{
	return this->name;
}

Vector<User> Store::getUsers() const
{
	return this->users;
}

Vector<Product> Store::getProducts() const
{
	return this->products;
}
