#pragma once
#ifndef _ZORK_CHARACTER_
#define _ZORK_CHARACTER_

#include "entity.h"

class Character : public Entity
{
	public:
		Character(string name, string description) : Entity(name, description) { this->type = CHARACTER; };
		~Character() {};

		bool Alive(void) { return health > 0; }

	private:
		int health = 5;

};


#endif // !_ZORK_CHARACTER_
