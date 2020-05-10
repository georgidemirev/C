#pragma once


class Wallet {
private:

	double money;

public:

	Wallet();

	~Wallet();

	Wallet(const Wallet &other);

	Wallet& operator=(const Wallet& other);

	double getMoney() const;

	void setMoney(double const amount);
};