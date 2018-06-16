#include "container.h"

#include <iostream>

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


Container::~Container()
{

}


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

void Container::SwapDescription(void)
{
		string dummy = this->descritption;
		this->descritption = this->otherText;
		this->otherText = dummy;
}

void Container::ToogleContentVisibility(bool visible)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.cend(); ++it)
		(*it)->visible = visible;
}

void Container::UsedOn(void)
{
	if (isLocked) 
	{
		isLocked = false;
		this->descritption = this->unlockText;
	}
}