#pragma once
#ifndef _ZORK_PLAYER_
#define _ZORK_PLAYER

#include "character.h"

#include <iostream>

class Player : public Character
{
public:
	// Constructor
	Player(string name, string description, int health, int thirst) : Character(name, description, health) 
	{
		this->thirst = thirst;
	};
	
	// Manages when the player gets hit
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

	// Runs every frame while not fighting.
	void Update(void)
	{
		thirst--;

		switch (this->thirst)
		{
			case 80:
				cout << "At this point of the adventure, a nice bottle of fresh water would be nice. " << endl << "  ";
				break;
			case 60:
				cout << "Your stomach starts to growl. Maybe you should have brought some provisions." << endl << "  ";
				break;
			case 40:
				cout << "You start to feel seriously thirsty." << endl << "  ";
				break;
			case 20:
				cout << "Your eyesight is starting to get blurry and your legs are beggining\n  to crumble. You need water, asap." << endl << "  ";
				break;
			case 10:
				cout << "The lack of water is starting to take a toll on your consciousness.\n  You wonder if this is all just a dream." << endl << "  ";
				break;
			case 4:
				cout << "The lack hidration makes you see things. You feel the end is near." << endl << "  ";
				break;
			case 2:
				cout << "Are you seeing a magic water fountain in this room?\n  Every goal seems so close and yet so far." << endl << "  ";
				break;
		}

		if (thirst <= 0) this->health = 0;
	}

	private:
		int thirst;
};

#endif // !_ZORK_PLAYER_

