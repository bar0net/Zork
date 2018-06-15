#include "world.h"

#include <iostream>

World::World(void) 
{
	Entity* lake = new Entity("lake", "You find yourself in a beautiful lake. There is a small box on the floor.");
	Entity* lake_box = new Entity("box", "the box is closed.", lake);
	
	this->zones.push_back(lake);
	this->current = lake;

	this->current->Look();
}

World::~World(void) 
{
	for (list<Entity*>::iterator it = this->zones.begin(); it != this->zones.cend(); ++it)
		delete *it;
}

void World::Update(ParsedInput msg)
{

}