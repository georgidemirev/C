#pragma once
#include "stdafx.h"
#include <iostream>
#include "Users.h"
using namespace std;

char* Admin::getPass()const
{
	return VIP::getPass();
}

void Admin::setPass(char * p)
{
	VIP::setPass(p);
	PowerUser::setPass(p);

}

void Admin::setTit(char *p)
{
	VIP::setTit(p);
	PowerUser::setTit(p);
}

void Admin::setUs(char *p)
{
	VIP::setUs(p);
	PowerUser::setUs(p);
}

void Admin::setIP(char *p)
{
	VIP::setIP(p);
	PowerUser::setIP(p);
}

void Admin::setRep(int p)
{
	PowerUser::setRep(p);
}

Admin::Admin() :VIP(), PowerUser() {}

Admin::Admin(char * ip, char *us, char *pass, char *tit, int r) :VIP(ip,us,pass,tit),PowerUser(ip,us,pass,tit,r){}

Admin::Admin(const Admin &p) :VIP(p), PowerUser(p) {}

Admin & Admin::operator=(const Admin &p)
{
	if (this != &p)
	{
		VIP::operator=(p);
		PowerUser::operator=(p);
	}
	return *this;
}

Admin::~Admin() {}

char * Admin::getIP() const
{
	return VIP::getIP();
}

char * Admin::getUs() const
{
	return VIP::getUs();
}

char * Admin::getTit() const
{
	return VIP::getTit();
}

int Admin::getRep() const
{
	return PowerUser::getRep();
}

void Admin::changePass(char *oldP, char *newP)
{
	VIP::changePass(oldP,newP);
}

void Admin::changeOtherUsername(User & p, char * newU)
{
	p.setUs(newU);
}

void Admin::giveReputation(PowerUser &p)
{
	PowerUser::giveReputation(p);
}
