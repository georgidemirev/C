#include "stdafx.h"
#include "header.h"

Person::Person()
{
	name = nullptr;
	egn = nullptr;
	age = -1;
	birth = -1;
}

Person::Person(char * n, char *e, int a, int b)
{
	setName(n);
	setEgn(e);
	setAge(a);
	setBirht(b);
}

Person::Person(const Person & p) 
{
	setName(p.getName());
	setEgn(p.getEgn());
	setAge(p.getAge());
	setBirht(p.getBirth());
}

Person::~Person()
{
	delete[] name;
	delete[] egn;
}

char * Person::getName() const
{
	return name;
}

char * Person::getEgn()const
{
	return egn;
}

int Person::getAge()const
{
	return age;
}

int Person::getBirth()const
{
	return birth;
}

void Person::setName(char * p)
{
	if (getName() == nullptr) {
		name = new char[strlen(p) + 1];
		strcpy_s(name, strlen(p) + 1, p);
	}
	else {
		delete[] name;
		name = new char[strlen(p) + 1];
		strcpy_s(name, strlen(p) + 1, p);
	}
}

void Person::setEgn(char *p)
{
	if (getEgn() == nullptr) {
		egn = new char[strlen(p) + 1];
		strcpy_s(egn, strlen(p) + 1, p);
	}
	else {
		delete[] egn;
		egn = new char[strlen(p) + 1];
		strcpy_s(egn, strlen(p) + 1, p);
	}
}

void Person::setAge(int p)
{
	age = p;
}

void Person::setBirht(int p)
{
	birth = p;
}
