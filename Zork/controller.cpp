#include "controller.h"


Controller::Controller() 
{
	// associate key words with allowed action
	translate["look"] = look;
	translate["read"] = look;

	translate["go"] = go;
	translate["walk"] = go;
	translate["run"] = go;

	translate["open"] = open;

	translate["close"] = close;

	translate["use"] = use;

	translate["take"] = take;
	translate["grab"] = take;

	translate["drop"] = drop;

	translate["inventory"] = inventory;

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
		int length = (*it).size();
		if (input.size() < length) continue;

		if (input.substr(0, length) != (*it)) continue;
				
		output.action = translate[(*it)];
		break;
	}
	if (output.action == none) return output;
	

	// Find the target
	// TODO: check if more than one target is found
	for (list<string>::iterator it = targets.begin(); it != targets.cend(); ++it) 
	{
		size_t found = input.find((*it));

		if (found != string::npos) 
		{
			output.target = (*it);
			break;
		}
	}
	return output;
}
