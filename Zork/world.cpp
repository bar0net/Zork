#include "world.h"

#include <iostream>

#include "object.h"
#include "container.h"
#include "item.h"
#include "exit.h"

World::World(void) 
{
	this->player = new Entity("player", "I look wonderful in cargo shorts and a kaki shirt.");

	// Zones
	Entity* desert = new Entity("desert", "You find yourself in front of the entrance of an ancent tomb surrounded by miles of desert.");
	Entity* entrance = new Entity("entrance", 
		"The entrance hall is deemly lit. Looking at the vivid pictograms\n  that decorate this stance," 
		" it becomes clear that the last king of\n  Anatria was powerful and beloved by his subjects.");
	Entity* mural = new Entity("mural",
		"There is a huge mural presiding the stance. The scene depicts the funeral of the king.\n  "
		"You can see some priests embalming the late king's body while servants store bast amounts\n  "
		"of richess with the sarcophagus.\n  "
		"On closer inspection, you can see some human remains at the corner of the room. They were\n  "
		"the paintors who got trapped in the tomb. No trace of the riches, though...");
	Entity* rubble = new Entity("rubble",
		"This room has clearly been closed for centuries and the dust has settled. Even though there\n  "
		"is little light in this stance, you can distinguish some rubble on the floor as some walls\n  "
		"has clearly collapsed.");


	this->zones.push_back(desert);
	this->zones.push_back(entrance);
	this->zones.push_back(mural);
	this->zones.push_back(rubble);

	// Define Exits
	Exit* desert_north = new Exit("north", "Two massive stone columns welcome you to the temple.", "The entrance to the temple lies to the north.", desert, entrance);

	Exit* entrance_south = new Exit("south", "Two massive stone columns preside the exit of the temple.", "The gates to the desert lie to the south.", entrance, desert);
	Exit* entrance_east = new Exit("east", "The door has rusted and the decorations have deteriorated.\n  Time has clearly takem its toll on this door.",
		"You can see a rusted door to the east.", true, entrance, rubble);
	Exit* entrance_north = new Exit("north", "You can see a long hallway with pictograms on the walls and long extinguished torches.", "On the northern part of"
		"of the room, you can see a long hallway", entrance, mural);

	Exit* rubble_west = new Exit("west", "You can see a glimpse of the entrance hall through the door.", 
		"Through the darkness, you can sense the rusted door to the west.", rubble, entrance);

	Exit* mural_south = new Exit("south", "You can see a long hallway with pictograms on the walls and long extinguished torches.",
		"On the southern part of the room, you can see a long hallway", mural, entrance);

	// Desert contents
	Container* bag = new Container("bag", "", false, "You can see the contents of your bag.", 
		"It's your standard adventure bag with an obscene amount of zips. It's closed.", false, 
		"Your bag lies on the floor. It's too heavy to pick up, though...", true, desert);
	
	Item* flashlight = new Item("flashlight", "Your standard issued flashlight for adventurers, except the light bulb is busted.", 
		"There is a barely functional flashlight.", true, true, bag);
	



	this->current = desert;
	this->current->Look();
}

World::~World(void) 
{
	for (list<Entity*>::iterator it = this->zones.begin(); it != this->zones.cend(); ++it)
		delete *it;
}

void World::Update(ParsedInput msg)
{
	if (msg.action == none)
	{
		cout << "I don't understand what you want to do..." << endl << "  ";
		return;
	}

	// special actions without target
	if (msg.action == inventory)
	{
		string text = this->player->ListContents();

		if (text == "")
			cout << "My inventory is empty." << endl << "  ";
		else
			cout << "I am currently carrying: " << text.substr(0,text.size()-2) << "." << endl << "  ";
		return;
	}


	if (msg.target == "")
	{
		cout << "I don't understand what is the target of your action..." << endl << "  ";
		return;
	}

	Entity* target = current->Find(msg.target);
	if (target == NULL) 
	{
		cout << "[World::Update] Could not find the target <<" << msg.target << ">> for this action.";
	}


	switch (msg.action)
	{
	case look:
		target->Look();
		break;

	case go:
		CurrentPosition(target->Go());
		break;

	case open:
		target->Open();
		break;

	case close:
		target->Close();
		break;

	case use:
		target->Use();
		break;

	case take:
		target->Take(this->player);
		break;

	case drop:
		target->Drop();
		break;

	default:
		break;
	}
}


// Update current player position
void World::CurrentPosition(Entity* room)
{
	if (room == NULL) return;
		
	this->current = room;

	this->current->Look();
}