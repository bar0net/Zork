#pragma once
#ifndef _ZORK_GLOBALS_
#define _ZORK_GLOBALS_

#include <string>

// List of allowed actions
enum Actions { none, look, go, open, close, use, take, drop, inventory};

// Format for parsed input
struct ParsedInput 
{
	public: 
		Actions action = none;
		std::string target = "";
		std::string interactor = "";
};


#endif // !_ZORK_GLOBALS_
