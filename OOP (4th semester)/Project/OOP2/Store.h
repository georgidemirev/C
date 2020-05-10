#pragma once
#include "stdafx.h"
#include "User.h"
#include "Product.h"
#include "Vector.h"

class Store {
private:

	char* name;

	Vector<User> users;

	Vector<Product> products;

	bool isLoggedIn; // to store information if there is logged user
					// will be checked before everything that needs a logged user
	
	// helping methods:

	User* findUserByUsername(char* const username); // will be used in logIn method to validate that user exists

	Product* findProductByName(char* const name);

	bool doesUserExistByUsername(char* const username); // will be used to register users only with unique usernames

	bool doesUserExistById(int id); // will be used to register users only with unique ids

	bool doesProductExistByName(char* const name); // will be used in addProductToCart to check if that product exists

	bool hasEnoughMoney(User const user, double const money); // checks if user has enough money in the wallet to buy everything from the shopping cart

	//TODO: in future the user will be able to decide what he wants to buy from the cart.

public:

	Store(char* const name);

	~Store();

	Store(const Store &other);

	Store& operator=(const Store& other);

	void addProduct(Product const product);

	void registerUser(char* const username, char* const password,int const id);

	void logIn(char* const username, char* const password);

	void logOut();

	void addProductToCart(User const user, char* const name, int const quantity);

	void removeProductFromCart(User const user, char* const name);

	void printCart(User const user) const;

	void buyEverythingFromCart(User const user);

	void printAllProducts() const;

	void printProductsByCategory(char* const category) const;

	void printProductsByPrice(double const price) const;

	void printProductsByName(char* const name) const;

	char* getName() const;

	Vector<User> getUsers() const;

	Vector<Product> getProducts() const;
};