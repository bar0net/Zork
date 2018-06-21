#pragma once
#ifndef _ZORK_ITEM_
#define _ZORK_ITEM_

#include "object.h"

#include "room.h"
#include "container.h"

// A convinient data structure to communicate internally
struct Result
{
	Entity* item;
	string msg;

	Result(Entity* item, string msg)
	{
		this->item = item;
		this->msg = msg;
	}
};


class Item : public Object
{
	public:
		// Should this object be destroyed after a successful use?
		// when it's not the primary target of the command use 
		// Explained later with Use and UsedOn
		bool destroyOnUsedOn;

		// The list of entites that this item can interact with
		list<Entity*> allowedInteractors;

		// Constructor & Destructor
		Item(string name, string description, string placementText, bool visible, bool canPick, bool destroyOnUse, bool destroyOnUsedOn, Entity* parent);
		Item(string name, string description, string placementText, bool visible, bool canPick, bool destroyOnUse, bool destroyOnUsedOn, Entity* allowedInteractor, Entity* parent);
		Item(string name, string description, string placementText, bool visible, bool canPick, bool destroyOnUse, bool destroyOnUsedOn, list<Entity*> allowedInteractors, Entity* parent);
		~Item();
		
		// Actions
		// Given a valid interaction "Use item1 on item2"
		// Use will be called for item1
		// UsedOn will be called for Item2
		void Use(Entity* target, Entity* location, map<Combination*, Entity*> combinations);
		void UsedOn(void);

	private:
		// Can it be moved to the inventory
		bool canPick;

		// Can it be moved outside the inventory
		bool canDrop;

		// Can be a target of the Use command
		bool canUse;

		// Should this object be destroyed after a successful use?
		bool destroyOnUse;

		// Checks if this item can interact with the secondary entity
		bool CanInteract(Entity* entity);

		// Find the proper combination and parses it to a convenient format
		Result* GetCombination(string name1, string name2, string location, map<Combination*, Entity*> combinations);
};

#endif // !_ZORK_ITEM_

