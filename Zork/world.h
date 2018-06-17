#pragma once
#ifndef _ZORK_WORLD_
#define _ZORK_WORLD_

#include <list>
#include <map>

#include "globals.h"
#include "entity.h"
#include "combinations.h"

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

		// List of Item Combinations
		// All combinations must be linked to an ITEM
		map<Combination*, Entity*> combinations;

		// Updates current player position
		void CurrentPosition(Entity* room);
};

#endif // !_ZORK_WORLD_
