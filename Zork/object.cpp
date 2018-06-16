#include "object.h"

#include <iostream>

Object::Object(string name, string description, string placementText, bool visible, Entity* parent) :
Entity(name, description)
{
	this->placementText = placementText;
	this->visible = visible;

	parent->Add(this);
}

Object::~Object() {}

void Object::SeeContents(void)
{
	if (!this->visible) return;

	cout << this->placementText << endl << "  ";
}
