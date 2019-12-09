#include "stdafx.h"
#include "header.h"


BankAccount::BankAccount()
{
	balance = 0;
	creditLimit = 0;
}

BankAccount::BankAccount(int bal, int cre)
{
	setBalance(bal);
	setCreditLimit(cre);
}

BankAccount::BankAccount(const BankAccount & p)
{
	this->balance = p.getBalance();
	this->creditLimit = p.getCreditLimit();
}

BankAccount::~BankAccount()
{
}

int BankAccount::getBalance() const
{
	return balance;
}

int BankAccount::getCreditLimit() const
{
	return creditLimit;
}

void BankAccount::setBalance(int p)
{
	if (p < getCreditLimit())cout << "The balance is less than your credit limit!\n";
	balance = p;
}

void BankAccount::setCreditLimit(int p)
{
	creditLimit = p;
}

void BankAccount::Pay(int p)
{
	if (((getBalance()+getCreditLimit()) >= p) && p>0)
	{
		setBalance(getBalance() - p);
	}
	else cout << "Eror!\n";
}

void BankAccount::CashIn(int p)
{
	balance += p;
}

void BankAccount::CashOut(int p)
{
	if (getBalance() < p) {
		cout << "You cant take more money than you have!\n";
	}
	else {
		balance -= p;
	}
}

int BankAccount::PrintBalance() const
{
	return getBalance();
}
