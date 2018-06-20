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

	if (parent != NULL)
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
	if (this->placementText != "")
		cout << this->placementText << endl << "  ";
}

void Exit::Open(void)
{
	if (this->locked)
		cout << "It's locked. You will need some kind of key to open it" << endl << "  ";
	else
		cout << "It's open." << endl << "  ";
}

void Exit::Close(void)
{
	if (this->locked)
		cout << "You can't close that... It's locked." << endl << "  ";
	else
		cout << "This tomb is really old and delicate, I'd better let that open just to be safe." << endl << "  ";
}