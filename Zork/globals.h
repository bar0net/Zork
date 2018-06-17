#pragma once
#ifndef _ZORK_GLOBALS_
#define _ZORK_GLOBALS_

#include <string>

// List of allowed actions
enum Actions { none, look, go, open, close, use, take, drop, inventory};

enum EntityTypes {ENTITY, ITEM, CONTAINER, ROOM, EXIT};

// Format for parsed input
struct ParsedInput 
{
	public: 
		Actions action = none;
		std::string target = "";
		std::string interactor = "";
};

#endif // !_ZORK_GLOBALS_
