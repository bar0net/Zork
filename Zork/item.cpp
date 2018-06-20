#include "item.h"

#include <iostream>

// Constructors
Item::Item(string name, string description, string placementText, bool visible, bool canPick, bool destroyOnUse, bool destroyOnUsedOn, Entity* parent) :
	Object(name, description, placementText, canPick, visible, parent)
{
	this->canPick = canPick;
	this->canDrop = false;
	this->parent = parent;
	this->type = ITEM;
	this->destroyOnUse = destroyOnUse;
	this->destroyOnUsedOn = destroyOnUsedOn;
}

Item::Item(string name, string description, string placementText, bool visible, bool canPick, bool destroyOnUse, bool destroyOnUsedOn, Entity* allowedInteractor, Entity* parent) :
	Item(name, description, placementText, visible, canPick, destroyOnUse, destroyOnUsedOn, parent)
{
	this->allowedInteractors.push_back(allowedInteractor);
}

Item::Item(string name, string description, string placementText, bool visible, bool canPick, bool destroyOnUse, bool destroyOnUsedOn, list<Entity*> allowedInteractors, Entity* parent) :
	Item(name, description, placementText, visible, canPick, destroyOnUse, destroyOnUsedOn, parent)
{
	this->allowedInteractors = allowedInteractors;
}

Item::~Item() 
{ }


// Use the item on the target
void Item::Use(Entity* target, Entity* location, map<Combination*, Entity*> combinations)
{
	// Exit if this item has no allowed interactors
	if (this->allowedInteractors.size() == 0) 
	{
		cout << "You can't use this." << endl << "  ";
		return;
	}

	// If it has interactors, check if the target item is among them
	bool found = CanInteract(target);
	if (!found) 
	{
		cout << "You can't do this." << endl << "  ";
		return;
	}
	
	// if target is an Item, check if there is a viable combination
	if (target->type == ITEM || target->type == ROOM) 
	{
		Result* r = this->GetCombination(this->name, target->name, location->name, combinations);
		
		if (r != NULL)
		{
			if ((*r).item->type == ITEM)
			{
				Item* i = (Item*)(*r).item;
				i->parent = this->parent;
				cout << (*r).msg;

				if (this->parent->name == "player" && i->canPick == true)
				{
					i->parent = this->parent;
					i->canPick = false;
					i->canDrop = true;
				}
				else
				{
					i->parent = location;

					if (target->name != location->name)
						cout << " But you dropped it on the floor.";
				}
				cout << endl << "  ";
				i->parent->Add(i);
			}
			else if ((*r).item->type == EXIT)
			{
				Room* i = (Room*)(*r).item;
				cout << (*r).msg << endl << "  ";
				// i->UsedOn(); // unlock for safety
				location->Add(i);
			}
		}
		else 
		{
			cout << "You try but it doesn't seem to be the right place for that." << endl << "  ";
			return;
		}
	}
	else if(target->type == CONTAINER) 
	{
		cout << "You have succesfully unlocked the " << target->name << endl << "  ";
	}
	else if (target->type == EXIT)
	{
		cout << "You opened the " << target->name << endl << "  ";
	}


	if (this->destroyOnUse) delete this;
	target->UsedOn();
} 


void Item::UsedOn(void) 
{
	if (this->destroyOnUsedOn) delete this;
}


bool Item::CanInteract(Entity* entity)
{
	bool found = false;
	for (list<Entity*>::iterator it = this->allowedInteractors.begin(); it != this->allowedInteractors.cend(); ++it)
	{
		if ((*it) -> name == entity->name)
		{
			found = true;
			break;
		}
	}

	return found;
}

Result* Item::GetCombination(string name1, string name2, string location, map<Combination*, Entity*> combinations)
{
	Combination* c = new Combination(name1, name2, "");

	for (map<Combination*, Entity*>::iterator it = combinations.begin(); it != combinations.cend(); ++it) 
	{
		if (c->inputA == (*it).first->inputA && c->inputB == (*it).first->inputB)
		{
			if ((*it).first->location == "" || (*it).first->location == location)
				return new Result((*it).second, (*it).first->msg);
			else
				return NULL;
		}
	}

	return NULL;
}