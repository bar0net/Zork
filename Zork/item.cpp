#include "item.h"

#include <iostream>

// Constructors
Item::Item(string name, string description, string placementText, bool visible, bool canPick, bool destroyOnUse, Entity* parent) :
	Object(name, description, placementText, visible, parent)
{
	this->canPick = canPick;
	this->canDrop = false;
	this->parent = parent;
	this->type = ITEM;
	this->destroyOnUse = destroyOnUse;
}

Item::Item(string name, string description, string placementText, bool visible, bool canPick, bool destroyOnUse, Entity* allowedInteractor, Entity* parent) :
	Item(name, description, placementText, visible, canPick, destroyOnUse, parent)
{
	this->allowedInteractors.push_back(allowedInteractor);
}

Item::Item(string name, string description, string placementText, bool visible, bool canPick, bool destroyOnUse, list<Entity*> allowedInteractors, Entity* parent) :
	Item(name, description, placementText, visible, canPick, destroyOnUse, parent)
{
	this->allowedInteractors = allowedInteractors;
}

Item::~Item() 
{
	cout << "The " << this->name << " got destroyed." << endl << "  ";
	this->parent->Remove(this);
}


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

// Drops the item if the recipient 'parent' is valid
void Item::Drop(Entity* parent) 
{
	if (!canDrop) 
	{
		cout << "You can't do that." << endl << "  ";
		return;
	}

	if (parent->type == ROOM) 
	{
		DropAction(parent);
		cout << "You dropped the " << this->name << " on the floor." << endl << "  ";
	}
	else if (parent->type == CONTAINER)
	{
		DropAction(parent);
		cout << "You dropped the " << this->name << " in the " << parent->name << endl << "  ";
	}
	else
		cout << "You can't do that." << endl << "  ";
}


// Drops the item on the recipient 'parent'
void Item::DropAction(Entity* parent) 
{
	this->parent->Remove(this);

	canPick = true;
	canDrop = false;

	this->parent = parent;
	parent->Add(this);
}

// Use the item on the target
void Item::Use(Entity* target) 
{
	if (this->allowedInteractors.size() == 0) 
	{
		cout << "You can't use this." << endl << "  ";
		return;
	}

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

	if (destroyOnUse) delete this;
} 