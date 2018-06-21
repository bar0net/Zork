#include <iostream>
#include <algorithm>
#include <string>
#include <conio.h>

#include "world.h"
#include "controller.h"
#include "globals.h"

using namespace std;

// Things to be done at the begining of the game
void Start(void)
{
	// Greet the player
	cout << "                      Welcome to myZork!                 " << endl;
	cout << "  ====================================================== " << endl << endl;
	cout << "  After countless hours of driving through the dessert," << endl;
	cout << "  your 'not at all suspicious looking' driver drops you" << endl;
	cout << "  at the gates of the lost tomb of the last king of Anaria." << endl;
	cout << "  You have been looking for this place and the secrets it" << endl;
	cout << "  stores for all your live." << endl;
	cout << "  It seems you are not the first to lay foot on this place," << endl;
	cout << "  but you can't see any signs of recent activity. How odd..." << endl << endl;
	cout << "  ";
}


// Get the player's command from the console
// @returns: the player's command as a lowercase string
string ReadInput(void)
{
	string input;

	getline(cin, input);
	transform(input.begin(), input.end(), input.begin(), tolower);
	cout << endl << "  ";

	return input;
}


// Things to do before closing the game
void End(void)
{
	cout << "Thanks for playing!" << endl << endl;
	cout << "  -- Press any key to close. -- " << endl;
	_getch();
}


int main(void)
{
	Start();

	string input;
	World* world = new World;
	Controller controller;
	
	while (1)
	{
		cout << endl << "  ";

		input = ReadInput();

		if (input == "exit" || input == "quit") break;
		if (!world->player->Alive())
		{
			cout << "\n  You're passion for adventure saw your demise.\n  "
				"You tried valiently, but ultimately you failed.\n  "
				"Your remains will be lost in an unknown tomb in \n  "
				"the desert, until some other crazy adventurer tries\n  "
				"to defy the curse of the last king of Anatria." << endl << endl << "  ";
			break;
		}


		ParsedInput msg = controller.Parse(input, world->Visible());
		world->Update(msg);

		if (world->gameOver) break;
	}

	End();
	return 0;
}
