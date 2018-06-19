#pragma once
#ifndef _ZORK_COMBINATIONS_
#define _ZORK_COMBINATIONS_

#include <string>

using namespace std;

struct Combination
{
	string inputA;
	string inputB ;
	string location;
	
	Combination(string input1, string input2);
	Combination(string input1, string input2, string location);
};

#endif // !_ZORK_COMBINATIONS_

