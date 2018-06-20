#pragma once
#ifndef _ZORK_ITEM_
#define _ZORK_ITEM_

#include "object.h"

#include "room.h"
#include "container.h"

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
		bool destroyOnUsedOn;
		list<Entity*> allowedInteractors;

		// Constructor & Destructor
		Item(string name, string description, string placementText, bool visible, bool canPick, bool destroyOnUse, bool destroyOnUsedOn, Entity* parent);
		Item(string name, string description, string placementText, bool visible, bool canPick, bool destroyOnUse, bool destroyOnUsedOn, Entity* allowedInteractor, Entity* parent);
		Item(string name, string description, string placementText, bool visible, bool canPick, bool destroyOnUse, bool destroyOnUsedOn, list<Entity*> allowedInteractors, Entity* parent);
		~Item();
		
		// Actions
		void Use(Entity* target, Entity* location, map<Combination*, Entity*> combinations);
		void UsedOn(void);

	private:
		bool canPick;
		bool canDrop;
		bool canUse;
		bool destroyOnUse;

		bool CanInteract(Entity* entity);
		Result* GetCombination(string name1, string name2, string location, map<Combination*, Entity*> combinations);
};

#endif // !_ZORK_ITEM_

