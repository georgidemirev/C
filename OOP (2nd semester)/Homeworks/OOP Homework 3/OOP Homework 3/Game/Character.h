#pragma once
#include "Points.h"
#include "Entity.h"
using namespace std;

class Character :public Entity{ // is abstract 
private:

	int damage, health;

public:

	Character(char* = "", Point2D& p = Point2D(0,0), int = 0, int = 0);
	Character(Character&);
	Character& operator=(Character&);
	virtual ~Character() {};
	
	const int getHealth()const { return this->health; };
	const int getDamage()const { return this->damage; };
	const char* getName()const { return Entity::getName(); };
	Point2D* getLocation() { return Entity::getLocation(); }; 

	void setHealth(const int a) { this->health = a; };
	void setDamage(const int a) { this->damage = a; };
	void setName(const char* p) { Entity::setName(p); };
	void setLocation(Point2D & p) { Entity::setLocation(p); };

	bool isAlive()override { return true; };
};

Character::Character(char* name, Point2D& point, int d, int h):Entity(name,point) {
	setDamage(d);
	setHealth(h);
}

Character::Character(Character &p):Entity(p)
{
	setDamage(p.getDamage());
	setHealth(p.getHealth());
}

Character & Character::operator=(Character & p)
{
	setDamage(p.getDamage());
	setHealth(p.getHealth());
	setName(p.getName());
	setLocation(*p.getLocation());
	return *this;
}
