#pragma once
#ifndef _ZORK_WORLD_
#define _ZORK_WORLD_

#include <list>
#include <map>

#include "globals.h"
#include "entity.h"
#include "combinations.h"
#include "player.h"
#include "enemy.h"

class World
{
	public:
		// Constructor & Destructor
		World();
		~World();

		// player description and inventory
		Player* player;

		// Things to do every frame
		void Update(ParsedInput msg);

		// Return the list of visible entities in the current zone
		list<string> Visible();

		// Have we reach a successful end of the game
		bool gameOver = false;


	private:
		// list of zones in this world
		list<Entity*> zones;

		// zone where the player is standing
		Entity* current;

		// List of Item Combinations
		// All combinations must be linked to an ITEM
		map<Combination*, Entity*> combinations;

		// Updates current player position
		void CurrentPosition(Entity* room);

		Enemy* enemy = NULL;

		void SearchEnemy(void);

		void NeutralState(ParsedInput msg);
		void FightState(ParsedInput msg);
};

#endif // !_ZORK_WORLD_
