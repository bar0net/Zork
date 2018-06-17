#include "combinations.h"

Combination::Combination(string input1, string input2)
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
}