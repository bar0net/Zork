#pragma once
#ifndef _ZORK_CHARACTER_
#define _ZORK_CHARACTER_

#include "entity.h"

class Character : public Entity
{
	public:
		Character(string name, string description, int health);
		~Character() {};

		bool Alive(void);
		void virtual Hit(void);
		virtual void Die(void) {};

	//private:
		int health;

};


#endif // !_ZORK_CHARACTER_
