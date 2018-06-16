#include "object.h"

#include <iostream>

// Constructor
Object::Object(string name, string description, string placementText, bool visible, Entity* parent) :
Entity(name, description)
{
	this->placementText = placementText;
	this->visible = visible;

	parent->Add(this);
}

// Destructor
Object::~Object() {}

// Display its placement text
void Object::SeeContents(void)
{
	if (!this->visible) return;

	cout << this->placementText << endl << "  ";
}
