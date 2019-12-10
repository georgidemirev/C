#pragma once
#include "stdafx.h"
#include <iostream>
#include "Users.h"
using namespace std;

PowerUser::PowerUser():User()
{
	reputation = 0;
}

PowerUser::PowerUser(char * ip, char * us, char * pass, char *title, int rep):User(ip,us,pass,title)
{
	setRep(rep);
}

PowerUser::PowerUser(const PowerUser & p):User(p)
{
	setRep(p.getRep());
}

PowerUser & PowerUser::operator=(const PowerUser & p)
{
	if (this != &p)
	{
		User::operator=(p);
		setRep(p.getRep());
	}
	return *this;
}

PowerUser::~PowerUser(){}

char * PowerUser::getIP()const
{
	return User::getIP();
}

char * PowerUser::getUs()const
{
	return User::getUs();
}

char * PowerUser::getPass()const
{
	return User::getPass();
}

char * PowerUser::getTit()const
{
	return User::getTit();
}

int PowerUser::getRep()const
{
	return reputation;
}

void PowerUser::setIP(char * p)
{
	User::setIP(p);
}

void PowerUser::setUs(char *p)
{
	User::setUs(p);
}

void PowerUser::setPass(char *p)
{
	User::setPass(p);
}

void PowerUser::changePass(char * oldP, char *newP)
{
	User::changePass(oldP, newP);
}

void PowerUser::addRep()
{
	reputation++;
}

void PowerUser::giveReputation(PowerUser& user)
{
	if (!strcmp(getUs(), user.getUs()))cout << "Both objects have the same names and can not give reputation!\n";
	else user.addRep();
}

void PowerUser::setTit(char *p)
{
	User::setTit(p);
}

void PowerUser::setRep(int p)
{
	reputation = p;
}
