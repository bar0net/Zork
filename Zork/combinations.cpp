#include "combinations.h"

Combination::Combination(string input1, string input2, string msg) : Combination(input1, input2, msg, "") { }

Combination::Combination(string input1, string input2, string msg, string location)
{
	if (input1 <= input2)
	{
		this->inputA = input1;
		this->inputB = input2;
	}
	else
	{
		this->inputB = input1;
		this->inputA = input2;
	}

	this->location = location;
	this->msg = msg;
}