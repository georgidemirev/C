#pragma once
#include "stdafx.h"
#include "User.h"
#include "Product.h"
#include <vector>

class Store {
private:

	string name;

	vector<User*> users;

	vector<Product*> products;
	
	// helping methods:

	User* findUserByUsername(string const username);

	Product* findProductByName(string const name);

	bool doesUserExistByUsername(string const username); // will be used to register users only with unique usernames

	bool doesUserExistById(int id); // will be used to register users only with unique ids

	bool doesProductExistByName(string const name); // will be used in addProductToCart to check if that product exists

	bool hasEnoughMoney(string const username, double const money); // checks if user has enough money in the wallet to buy everything from the shopping cart

public:

	Store(string const name);

	~Store();

	Store(const Store &other);

	Store& operator=(const Store& other);

	void addProduct(Product* const product);

	void removeProduct(string const name);

	void registerUser(string const username, string const password, int const id);

	void removeUser(string const username);

	void addProductToCart(string const username, string const name, int const quantity);

	void removeProductFromCart(string const username, string const product);

	void printCart(string const user);

	void buyEverythingFromCart(string const username);

	void printAllProducts() const;

	void printProductsByCategory(string const category) const;

	void printProductsByPrice(double const price) const;

	void printProductsByName(string const name) const;

	string getName() const;

	vector<User*> getUsers() const;

	vector<Product*> getProducts() const;
};