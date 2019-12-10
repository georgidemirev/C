#pragma once
#include <iostream>
#include "Character.h"
#include "Player.h"
using namespace std;

class Mob :public Character {
private:

	type_ type = mob;

public:
	

	Mob(char* name = "" , Point2D& point = Point2D(0,0) , int d=0, int h=0) :Character(name, point, d, h) {};
	Mob(Mob&);
	Mob & operator=(Character &);
	virtual ~Mob() {};

	virtual Entity* clone()  override { return new Mob(*this); };

	const type_ getType() const { return this->type; };
	const int getID()const { return Character::getID(); };
	const char* getName()const { return Character::getName(); };
	Point2D* getLocation() { return Character::getLocation(); };
	const int getHealth()const { return Character::getHealth(); };
	const int getDamage()const { return Character::getDamage(); };

	void setHealth(const int a) { Character::setHealth(a); };
	void setDamage(const int a) { Character::setDamage(a); };
	void setName(const char* p) { Character::setName(p); };
	void setLocation(Point2D& p) { Character::setLocation(p); };

	virtual bool isAlive() override { if (getHealth() > 0)return true; else return false; }

	void attack(Entity&);
};

Mob::Mob(Mob &p) :Character(p) {}

Mob & Mob::operator=(Character & p)
{
	Character::operator=(p);
	return *this;
}

void Mob::attack(Entity& p) { 
	//here i make dynamic_cast because in the tast is asked only for Player and Mob 
	Player* cast = dynamic_cast<Player*>(&p);
	if (cast != nullptr && (p.getType() == player)) {
		if (getDistanceTo(p) < 5) {
			cast->setHealth(cast->getHealth() - this->getDamage()); // Here i make THIS the attacker and P the defender
		};// the cast is changing the health of object p
	}
	else return;
}
