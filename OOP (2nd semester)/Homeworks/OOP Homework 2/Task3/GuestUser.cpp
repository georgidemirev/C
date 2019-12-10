#pragma once
#include "stdafx.h"
#include <iostream>
#include "Users.h"
using namespace std;

Guest::Guest()
{
	ip = nullptr;
}

Guest::Guest(char * p)
{
	if (ip == nullptr)
	{
		ip = new char[strlen(p) + 1];
		strcpy_s(ip, strlen(p) + 1, p);
	}
	else {
		delete[] ip;
		ip = new char[strlen(p) + 1];
		strcpy_s(ip, strlen(p) + 1, p);
	}
}

Guest::Guest(const Guest & p)
{
	setIP(p.getIP());
}

Guest & Guest::operator=(const Guest &p)
{
	setIP(p.getIP());
	return *this;
}

Guest::~Guest()
{
	delete[] ip;
}

char* Guest::getIP()const
{
	return ip;
}

void Guest::setIP(char * p)
{
	if (p == nullptr) {
		p = "";
	}
	int len = strlen(p) + 1;
	delete[] ip;
	ip = new char[len];
	strcpy_s(ip, len, p);
}
/////////////////////////////////////////////////////////////////////////////////////
/////								USER										/////
/////////////////////////////////////////////////////////////////////////////////////

User::User() :Guest()
{
	password = nullptr;
	username = nullptr;
	title = nullptr;
}

User::User(char * ip, char *us, char *p, char *t) : Guest(ip)
{
	setPass(p);
	setUs(us);
	setTit(t);
}

User::User(const User & p):Guest(p)
{
	setPass(p.getPass());
	setUs(p.getUs());
	setTit(p.getTit());
}

User & User::operator=(const User & p)
{
	if (this != &p)
	{
		Guest::operator=(p);
		setIP(p.getIP());
		setUs(p.getUs());
		setPass(p.getPass());
	}
	return *this;
}

User::~User()
{
	delete[] password;
	delete[] title;
	delete[] username;
}

char * User::encrypt()
{
	for (int i = 0; i < strlen(password); i++) 
	{
		password[i] = password[i] + 3;
	}
	return password;
}

char * User::decrypt() const
{	
	char* arr = new char[strlen(password) + 1];
	strcpy_s(arr, strlen(password) + 1, password);
	for (int i = 0; i < strlen(password) ; i++) 
	{
		arr[i] = (char)arr[i] - 3;
	}
	return arr;
}

char * User::getIP()const
{
	return Guest::getIP();
}

char * User::getUs()const
{
	return username;
}

char * User::getTit()const
{
	return title;
}

void User::setIP(char * p)
{
	Guest::setIP(p);
}

void User::setUs(char * p)
{
	if (p == nullptr) {
		p = "";
	}
	int len = strlen(p) + 1;
	delete[] username;
	username = new char[len];
	strcpy_s(username, len, p);
}

void User::setPass(char* p) 
{
	if (p == nullptr) {
		p = "";
	}
	int len = strlen(p) + 1;
	delete[] password;
	password = new char[len];
	strcpy_s(password, len, p);
	encrypt();
}

void User::setTit(char * p)
{
	if (p == nullptr) {
		p = "";
	}
	int len = strlen(p) + 1;
	delete[] title;
	title = new char[len];
	strcpy_s(title, len, p);
}

char* User::getPass() const
{
	return decrypt();
}

bool User::verifyPass(char * oldP)
{
	return !strcmp(oldP, getPass());
}

void User::changePass(char* oldP ,char* newP)
{
	if (verifyPass(oldP)) 
	{
		setPass(newP);
	}
	else
	{
		cout << "The password is not correct!\n";
	};
}