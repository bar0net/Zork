#include "exit.h"

#include <iostream>

// Constructor
Exit::Exit(string name, string description, string placement, Entity* parent, Entity* destination) :
	Entity(name, description)
{
	this->destination = destination;
	this->locked = false;
	this->placementText = placement;
	this->type = EXIT;

	parent->Add(this);
}

Exit::Exit(string name, string description, string placement, bool locked, Entity* parent, Entity* destination) :
	Exit(name, description, placement, parent, destination)
{
	this->locked = locked;
}

// Destructor
Exit::~Exit() {};


Entity* Exit::Go(void) 
{
	if (!locked) return this->destination;

	cout << "This exit is locked." << endl << "  ";
	return NULL;
}

void Exit::UsedOn(void)
{
	this->locked = false;
}

void Exit::SeeContents(void) 
{
	cout << this->placementText << endl << "  ";
}
