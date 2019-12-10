#pragma once
#include <iostream>
using namespace std;

class Person {
private:

	char* name;
	char* egn;
	int age;
	int birth;

public:

	Person();
	Person(char*, char*, int, int);
	Person(const Person &);
	~Person();

	char* getName()const;
	char* getEgn()const;
	int getAge()const;
	int getBirth()const;

	void setName(char*);
	void setEgn(char*);
	void setAge(int);
	void setBirht(int);

};

class BankAccount {
private:

	int balance;
	int creditLimit;

public:

	BankAccount();
	BankAccount(int, int);
	BankAccount(const BankAccount &);
	~BankAccount();

	int getBalance()const;
	int getCreditLimit()const;

	void setBalance(int);
	void setCreditLimit(int);

	void Pay(int);
	void CashIn(int);
	void CashOut(int);
	int PrintBalance()const;

};

class PersonWithAccount :public Person , public BankAccount{
private:

	char* IBAN;

public:

	PersonWithAccount();
	PersonWithAccount(char*,char*,int,int,int, int,char*);
	PersonWithAccount(const PersonWithAccount &);
	~PersonWithAccount();

	char* getName()const;
	char* getEgn()const;
	int getAge()const;
	int getBirth()const;
	int getBalance()const;
	int getCreditLimit()const;
	char* getIBAN()const;

	void setName(char*);
	void setEgn(char*);
	void setAge(int);
	void setBirht(int);
	void setBalance(int);
	void setCreditLimit(int);
	void setIBAN(char*); 

	void Pay(int);
	void CashIn(int);
	void CashOut(int);
	int PrintBalance()const;

	void regToSpotify();
};