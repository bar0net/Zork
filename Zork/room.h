#pragma once
#ifndef _ZORK_ROOM_
#define _ZORK_ROOM_

#include "entity.h"

class Room : public Entity
{
	public:
		Room(string name, string description) : Entity(name, description) { this->type = ROOM; };
		~Room() {};
};

#endif // !_ZORK_ROOM_
