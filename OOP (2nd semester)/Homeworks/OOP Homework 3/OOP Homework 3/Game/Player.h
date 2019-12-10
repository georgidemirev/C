#pragma once
#include <iostream>
#include "Character.h"
using namespace std;

class Player:public Character {
private:

	type_ type = player;

public:

	Player(char* name = "" , Point2D& point = Point2D(0, 0), int d=0, int h=0) :Character(name, point, d, h) {};
	Player(Player&);// not a const because of dynamic_cast in Base classes!
	Player& operator=(Character & p);// in case we want to assing mob or character to player
	virtual ~Player() {};

	virtual Entity* clone() override { return new Player(*this); };

	const type_ getType() const { return this->type; };
	const int getID()const { return Character::getID(); };
	const char* getName()const { return Character::getName(); };
	Point2D* getLocation() { return Character::getLocation(); };
	const int getHealth()const { return Character::getHealth(); };
	const int getDamage()const { return Character::getDamage();};

	void setHealth(const int a) { Character::setHealth(a); };
	void setDamage(const int a) { Character::setDamage(a); };
	void setName(const char* p) { Character::setName(p); };
	void setLocation(Point2D& p) { Character::setLocation(p); };

	bool isAlive() override { if (getHealth() > 0)return true; else return false;	}

	void attack(Entity& p);
};

Player::Player(Player& p) :Character(p) {}

Player & Player::operator=(Character & p)
{
	Character::operator=(p);
	return *this;
}

void Player::attack(Entity& p){
	//here i make dynamic_cast because in the tast is asked only for Player and Mob 
	Character* cast = dynamic_cast<Character*>(&p);
	if (cast != nullptr && (p.getType() == mob || p.getType() == player)) {
		if (getDistanceTo(p) < 5) {
			cast->setHealth(cast->getHealth() - this->getDamage()); // Here i make THIS the attacker and P the defender
		};// the cast is changing the health of object p
	}
	else return;
}