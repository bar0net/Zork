#pragma once
#ifndef _ZORK_OBJECT_
#define _ZORK_OBJECT_

#include "entity.h"

class Object : public Entity
{
	public:
		// Constructor & Destructor
		Object(string name, string description, string placementText, bool visible, Entity* parent);
		~Object();

		// Display its placement text
		void SeeContents(void);

	private:
		// text to make its presence known
		// when the parent is looked at
		string placementText = "";
};

#endif // !_ZORK_OBJECT_
