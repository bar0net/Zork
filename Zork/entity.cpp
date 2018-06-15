#include <iostream>
#include "entity.h"

Entity::Entity(std::string name, std::string description)
{
	this->name = name;
	this->descritption = description;
	this->visible = true;
	this->contains = {};
}

Entity::Entity(std::string name, std::string description, Entity* parent)
{
	this->name = name;
	this->descritption = description;
	this->visible = true;
	this->contains = {};

	parent->Add(this);
}

Entity::~Entity()
{
	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend(); ++it)
		delete *it;
}


void Entity::Add(Entity* entity)
{
	this->contains.push_back(entity);
}


Entity* Entity::Find(string name) 
{
	if (this->name == name) return this;

	Entity* output;
	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend(); ++it)
	{
		output = (*it)->Find(name);

		if (output != NULL) return output;
	}

	return NULL;
}


list<string> Entity::Visible() 
{
	if (!this->visible) return {};

	list<string> output = {this->name};
	
	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend(); ++it)
		output.merge((*it)->Visible());

	return output;
}


void Entity::Look(void) 
{
	if (!this->visible) return;

	std::cout << this->descritption << endl << "  ";
}

void Entity::Go(void) 
{

}
