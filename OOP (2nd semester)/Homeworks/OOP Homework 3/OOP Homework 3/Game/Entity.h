#pragma once
#include <iostream>
#include "Character.h"
#include "Points.h"
using namespace std;

enum type_ { player, npc, mob };

static int id_generator = 5289401;

class Entity {
private:

	int id;

	char* name;

	Point2D* location;

public:

	Entity();
	Entity(char* name, Point2D& p);
	Entity(Entity&);// not a const because of dynamic_cast
	Entity& operator=( Entity&);
	virtual ~Entity() { delete[] name; delete location;};

	virtual Entity* clone() = 0;

	virtual const type_ getType() const = 0;
	const int getID()const { return id; };
	const char* getName()const { return name; };
	Point2D* getLocation() { return location; };

	void generateID();
	void setName(const char* n);
	void setLocation(Point2D& p);

	virtual bool isAlive() { return true; };

	virtual double getDistanceTo2D( Entity&)const;
	virtual double getDistanceTo( Entity&)const;
	 
	virtual void moveTo(Point2D&);// not a const because of dynamic_cast
	virtual void moveTo(Entity&);// not a const because of dynamic_cast

};

Entity::Entity()
{
	generateID();
	setName("");
	setLocation(Point2D(0,0));
}

Entity::Entity(char * name , Point2D & p)
{	
	generateID();
	setName(name);
	setLocation(p);
}

Entity::Entity(Entity &p)
{
	generateID();
	setName(p.getName());
	setLocation(*(p.getLocation()));
}

Entity & Entity::operator=(Entity & p) // here operator= only assigns the variables to the other class, the ip is not changed
{
	setName(p.getName());
	setLocation(*p.getLocation());
	return *this;
}

void Entity::generateID()
{
	this->id = ++id_generator;
}

void Entity::setName(const char * n)
{
	if (n == nullptr) {
		n = "";
	}
		delete[] name;
		this->name = new char[strlen(n) + 1];
		strcpy_s(this->name, strlen(n) + 1, n);
	
}

void Entity::setLocation(Point2D& p)
{		
	 if (location != nullptr) {
			 delete location;
		 }
	 Point3D* castTo3D = dynamic_cast<Point3D*>(&p);
	 if (castTo3D != nullptr) {
		 location = new Point3D;
		 Point3D* castLocation = dynamic_cast<Point3D*>(this->location);
		 castLocation->setX(p.getX());
		 castLocation->setY(p.getY());
		 castLocation->setZ(castTo3D->getZ());
	 }
	 else {
		 location = new Point2D;
		 location->setX(p.getX());
		 location->setY(p.getY());
	 }
}

double Entity::getDistanceTo2D( Entity & p)const
{
	return this->location->getDistanceTo(*p.getLocation());
}

double Entity::getDistanceTo( Entity & p)const
{
	Point3D* castThisTo3D = dynamic_cast<Point3D*>(this->location);
	Point3D* castOtherTo3D = dynamic_cast<Point3D*>(p.getLocation());
	if (castThisTo3D == nullptr || castOtherTo3D == nullptr) {
		return this->getDistanceTo2D(p);
	}
	else return castThisTo3D->getDistanceTo(*(castOtherTo3D));
}

void Entity::moveTo(Point2D & other)
{
	setLocation(other);
}

void Entity::moveTo(Entity & p)
{
	setLocation(*(p.getLocation()));
}