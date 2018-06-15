#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Things to be done at the begining of the game
void Start(void)
{
	// Greet the player
	cout << "    Welcome to myZork!    " << endl;
	cout << "  ======================  " << endl << endl;
	cout << "  ";
}


// Get the player's command from the console
// @returns: the player's command as a lowercase string
string ReadInput(void)
{
	string input;

	getline(cin, input);
	transform(input.begin(), input.end(), input.begin(), tolower);
	cout << "  ";

	return input;
}


// Things to do before closing the game
void End(void)
{
	cout << "Thanks for playing!  " << endl;
}


int main(void)
{
	string input;

	Start();

	while (1)
	{
		input = ReadInput();

		if (input == "exit") break;
	}

	End();
	return 0;
}
