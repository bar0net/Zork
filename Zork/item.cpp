#include "item.h"

#include <iostream>

Item::Item(string name, string description, string placementText, bool visible, Entity* parent) :
Entity(name, description)
{
	this->placementText = placementText;
	this->visible = visible;

	parent->Add(this);
}

Item::~Item() {}

void Item::SeeContents(void)
{
	if (!this->visible) return;

	cout << this->placementText << endl << "  ";
}
