#include "item.h"

#include <iostream>

// Constructors
Item::Item(string name, string description, string placementText, bool visible, bool canPick, Entity* parent) :
	Object(name, description, placementText, visible, parent)
{
	this->canPick = canPick;
	this->canDrop = false;
	this->allowedInteractors = {};
	this->parent = parent;
}

Item::Item(string name, string description, string placementText, bool visible, bool canPick,  Entity* allowedInteractor, Entity* parent) :
	Object(name, description, placementText, visible, parent)
{
	this->canPick = canPick;
	this->canDrop = false;
	this->allowedInteractors.push_back(allowedInteractor);
	this->parent = parent;
}

Item::Item(string name, string description, string placementText, bool visible, bool canPick, list<Entity*> allowedInteractors, Entity* parent) :
	Object(name, description, placementText, visible, parent)
{
	this->canPick = canPick;
	this->canDrop = false;
	this->allowedInteractors = allowedInteractors;
	this->parent = parent;
}

Item::~Item() {}


void Item::Take(Entity* player)
{
	if (!canPick) 
	{
		cout << "You can't do that." << endl << "  ";
		return;
	}

	this->parent->Remove(this);

	cout << "I grab the " << this->name << " and store it in my inventory." << endl << "  ";

	canPick = false;
	canDrop = true;

	this->parent = player;
	parent->Add(this);
}


void Item::Drop(Entity* parent) 
{
	if (!canDrop) 
	{
		cout << "You can't do that." << endl << "  ";
		return;
	}

	this->parent->Remove(this);

	cout << "You dropped the " << this->name << " on the " << parent->name << endl << "  ";

	canPick = true;
	canDrop = false;

	this->parent = parent;
	parent->Add(this);
}


void Item::Use(Entity* target) 
{
	bool found = false;
	for (list<Entity*>::iterator it = this->allowedInteractors.begin(); it != this->allowedInteractors.cend(); ++it)
	{
		if (*it == target)
		{
			found = true;
			break;
		}
	}

	if (!found)
		cout << "You can't do this." << endl << "  ";

	cout << "You used " << this->name << " on " << target->name << " and it worked." << endl << "  ";
	target->UsedOn();
} 