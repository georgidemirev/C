#pragma once
#include <iostream>
#include "Character.h"
using namespace std;

class NPC :public Entity {
private:

	type_ type = npc;

public:

	NPC(char* name = "", Point2D& point = Point2D(0, 0)) :Entity(name, point) {};
	NPC(NPC&);
	NPC & operator=(Entity & );
	virtual ~NPC() {};

	virtual Entity* clone()  override { return new NPC(*this); };

	const type_ getType() const { return this->type; };
	const int getID()const { return Entity::getID(); };
	const char* getName()const { return Entity::getName(); };
	Point2D* getLocation() { return Entity::getLocation(); };

	void setName(const char* p) { Entity::setName(p); };
	void setLocation(Point2D& p) { Entity::setLocation(p); };

	virtual bool isAlive() override { return true;}
};

NPC::NPC(NPC &p) :Entity(p) {}

NPC & NPC::operator=(Entity & p)
{
	Entity::operator=(p);
	return *this;
}

