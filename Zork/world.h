#pragma once
#ifndef _ZORK_WORLD_
#define _ZORK_WORLD_

#include <list>

#include "entity.h"
#include "globals.h"

class World
{
	public:
		World();
		~World();

		void Update(ParsedInput msg);

		list<string> Visible() { return current->Visible(); };

	private:
		list<Entity*> zones;
		Entity* current;
};

#endif // !_ZORK_WORLD_
