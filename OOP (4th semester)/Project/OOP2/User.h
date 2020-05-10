#pragma once
#include "ShoppingCart.h"
#include "Wallet.h"

class User {
private:

	char* username;

	char* password;

	int id;

	ShoppingCart shoppingCart;

	Wallet wallet;

public:

	User();

	User(char* const username, char* const password, int const id);

	~User();

	User(const User &other);

	User& operator=(const User& other);

	double getMoneyInWallet() const;

	char* getUsername() const;

	char* getPassword() const;

	Wallet getWallet() const;

	ShoppingCart getShoppingCart() const;

	int getId() const;
};