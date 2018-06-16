#pragma once
#ifndef _ZORK_ITEM_
#define _ZORK_ITEM_

#include "entity.h"

class Object : public Entity
{
	public:
		Object(string name, string description, string placementText, bool visible, Entity* parent);
		~Object();

		void SeeContents(void);

	private:
		string placementText = "";
};

#endif // !_ZORK_ITEM_
