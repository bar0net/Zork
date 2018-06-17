#pragma once
#ifndef _ZORK_GLOBALS_
#define _ZORK_GLOBALS_

#include <string>

// List of allowed actions
enum Actions { NONE, LOOK, GO, OPEN, CLOSE, USE, TAKE, DROP, INVENTORY, HELP};

enum EntityTypes {ENTITY, ITEM, CONTAINER, ROOM, EXIT};

// Format for parsed input
struct ParsedInput 
{
	public: 
		Actions action = NONE;
		std::string target = "";
		std::string interactor = "";
};

#endif // !_ZORK_GLOBALS_
