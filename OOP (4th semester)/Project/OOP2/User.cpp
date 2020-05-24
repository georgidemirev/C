#include "stdafx.h"
#include "User.h"
#include "ShoppingCart.h"

User::User() : username("username"), password("password"), id(-1) 
{
	this->shoppingCart = new ShoppingCart();
	this->wallet = new Wallet();
}

User::User(string const username, string const password,int const id) :
	username(username), password(password), id(id)
{
	this->shoppingCart = new ShoppingCart();
	this->wallet = new Wallet();
}

User::~User() 
{
	delete shoppingCart;
	delete wallet;
};

User::User(const User &other):username(other.getUsername()),
password(other.getPassword()), id(other.getId()), 
shoppingCart(other.getShoppingCart()), wallet(other.getWallet()) {};

User& User::operator=(const User& other)
{
	this->username = other.getUsername();
	this->wallet = other.getWallet();
	this->shoppingCart = other.getShoppingCart();
	this->password = other.getPassword();
	this->id = other.getId();
	return *this;
};

bool User::operator==(const User& o1) const
{
	if (this->username.compare(o1.getUsername()) == 0)
	{
		return true;
	};
	return false;
};

double User::getMoneyInWallet() const 
{
	return (*this->wallet).getMoney();
}

string User::getUsername() const
{
	return this->username;
}

string User::getPassword() const
{
	return this->password;
}

Wallet* User::getWallet() const
{
	return this->wallet;
}

ShoppingCart* User::getShoppingCart() const
{
	return this->shoppingCart;
}

int User::getId() const
{
	return this->id;
}