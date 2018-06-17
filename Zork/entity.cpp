#include <iostream>
#include "entity.h"

// Constructor
Entity::Entity(std::string name, std::string description)
{
	this->name = name;
	this->descritption = description;
	this->visible = true;
	this->contains = {};
}


// Destructor
Entity::~Entity()
{
	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend(); ++it)
		delete *it;
}


// Adds a valid entity to the contains list
// #entity: a valid entity
void Entity::Add(Entity* entity)
{
	this->contains.push_back(entity);
}


// Removes a valid entity to the contains list
// #entity: a valid entity
void Entity::Remove(Entity* entity)
{
	this->contains.remove(entity);
}


string Entity::ListContents(void) 
{
	string output = "";

	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend(); ++it)
		output += (*it)->name + ", ";

	return output;
}


// Looks for an entity with name 'name' within itself
// #name: the name of the entity we are looking for
// @returns: the entity if found, else NULL
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


// Fetch a list of all visible entities within itself
// @returns: list of visible entities
list<string> Entity::Visible() 
{
	if (!this->visible) return {};

	list<string> output = {this->name};
	
	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend(); ++it)
		output.merge((*it)->Visible());

	return output;
}


// Look action
// Displays the entities description and the placement text
// of all visible object contained inside it
void Entity::Look(void) 
{
	if (!this->visible) return;

	std::cout << this->descritption << endl << "  ";

	for (list<Entity*>::iterator it = this->contains.begin(); it != this->contains.cend(); ++it)
		(*it)->SeeContents();
}


// ======== ACTION PLACEHOLDER ====== 
// default behaviour if child class doesn't allow an action
Entity* Entity::Go(void)
{
	cout << "You can not go there." << endl << "  ";
	
	return NULL;
}


void Entity::Open(void) 
{
	cout << "It won't open." << endl << "  ";
}


void Entity::Close(void) 
{
	cout << "Trying to close this makes no sense." << endl << "  ";
}


void Entity::Take(Entity* parent)
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


void Entity::Use(Entity* recipient)
{
	cout << "That is simply not possible." << endl << "  ";
}