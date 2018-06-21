#pragma once
#ifndef _ZORK_COMBINATIONS_
#define _ZORK_COMBINATIONS_

#include <string>

using namespace std;

// Manage Combinations of Items
struct Combination
{
	public:
		// The 2 Items used
		// ItemA <= ItemB
		string inputA;
		string inputB ;

		// The location should be not null
		// if the location where the use of
		// both items is binding
		string location;

		// The message to output when the combination
		// takes place
		string msg;
	
		// Constructor & Destructor
		Combination(string input1, string input2, string msg);
		Combination(string input1, string input2, string msg, string location);
};

#endif // !_ZORK_COMBINATIONS_

