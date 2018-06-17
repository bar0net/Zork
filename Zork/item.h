#pragma once
#ifndef _ZORK_ITEM_
#define _ZORK_ITEM_

#include "object.h"

#include "room.h"
#include "container.h"

class Item : public Object
{
	public:
		Entity* parent;

		// Constructor & Destructor
		Item(string name, string description, string placementText, bool visible, bool canPick, bool destroyOnUse, Entity* parent);
		Item(string name, string description, string placementText, bool visible, bool canPick, bool destroyOnUse, Entity* allowedInteractor, Entity* parent);
		Item(string name, string description, string placementText, bool visible, bool canPick, bool destroyOnUse, list<Entity*> allowedInteractors, Entity* parent);
		~Item();
		
		// Actions
		void Take(Entity* parent);
		void Use(Entity* target);
		void Drop(Entity* parent);

	private:
		bool canPick;
		bool canDrop;
		bool canUse;
		bool destroyOnUse;

		list<Entity*> allowedInteractors;
		void Drop(Room* parent);
		void Drop(Container* parent);
		void DropAction(Entity* parent);
};

#endif // !_ZORK_ITEM_

