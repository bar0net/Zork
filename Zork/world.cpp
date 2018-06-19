#include "world.h"

#include <iostream>

#include "object.h"
#include "container.h"
#include "item.h"
#include "exit.h"
#include "room.h"

World::World(void) 
{
	this->player = new Character("player", "I look wonderful in cargo shorts and a kaki shirt.");

	// Zones
	Room* desert = new Room("desert", "You find yourself in front of the entrance of an ancent\n  tomb surrounded by miles of desert.");
	Room* entrance = new Room("entrance",
		"The entrance hall is deemly lit. Looking at the vivid pictograms\n  that decorate this stance," 
		" it becomes clear that the last king of\n  Anatria was powerful and beloved by his subjects.");
	Room* mural = new Room("mural",
		"There is a huge mural presiding the stance. The scene depicts the funeral of the king.\n  "
		"You can see some priests embalming the late king's body while servants store bast amounts\n  "
		"of richess with the sarcophagus.\n  "
		"On closer inspection, you can see some human remains at the corner of the room. They were\n  "
		"the paintors who got trapped in the tomb. No trace of the riches, though...");
	Room* rubble = new Room("rubble",
		"This room has clearly been closed for centuries and the dust has settled. Even though there\n  "
		"is little light in this stance, you can distinguish some rubble on the floor as some walls\n  "
		"has clearly collapsed.");
	Room* chamber = new Room("chamber", "You find yourself in a dark chamber.");
	Room* workshop = new Room("workshop", "This appears to be a small room used by the artisans who worked on the tomb.\n  "
		"You can see the rests of some old broken tools, they don't work\n  "
		"anymore but they would make a hell of an exhibition in a museum.");

	this->zones.push_back(desert);
	this->zones.push_back(entrance);
	this->zones.push_back(mural);
	this->zones.push_back(rubble);

	// Define Exits
	Exit* desert_north = new Exit("north", "Two massive stone columns welcome you to the temple.", "The entrance to the temple lies to the north.", desert, entrance);
	Exit* desert_gates = new Exit("gates", "Two massive stone columns welcome you to the temple.", "", desert, entrance);

	Exit* entrance_south = new Exit("south", "Two massive stone columns preside the exit of the temple.", "The gates to the desert lie to the south.", entrance, desert);
	Exit* entrance_gates = new Exit("gates", "Two massive stone columns preside the exit of the temple.", "", entrance, desert);
	Exit* entrance_east = new Exit("door", "The door has rusted and the decorations have deteriorated.\n  Time has clearly takem its toll on this door.",
		"There is a rusted door at one side of the room.", true, entrance, rubble);
	Exit* entrance_north = new Exit("north", "You can see a long hallway with pictograms on the walls and long extinguished torches.", "On the northern part of"
		"of the room, you can see a long hallway", entrance, mural);
	Exit* entrance_hallway = new Exit("hallway", "You can see a long hallway with pictograms on the walls and long extinguished torches.", "", entrance, mural);

	Exit* rubble_west = new Exit("west", "You can see a glimpse of the entrance hall through the door.", 
		"Through the darkness, you can sense the rusted door to the west.", rubble, entrance);
	Exit* rubble_door = new Exit("door", "You can see a glimpse of the entrance hall through the door.",
		"", rubble, entrance);

	Exit* mural_south = new Exit("south", "You can see a long hallway with pictograms on the walls and long extinguished torches.",
		"On the southern part of the room, you can see a long hallway", mural, entrance);
	Exit* mural_hallway = new Exit("hallway", "You can see a long hallway with pictograms on the walls and long extinguished torches.", "", mural, entrance);
	Exit* mural_west = new Exit("west", "You can see a small door on the west wall, it seems to be decorated with pictograms of artisans and crafters.",
		"There is a small door in the west wall.", mural, chamber);
	Exit* mural_door = new Exit("door", "You can see a small door on the west wall, it seems to be decorated with pictograms of artisans and crafters.", "", mural, chamber);

	Exit* chambers_east = new Exit("east", "Through the small door you can catch a glipse of the amazing mural on the room ahead.",
		"You can see a small door along the east wall.", chamber, mural);
	Exit* chambers_door = new Exit("door", "Through the small door you can catch a glipse of the amazing mural on the room ahead.", "", chamber, mural);
	Exit* chambers_hole = new Exit("hole", "This tomb is not inmune to the hazards of time. A collapse has created a hole were there used to be a door.",
		"There's a hole on the southern wall of this chamber", chamber, workshop);
	Exit* chambers_south = new Exit("south", "This tomb is not inmune to the hazards of time." 
		"A collapse has created a hole were there used to be a door.", "", chamber, workshop);

	Exit* workshop_north = new Exit("north", "Sismic activity has transformed what it used to be a door into a hole. It looks safe to cross at the moment...",
		"There is a hole in the northern part of the workshop", workshop, chamber);
	Exit* workshop_hole = new Exit("hole", "Sismic activity has transformed what it used to be a door into a hole. It looks safe to cross at the moment...", "", workshop, chamber);

	// Desert contents
	Container* bag = new Container("bag", "", false, "You can see the contents of your bag.", 
		"It's your standard adventure bag with an obscene amount of zips. It's closed.", false, 
		"Your bag lies on the floor. It's too heavy to pick up, though...", false, true, desert);
	
	Container* flashlight = new Container("flashlight", "" , false, 
		"Your standard issued flashlight for adventurers. The battery compartment is open.",
		"Your standard issued flashlight for adventurers, except the light bulb is busted.", false,
		"There is a barely functional flashlight.", true, true, bag);

	Item* battery = new Item("battery", "This is the battery of your flashlight. It's still charged.", "There is a battery.", false, true, true, true, flashlight);
	
	Item* sand = new Item("sand", "There's sand for as long as the eye can see. The dunes shift slightly with every gust \n  "
		"of wind and it and you can't avoid thinking about the many wonders that may lay buried under them.",
		"The tomb is surrounded by an unhospitable desert with sand\n  shining defiant under the blazing sun.", true, false, false, false, desert);

	// Mural Contents
	Item* cables = new Item("cables", "A handful of copper cables.", "There are some copper cables.", true, true, true, true, mural);
	Container* cam_case = new Container("case", "It's an old camera case, probably from the 1970s. It has a small combination padlock.", true, 
		"It's an old camera case, probably from the 1970s.", "It's an old camera case, probably from the 1970s.", 
		false, "You can see an old case on the floor.", false, true, mural);
	Item* camera = new Item("camera", "It's just an old camera and it seems to be mostly broken.", "There is a camera",
		false, true, true, true, cam_case);
	Item* stuck_lens = new Item("lens", "The lens is stuck in the camera, maybe a gentle hit would losen it.", "The only part that seems salvageable is the lens.", true,
		false, true, true, camera);

	// Rubble Room Contents
	Item* red_orb = new Item("red orb", "It appears to a ceramic material with a crystaline structure but it glows in the dark and you can't fathom why.", 
		"You can see a glowing red orb.", true, true, true, true, rubble);
	Item* vase = new Item("vase", "It's an old vase with a strange viscous liquid inside. Is this goo flamable?",
		"Thanks to a faint streak of light, you can see a small vase in the chamber.", true, false, true, true, chamber);

	// Chamber Contents
	Item* corpse = new Item("corpse", "By his attire, you adventure to guess he was an archeologist but he appears to have been dead for decades.\n  "
		"At this point, you can't say what was the cause of his demise. Thirst? Starvation? Health issue? Or maybe\n  "
		"something else... ", "There is a rotten corpse near the entrance of the room.", true, false, false, false, chamber);
	Item* combination = new Item("paper", "It's a small piece of paper with a combination in it.", "You can see a piece of paper sticking out.", true, true, true, true, cam_case, corpse);

	// Workshop Contents
	Item* tools = new Item("tools", "There is a bunch of old, mostly rusted and almost destroyed tools.",
		"In one corner of the room you can see a collection of tools probably used by\n  the artisans who worked on the tomb", true, false, false, false, workshop);
	Item* rod = new Item("rod", "A metal rod.", "There's a metal rod.", true, true, true, true, cables, tools);
	cables->allowedInteractors.push_back(rod);
	Item* stick = new Item("wood", "An undefined type of wood of some sorts. It's a little moist, though...", "There is some wood.", true, true, true, true, vase, tools);
	Item* hammer = new Item("hammer", "It's an old ceremonial hammer. It seems really fragile.", "You can see a hammer.", true, true, true, true, stuck_lens, tools);
	stuck_lens->allowedInteractors.push_back(hammer);
	Item* tongs = new Item("tongs", "These tongs were made by a good blacksmith.\n  They are not only still functional, but also they have quite fancy engravings.",
		"There are some tongs.", true, true, false, false, tools);

	// Item Combinations
	Item* coil = new Item("coil", "A magnetic coil without a battery.", "There is a coil.", true, true, true, true, battery, NULL);
	battery->allowedInteractors.push_back(coil);

	Item* magnet = new Item("magnet", "You have a magnet.", "There is a magnet.", true, true, true, true, sand, NULL);
	sand->allowedInteractors.push_back(magnet);

	Item* rusted_key = new Item("key", "A rusted key.", "There is a rusted key", true, true, true, false, entrance_east, NULL);

	Item* lens = new Item("lens", "A plain old camera lens.", "You can see what it used to be the lens of a camera", true, true, true, true, NULL);
	Item* soaked_stick = new Item("stick", "A wooden stick soaken in some strange goo.", "There is a wooden stick.", true, true, true, true, lens, NULL);
	lens->allowedInteractors.push_back(soaked_stick);
	
	Item* torch = new Item("torch", "A flaming, bright torch you built yourself. You feel accomplished.", "A torch brightens the place.", true, true, true, true, NULL);

	combinations[new Combination("cables", "rod")] = coil;
	combinations[new Combination("coil", "battery")] = magnet;
	combinations[new Combination("magnet", "sand")] = rusted_key;
	combinations[new Combination("hammer", "lens")] = lens;
	combinations[new Combination("wood", "vase")] = soaked_stick;
	combinations[new Combination("stick", "lens", "desert")] = torch;


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
	if (msg.action == NONE)
	{
		cout << "I don't understand what you want to do..." << endl << "  ";
		return;
	}

	// special actions without target

	if (msg.action == LOOK && msg.target == "player")
		cout << this->player->descritption << endl << "  ";

	if (msg.action == INVENTORY || ((msg.action == LOOK && msg.target == "player")))
	{
		string text = this->player->ListContents();

		if (text == "")
			cout << "My inventory is empty." << endl << "  ";
		else
			cout << "I am currently carrying: " << text.substr(0,text.size()-2) << "." << endl << "  ";
		return;
	}

	if (msg.action == HELP)
	{
		cout << "To navigate the world of myZork you just need to state what you want to do.\n  "
				"You can 'look' around to explore your surroundings. 'Open' and 'close' containers\n  "
				"to reach their interior and maybe 'take' some items to your 'inventory'. You can\n  "
				"'use' some of these items on other objects to unlock some new possibilities.\n  "
				"By the way, you can always 'drop' the items you don't need on the room or inside\n  "
				"a container" << endl << "  ";
		return;
	}


	if (msg.target == "")
	{
		if (msg.action == GO) cout << "You can't go there..." << endl << "  ";
		else cout << "I don't understand what is the target of your action..." << endl << "  ";
		return;
	}

	
	Entity* target = current->Find(msg.target);
	if (target == NULL) target = player->Find(msg.target);

	if (target == NULL) 
	{
		cout << "[World::Update] Could not find the target <<" << msg.target << ">> for this action.";
		return;
	}

	Entity* interactor = current->Find(msg.interactor);
	if (interactor == NULL) interactor = player->Find(msg.interactor);

	switch (msg.action)
	{
	case LOOK:
		target->Look();
		break;

	case GO:
		CurrentPosition(target->Go());
		break;

	case OPEN:
		target->Open();
		break;

	case CLOSE:
		target->Close();
		break;

	case USE:
		if (interactor == NULL)
			target->Use(this->combinations);
		else
			target->Use(interactor, current, this->combinations);
		
		break;

	case TAKE:
		target->Take(this->player);
		break;

	case DROP:
		if (interactor == NULL)
			target->Drop(this->current);
		else
			target->Drop(interactor);
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

list<string> World::Visible(void)
{
	list<string> world = current->Visible();
	list<string> invent = player->Visible();
	
	world.merge(invent);

	return world;
}