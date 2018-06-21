#pragma once
#ifndef _ZORK_ENEMY_
#define _ZORK_ENEMY_

#include "character.h"

class Enemy : public Character
{
public:
	Enemy(string name, string description, int health, string deathMsg, Entity* parent);
	~Enemy();
	
	Actions Update(void);
	void Die(void);

private:
	string deathMsg;
	Entity* parent;
};


#endif // !_ZORK_ENEMY_
