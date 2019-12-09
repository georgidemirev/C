#include "stdafx.h"
#include "header.h"

PersonWithAccount::PersonWithAccount():Person(),BankAccount()
{
	IBAN = nullptr;
}

PersonWithAccount::PersonWithAccount(char * name, char * egn, int age, int birth , int b , int c,char* iban):Person(name,egn,age,birth),BankAccount(b,c)
{
	setIBAN(iban);
}

PersonWithAccount::PersonWithAccount(const PersonWithAccount & p ):Person(p),BankAccount(p)
{
	setIBAN(p.getIBAN());
}

PersonWithAccount::~PersonWithAccount()
{
	delete[] IBAN;
}
/////////
char * PersonWithAccount::getName() const
{
	return Person::getName();
}

char * PersonWithAccount::getEgn() const
{
	return Person::getEgn();
}

int PersonWithAccount::getAge() const
{
	return Person::getAge();
}

int PersonWithAccount::getBirth() const
{
	return Person::getBirth();
}

int PersonWithAccount::getBalance() const
{
	return BankAccount::getBalance();
}

int PersonWithAccount::getCreditLimit() const
{
	return BankAccount::getCreditLimit();
}

char* PersonWithAccount::getIBAN() const
{
	return IBAN;
}
///////////
void PersonWithAccount::setName(char * p)
{
	Person::setName(p);
}

void PersonWithAccount::setEgn(char *p)
{
	Person::setEgn(p);
}

void PersonWithAccount::setAge(int p)
{
	Person::setAge(p);
}

void PersonWithAccount::setBirht(int p)
{
	Person::setBirht(p);
}

void PersonWithAccount::setBalance(int p) 
{
	BankAccount::setBalance(p);
}

void PersonWithAccount::setCreditLimit(int p)
{
	BankAccount::setCreditLimit(p);
}

void PersonWithAccount::setIBAN(char* p)
{
	
	if (strlen(p) == 10) {
		for (int i = 0; i < strlen(p); i++)
		{
			if (p[i] < '0' || p[i] > '9') {
				cout << "Your IBAN has invalid characters!\n";
			}
		}
		if (getIBAN() == nullptr) {
			IBAN = new char[strlen(p) + 1];
			strcpy_s(IBAN, strlen(p) + 1, p);
		}
		else {
			delete[] IBAN;
			IBAN = new char[strlen(p) + 1];
			strcpy_s(IBAN, strlen(p) + 1, p);
		}
	}
	else {
		cout << "IBAN has more or less than 10 digits!\n";
	}
}
///////////
void PersonWithAccount::Pay(int p)
{
	BankAccount::Pay(p);
}

void PersonWithAccount::CashIn(int p)
{
	BankAccount::CashIn(p);
}

void PersonWithAccount::CashOut(int p)
{
	BankAccount::CashOut(p);
}

int PersonWithAccount::PrintBalance() const
{
	return getBalance();
}

void PersonWithAccount::regToSpotify()
{
	setBalance(getBalance() - 10);
	cout << "After registration to Spotify: \n";
	cout << "Name: " << getName() <<endl<< "IBAN: " << getIBAN() <<endl<< "New balance: " << getBalance() << endl;
}
