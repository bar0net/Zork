#include <iostream>
#include "entity.h"

Entity::Entity(std::string name, std::string description)
{
	this->name = name;
	this->descritption = description;
	this->placementText = "";
	this->visible = true;
	this->contains = {};
}

Entity::Entity(std::string name, std::string description, string placementText, Entity* parent)
{
	this->name = name;
	this->descritption = description;
	this->placementText = placementText;
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

	for (list<Entity*>::iterator it = this->contains.begin(); it != this->contains.cend(); ++it)
		(*it)->SeeContents();
}

void Entity::Go(void) 
{
	cout << "You can not go there." << endl << "  ";
}


void Entity::Open(void) 
{
	cout << "It won't open." << endl << "  ";
}


void Entity::Close(void) 
{
	cout << "Trying to close this makes no sense." << endl << "  ";
}


void Entity::Take(void) 
{
	cout << "You can't carry this." << endl << "  ";
}


void Entity::Drop(void) 
{
	cout << "You are not carrying that." << endl << "  ";
}


void Entity::Use(void) 
{
	cout << "That is simply not possible." << endl << "  ";
}

void Entity::SeeContents(void) 
{
	if (!this->visible) return;

	cout << this->placementText << endl << "  ";
}