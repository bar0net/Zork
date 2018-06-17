#include "controller.h"


Controller::Controller() 
{
	// associate key words with allowed action
	translate["look"] = LOOK;
	translate["read"] = LOOK;
	translate["glance"] = LOOK;

	translate["go"] = GO;
	translate["walk"] = GO;
	translate["run"] = GO;
	translate["cross"] = GO;

	translate["open"] = OPEN;

	translate["close"] = CLOSE;

	translate["use"] = USE;
	translate["employ"] = USE;

	translate["take"] = TAKE;
	translate["grab"] = TAKE;
	translate["pick"] = TAKE;

	translate["drop"] = DROP;
	translate["put"] = DROP;
	translate["leave"] = DROP;

	translate["inventory"] = INVENTORY;

	translate["help"] = HELP;

	for (map<string, Actions>::iterator it = translate.begin(); it != translate.cend(); ++it)
		this->commands.push_back(it->first);
}

Controller::~Controller() 
{	

}

// Transform input text to a convinient format
// #input: lowercase input text
// #targets: list of visible entities that can be the target of the action
// @returns: conviniently formated input
ParsedInput Controller::Parse(string input, list<string> targets)
{
	ParsedInput output;

	// Get the action
	// we asume the action is the first word of the input
	for (list<string>::iterator it = commands.begin(); it != commands.cend(); ++it)
	{
		unsigned int length = (*it).size();
		if (input.size() < length) continue;

		if (input.substr(0, length) != (*it)) continue;
				
		output.action = translate[(*it)];
		break;
	}
	if (output.action == NONE) return output;
	

	// Find the target
	// TODO: Create a new action for when you input too many targets (?)
	// TODO: Check actions that want 1 and actions that want 2 targets.

	unsigned int index = string::npos;
	for (list<string>::iterator it = targets.begin(); it != targets.cend(); ++it) 
	{
		size_t found = input.find((*it));

		if (found != string::npos)
		{
			if (output.target == "")
			{
				output.target = (*it);
				index = found;
			}
			else if (output.target != "" && output.interactor != "")
			{
				output.action = NONE;
				return output;
			}
			else if (output.target != ""  && found <= index)
			{
				output.interactor = output.target;
				output.target = (*it);
				index = -1;
			}
			else if (output.target != "" && found > index)
			{
				output.interactor = (*it);
				index = -1;
			}
		}
	}
	return output;
}
