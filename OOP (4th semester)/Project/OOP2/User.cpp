#include "stdafx.h"
#include "User.h"
#include "ShoppingCart.h"

User::User() : username("username"), password("password"), id(-1) {}

User::User(char* const username, char* const password,int const id) :
	username(username), password(password), id(id) {}

User::~User() {};

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

double User::getMoneyInWallet() const 
{
	return this->wallet.getMoney();
}

char* User::getUsername() const
{
	return this->username;
}

char* User::getPassword() const
{
	return this->password;
}

Wallet User::getWallet() const
{
	return this->wallet;
}

ShoppingCart User::getShoppingCart() const
{
	return this->shoppingCart;
}

int User::getId() const
{
	return this->id;
}