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
	if (this->allowedInteractors.size() == 0) 
	{
		cout << "You can't use this." << endl << "  ";
		return;
	}

	bool found = CanInteract(target);

	if (!found) 
	{
		cout << "You can't do this." << endl << "  ";
		return;
	}

	cout << "You used the " << this->name << " on the " << target->name;

	if (target->type == ITEM) 
	{
		Item* i = (Item*)this->GetCombination(this->name, target->name, location->name, combinations);
		
		if (i != NULL)
		{
			i->parent = this->parent;

			cout << " and you created a " << i->name;
			if (this->parent->name == "player")
			{
				i->parent = this->parent;
				cout << " and you put it on your inventory";
			}
			else
			{
				i->parent = location;
				cout << " and your left it on the floor";
			}
			i->parent->Add(i);
		}
		else 
		{
			cout << " but it doesn't seem to be the right place for that" << endl << "  ";
			return;
		}
	}
	cout << "." << endl << "  ";


	if (this->destroyOnUse) 
	{
		cout << this->name;
		delete this;
	}
	if (target->type == ITEM) 
	{
		if (((Item*)target)->destroyOnUsedOn) cout << " and " << target->name;
	}
	cout << " got destroyed." << endl << "  ";

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

Entity* Item::GetCombination(string name1, string name2, string location, map<Combination*, Entity*> combinations)
{
	Combination* c = new Combination(name1, name2);

	for (map<Combination*, Entity*>::iterator it = combinations.begin(); it != combinations.cend(); ++it) 
	{
		if (c->inputA == (*it).first->inputA && c->inputB == (*it).first->inputB)
		{
			if ((*it).first->location == "" || (*it).first->location == location)
				return (*it).second;
			else
				return NULL;
		}
	}

	// cout << "[DEBUG] NO MAP" << endl << "  ";

	return NULL;
}