#include "controller.h"


Controller::Controller() 
{
	translate["look"] = look;

	translate["go"] = go;
	translate["walk"] = go;
	translate["run"] = go;

	translate["open"] = open;

	translate["close"] = close;

	translate["use"] = use;

	translate["take"] = take;
	translate["grab"] = take;

	translate["drop"] = drop;

	for (map<string, Actions>::iterator it = translate.begin(); it != translate.cend(); ++it)
		this->commands.push_back(it->first);
}

Controller::~Controller() 
{	

}

ParsedInput Controller::Parse(string input, list<string> targets)
{
	ParsedInput output;

	// Get the action
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
