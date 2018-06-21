#include "character.h"

Character::Character(string name, string description, int health) : Entity(name, description)
{
	this->type = CHARACTER;
	this->health = health;
};

bool Character::Alive(void)
{
	return this->health > 0;
}

void Character::Hit(void) 
{
	this->health--;

	if (!this->Alive()) this->Die();
}