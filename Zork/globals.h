#pragma once
#ifndef _ZORK_GLOBALS_
#define _ZORK_GLOBALS_

#include <string>

// List of allowed actions
enum Actions { NONE = 0, LOOK = 1, GO = 2, OPEN = 3, CLOSE = 4, USE = 5, TAKE = 6, DROP = 7, INVENTORY = 8, HELP = 9, ROCK = 10, PAPER = 11, SCISSORS = 12};

enum EntityTypes {ENTITY, ITEM, CONTAINER, ROOM, EXIT, CHARACTER, ENEMY};


// Format for parsed input
struct ParsedInput 
{
	public: 
		Actions action = NONE;
		std::string target = "";
		std::string interactor = "";
};

#endif // !_ZORK_GLOBALS_
