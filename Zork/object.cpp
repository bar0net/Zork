#include "object.h"

#include <iostream>

// Constructor
Object::Object(string name, string description, string placementText, bool canPick, bool visible, Entity* parent) :
Entity(name, description)
{
	this->placementText = placementText;
	this->canPick = canPick;
	this->canDrop = false;
	this->visible = visible;
	this->parent = parent;

	if (parent != NULL) parent->Add(this);
}

// Destructor
Object::~Object() 
{
	// remove this item from parent contents
	if (parent != NULL) this->parent->Remove(this);
}

// Display its placement text
void Object::SeeContents(void)
{
	if (!this->visible) return;

	cout << this->placementText << endl << "  ";
}


void Object::Take(Entity* player)
{
	if (!canPick)
	{
		cout << "You can't do that." << endl << "  ";
		return;
	}

	this->parent->Remove(this);

	cout << "I grab the " << this->name << " and store it in my inventory." << endl << "  ";

	this->canPick = false;
	this->canDrop = true;

	this->parent = player;
	player->Add(this);
}


// Drops the item if the recipient 'parent' is valid
void Object::Drop(Entity* parent)
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
void Object::DropAction(Entity* parent)
{
	this->parent->Remove(this);

	canPick = true;
	canDrop = false;

	this->parent = parent;
	parent->Add(this);
}