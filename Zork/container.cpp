#include "container.h"

#include <iostream>

// Constructor
Container::Container(string name, string lockedText, bool isLocked, string openText, string closedText, bool isOpen, string placementText, bool visible, Entity* parent) :
	Object(name, lockedText, placementText, visible, parent)
{
	this->isOpen = isOpen;
	this->isLocked = isLocked;

	if (isOpen)
	{
		this->unlockText = openText;
		this->otherText = closedText;
	}
	else
	{
		this->unlockText = closedText;
		this->otherText = openText;
	}
		
	if (!isLocked) this->descritption = this->unlockText;
}


// Destructor
Container::~Container() {}


//Action: Look
void Container::Look(void)
{
	Entity::Look();

	if (contains.size() == 0)
		cout << "It's empty." << endl << "  ";
}

// ACTION: Open
void Container::Open(void)
{
	if (isLocked)
	{
		cout << "It's locked." << endl << "  ";
		return;
	}

	if (isOpen)
		cout << "It's already open." << endl << "  ";
	else
	{
		this->isOpen = true;
		SwapDescription();
		ToogleContentVisibility(true);

		cout << "You open the " << this->name << "." << endl << "  ";
	}
}


// ACTION: Close
void Container::Close(void)
{
	if (isOpen)
	{
		this->isOpen = false;
		SwapDescription();
		ToogleContentVisibility(false);

		cout << "You closed the " << this->name << "." << endl << "  ";
	}
	else
		cout << "It's already closed." << endl << "  ";
}


// ACTION: is the recipient of Use
// The container should be unlocked if the appropiate key is used on it
void Container::UsedOn(void)
{
	if (isLocked) 
	{
		isLocked = false;
		this->descritption = this->unlockText;
	}
}


// Swap entity's description and otherText
void Container::SwapDescription(void)
{
		string dummy = this->descritption;
		this->descritption = this->otherText;
		this->otherText = dummy;
}


// Sets all contained entities visibility to 'visible'
// #visible: whether the contained items should be visible or not
void Container::ToogleContentVisibility(bool visible)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.cend(); ++it)
		(*it)->visible = visible;
}
