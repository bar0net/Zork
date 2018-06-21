#include "enemy.h"

#include <iostream>
#include <random>
#include <ctime>

Enemy::Enemy(string name, string description, int health, string deathMsg, Entity* parent) : Character(name, description, health)
{
	this->deathMsg = deathMsg;
	this->parent = parent;
	parent->Add(this);
	this->type = ENEMY;
	std::srand(std::time(nullptr));
}

Enemy::~Enemy()
{
	this->parent->Remove(this);
}

void Enemy::Die(void) 
{
	std::cout << this->deathMsg << std::endl << "  ";
}

Actions Enemy::Update(void)
{
	int num = rand() % 3;

	if (num == 0) 
	{
		return ROCK;
	}
	else if (num == 1) 
	{
		return PAPER;
	}
	else 
	{
		return SCISSORS;
	}
}