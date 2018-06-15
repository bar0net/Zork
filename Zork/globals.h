#pragma once
#ifndef _ZORK_GLOBALS_
#define _ZORK_GLOBALS_

#include <string>

enum Actions { none, look, go};

struct ParsedInput 
{
	public: 
		Actions action = none;
		std::string target = "";
};


#endif // !_ZORK_GLOBALS_
