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
		Controller();
		~Controller();

		ParsedInput Parse(string input, list<string> targets);

	private:
		map<string, Actions> translate;
		list<string> commands;

};

#endif // !_ZORK_CONTROLLER_
