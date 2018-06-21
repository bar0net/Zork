#pragma once
#ifndef _ZORK_ENEMY_
#define _ZORK_ENEMY_

#include "character.h"

class Enemy : public Character
{
public:

	// Constructor & Destructor
	Enemy(string name, string description, int health, string deathMsg, Entity* parent);
	~Enemy();
	
	// It runs every frame an enemy is the active target
	Actions Update(void);

	// Manages the consequences of losing all health
	void Die(void);

private:
	// A message to show when the enemy dies
	string deathMsg;

	// The parent entity of this enemy 
	Entity* parent;
};


#endif // !_ZORK_ENEMY_
