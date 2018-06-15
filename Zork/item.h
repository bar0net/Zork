#pragma once
#ifndef _ZORK_ITEM_
#define _ZORK_ITEM_

#include "entity.h"

class Item : public Entity
{
	public:
		Item(string name, string description, string placementText, bool visible, Entity* parent);
		~Item();

		void SeeContents(void);

	private:
		string placementText = "";
};

#endif // !_ZORK_ITEM_
