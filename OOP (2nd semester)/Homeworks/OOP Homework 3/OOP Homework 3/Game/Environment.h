#pragma once
#include "Player.h"
#include "Mob.h"
#include "NPC.h"
#include <vector>

class Environment { 
private:
	
	vector<Entity*> entities; 
	
	void del() { 
		for (Entity* entity : entities) { 
			delete entity; 
		}
		cout << entities.size() << endl;
	} // deleting the pointers stored in entities.

public:

	Environment();
	Environment( Environment&);
	Environment& operator=( Environment&);
	virtual ~Environment() { del(); };

	vector<Entity*>& getEntities() { return entities; }
	void setEntities(const vector<Entity*>&); 

	void add(Entity&);
	Entity& getAt(int);
	void removeAt(int);
	void generateEntities();
	void destroyEntities();
	const Entity& getClosestEnemy(Player&, type_);
};

Environment::Environment()
{
	entities.reserve(5); // so that it does not resize the vector on every push of element
						 // and that is how less copy costructors will be called
}

Environment::Environment( Environment & p)
{
	setEntities(p.getEntities());
}

Environment & Environment::operator= ( Environment & p)
{
	setEntities(p.getEntities());
	return *this;
}

void Environment::setEntities(const vector<Entity*>& p)
{
	del();
	for (int i = 0; i < p.size(); i++) {
		add(*p[i]);
	}
}

void Environment::add(Entity& p)
{
	entities.push_back(p.clone());
}

Entity&  Environment::getAt(int p)
{
	return *(entities[p - 1]);
}

void Environment::removeAt(int p)
{
	vector<Entity*> copy = entities;
	entities.clear();
	for (int i = 0; i < copy.size(); i++) {
		if (i == p - 1)continue;
		entities.push_back(copy[i]);
	}
	copy.clear();
}

void Environment::generateEntities()
{
	Player newEntity("newPlayer", Point2D(0, 0), 10, 100);
	add(newEntity);
	Mob newEntity2("newMob", Point2D(1,1), 20, 200);
	add(newEntity2);
	NPC newEntity3("newNPC", Point2D(2,2));
	add(newEntity3);
}

void Environment::destroyEntities()
{
	entities.clear();
}

const Entity & Environment::getClosestEnemy(Player & p, type_ type)
{	
	double distance = -1;
	int i = 0;
	int holder = -1;

	for ( i ; i < entities.size(); i++) {
		if (entities[i]->getType() == type && entities[i]->isAlive())
		{
			distance = p.getDistanceTo(*entities[i]);
			if (entities[i]->getID() == p.getID())
			{
				distance = -1;
				break;// in case the objects are the same
			}
			holder = i;
			break;
		}
	}

	for ( i ; i < entities.size(); i++) {
		if (entities[i]->getType() == type && entities[i]->isAlive())
		{
			double copy = p.getDistanceTo(*entities[i]);
			if (entities[i]->getID() == p.getID())
			{
				continue;// in case the distance is 0 and the names are the same it will be counted as the same object(p)
			}
			if (copy < distance) {
				distance = copy;
				holder = i;
			}
		}
	}

	if (holder == -1) return p; // in case, there is not object with the same type as the one asked
	return *entities[holder];
}