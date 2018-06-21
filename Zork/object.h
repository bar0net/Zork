#pragma once
#ifndef _ZORK_OBJECT_
#define _ZORK_OBJECT_

#include "entity.h"

class Object : public Entity
{
	public:
		Entity * parent;

		// Constructor & Destructor
		Object(string name, string description, string placementText, bool canPick, bool visible, Entity* parent);
		~Object();

		// Actions
		void Take(Entity* player);
		void Drop(Entity* parent);

		// Display its placement text
		void SeeContents(void);

	private:
		// text to make its presence known
		// when the parent is looked at
		string placementText = "";

		// Can you put the object in your inventory
		bool canPick;

		// Can you take the item out of the inventory
		bool canDrop;

		// support function
		void DropAction(Entity* parent);
};

#endif // !_ZORK_OBJECT_
