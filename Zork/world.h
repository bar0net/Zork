#pragma once
#ifndef _ZORK_WORLD_
#define _ZORK_WORLD_

#include <list>

#include "entity.h"
#include "globals.h"

class World
{
	public:
		// Constructor & Destructor
		World();
		~World();

		// Things to do every frame
		void Update(ParsedInput msg);

		// Return the list of visible entities in the current zone
		list<string> Visible();


	private:
		// list of zones in this world
		list<Entity*> zones;

		// zone where the player is standing
		Entity* current;

		// player description and inventory
		Entity* player;

		// Updates current player position
		void CurrentPosition(Entity* room);
};

#endif // !_ZORK_WORLD_
