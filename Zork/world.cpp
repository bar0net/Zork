#include "world.h"

#include <iostream>

World::World(void) 
{
	Entity* lake = new Entity("lake", "You find yourself in a beautiful lake.");
	Entity* lake_box = new Entity("box", "the box is closed.", "There is a small box on the floor.", lake);
	
	this->zones.push_back(lake);
	this->current = lake;

	this->current->Look();
}

World::~World(void) 
{
	for (list<Entity*>::iterator it = this->zones.begin(); it != this->zones.cend(); ++it)
		delete *it;
}

void World::Update(ParsedInput msg)
{
	if (msg.action == none)
	{
		cout << "I don't understand what you want to do..." << endl << "  ";
		return;
	}

	if (msg.target == "")
	{
		cout << "I don't understand what is the target of your action..." << endl << "  ";
		return;
	}

	Entity* target = current->Find(msg.target);
	if (target == NULL) 
	{
		cout << "[World::Update] Could not find the target <<" << msg.target << ">> for this action.";
	}


	switch (msg.action)
	{
	case look:
		target->Look();
		break;

	case go:
		target->Go();
		break;

	case open:
		target->Open();
		break;

	case close:
		target->Close();
		break;

	case use:
		target->Use();
		break;

	case take:
		target->Take();
		break;

	case drop:
		target->Drop();
		break;

	default:
		break;
	}
}