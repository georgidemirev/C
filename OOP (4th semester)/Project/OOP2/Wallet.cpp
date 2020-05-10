#include "stdafx.h"

#include "Wallet.h"

Wallet::Wallet()
{
	this->money = 0;
}

Wallet::~Wallet() {};

Wallet::Wallet(const Wallet &other): money(other.getMoney()) {};

Wallet& Wallet::operator=(const Wallet& other)
{
	this->money = other.getMoney();
	return *this;
};

double Wallet::getMoney() const
{
	return this->money;
}

void Wallet::setMoney(double const amount)
{
	this->money = amount;
}