#pragma once
#ifndef _ZORK_ITEM_
#define _ZORK_ITEM_

#include "object.h"

class Item : public Object
{
	public:
		Entity* parent;

		// Constructor & Destructor
		Item(string name, string description, string placementText, bool visible, bool canPick, Entity* parent);
		Item(string name, string description, string placementText, bool visible, bool canPick, Entity* allowedInteractor, Entity* parent);
		Item(string name, string description, string placementText, bool visible, bool canPick, list<Entity*> allowedInteractors, Entity* parent);
		~Item();
		
		// Actions
		void Take(Entity* parent);
		void Drop(Entity* parent);
		void Use(Entity* target);

	private:
		bool canPick;
		bool canDrop;
		bool canUse;

		list<Entity*> allowedInteractors;
};

#endif // !_ZORK_ITEM_

