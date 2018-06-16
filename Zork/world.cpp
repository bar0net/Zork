#include "world.h"

#include <iostream>

#include "object.h"
#include "container.h"
#include "item.h"

World::World(void) 
{
	this->player = new Entity("player", "I look wonderful in cargo shorts and a kaki shirt.");

	Entity* desert = new Entity("desert", "You find yourself in front of the entrance of an ancent tomb surrounded by miles of desert.");
	Container* bag = new Container("bag", "", false, "You can see the contents of your bag.", "It's your standard adventure bag with an obscene amount of zips. It's closed.", false, "Your bag lies on the floor. It's too heavy to pick up, though...", true, desert);
	Item* flashlight = new Item("flashlight", "Your standard issued flashlight for adventurers, except the light bulb is busted.", "There is a barely functional flashlight.", true, true, bag);
	
	this->zones.push_back(desert);
	this->current = desert;

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

	// special actions without target
	if (msg.action == inventory)
	{
		string text = this->player->ListContents();

		if (text == "")
			cout << "My inventory is empty." << endl << "  ";
		else
			cout << "I am currently carrying: " << text.substr(0,text.size()-2) << "." << endl << "  ";
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
		target->Take(this->player);
		break;

	case drop:
		target->Drop();
		break;

	default:
		break;
	}
}