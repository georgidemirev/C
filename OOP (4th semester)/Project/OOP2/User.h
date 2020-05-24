#pragma once
#include "ShoppingCart.h"
#include "Wallet.h"

class User {
private:

	string username;

	string password;

	int id;

	ShoppingCart *shoppingCart;

	Wallet *wallet;

public:

	User();

	User(string const username, string const password, int const id);

	virtual ~User();

	User(const User &other);

	User& operator=(const User& other);

	bool User::operator==(const User& o1) const;

	double getMoneyInWallet() const;

	string getUsername() const;

	string getPassword() const;

	Wallet* getWallet() const;

	ShoppingCart* getShoppingCart() const;

	int getId() const;
};