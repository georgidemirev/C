#pragma once
#include "stdafx.h"
#include <iostream>
#include "Users.h"
using namespace std;

#include "stdafx.h"
#include "Users.h"

VIP::VIP() :User() {}

VIP::VIP(char * ip, char * us, char * pass, char *title) : User(ip, us, pass, title) {}

VIP::VIP(const VIP &p) : User(p) {}

VIP & VIP::operator=(const VIP &p)
{
	setIP(p.getIP());
	setPass(p.getPass());
	setUs(p.getUs());
	setTit(p.getTit());
	return *this;
}

VIP::~VIP(){}

char * VIP::getIP() const
{
	return User::getIP();
}

char * VIP::getUs() const
{
	return User::getUs();
}

char * VIP::getPass() const
{
	return User::getPass();
}

char * VIP::getTit() const
{
	return User::getTit();
}

void VIP::setIP(char * p)
{
	User::setIP(p);
}

void VIP::setUs(char *p)
{
	User::setUs(p);
}

void VIP::setPass(char *p)
{
	User::setPass(p);
}

void VIP::setTit(char *p)
{
	User::setTit(p);
}

void VIP::changePass(char * oldP, char * newP)
{
	User::changePass(oldP, newP);
}
