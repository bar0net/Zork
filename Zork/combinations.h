#pragma once
#ifndef _ZORK_COMBINATIONS_
#define _ZORK_COMBINATIONS_

#include <string>

using namespace std;

struct Combination
{
	public:
		string inputA;
		string inputB ;
		string location;
		string msg;
	
		Combination(string input1, string input2, string msg);
		Combination(string input1, string input2, string msg, string location);
};

#endif // !_ZORK_COMBINATIONS_

