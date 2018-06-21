#pragma once
#ifndef _ZORK_PLAYER_
#define _ZORK_PLAYER

#include "character.h"

#include <iostream>

class Player : public Character
{
public:
	Player(string name, string description, int health) : Character(name, description, health) {};
	void Hit(void) 
	{
		Character::Hit();
		switch (this->health)
		{
		case 5:
			cout << "You now have some bruises and scratches. " << endl << "  ";
			break;
		case 3:
			cout << "You are starting to bleed. " << endl << "  ";
			break;
		case 2:
			cout << "You feel nausiated and your vision is getting blurry." << endl << "  ";
			break;
		case 1:
			cout << "You feel the frozen breath of the grim reaper.\n  For better or worse, you know the end is near." << endl << "  ";
			break;
		default:
			break;
		}
	}
};

#endif // !_ZORK_PLAYER_

