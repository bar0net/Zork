#pragma once
#ifndef _ZORK_CHARACTER_
#define _ZORK_CHARACTER_

#include "entity.h"

class Character : public Entity
{
	public:
		// The hit points of the Character
		int health;

		// Constructor & Destructor
		Character(string name, string description, int health);
		~Character() {};

		// Checks if the character is alive
		bool Alive(void);

		// Manages the consequences of getting hit
		void virtual Hit(void);
		
		// Manages the consequences of losing all health
		virtual void Die(void) {};
};


#endif // !_ZORK_CHARACTER_
