#pragma once
#ifndef _ZORK_CONTROLLER_
#define _ZORK_CONTROLLER_

#include <string>
#include <map>
#include <list>

#include "globals.h"

using namespace std;

class Controller 
{

	public:
		// Constructor & Destructor
		Controller();
		~Controller();

		// Convert an light-formatted input (all in lower case) to
		// a convenient message type to pass to the game
		ParsedInput Parse(string input, list<string> targets);

	private:
		// A map linking possible spellings of a command
		// to one of the allowed actions
		map<string, Actions> translate;

		// A list of the possible spellings of a command
		// ** we used to check the input and then we
		// ** use the translate map to get the action
		list<string> commands;

};

#endif // !_ZORK_CONTROLLER_
