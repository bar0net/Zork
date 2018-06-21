#include "world.h"

#include <iostream>

#include "object.h"
#include "container.h"
#include "item.h"
#include "exit.h"
#include "room.h"
#include "enemy.h"

World::World(void) 
{
	this->player = new Player("player", "I look wonderful in cargo shorts and a kaki shirt.", 7);

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
	Room* tomb = new Room("tomb", "You find yourself in the burial site surrounded by uncountable riches.");

	this->zones.push_back(desert);
	this->zones.push_back(entrance);
	this->zones.push_back(mural);
	this->zones.push_back(rubble);
	this->zones.push_back(chamber);
	this->zones.push_back(workshop);
	this->zones.push_back(tomb);

	// Define Exits
	Exit* desert_north = new Exit("north", "Two massive stone columns welcome you to the temple.", "The entrance to the temple lies to the north.", desert, entrance);
	Exit* desert_gates = new Exit("gates", "Two massive stone columns welcome you to the temple.", "", desert, entrance);

	Exit* entrance_south = new Exit("south", "Two massive stone columns preside the exit of the temple.", "The gates to the desert lie to the south.", entrance, desert);
	Exit* entrance_gates = new Exit("gates", "Two massive stone columns preside the exit of the temple.", "", entrance, desert);
	Exit* entrance_east = new Exit("door", "The door has rusted and the decorations have deteriorated.\n  Time has clearly takem its toll on this door.",
		"There is a rusted door at one side of the room.", true, entrance, rubble);
	Exit* entrance_north = new Exit("north", "You can see a long hallway with pictograms on the walls and long extinguished torches.", "On the northern part "
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

	Exit* mural_gates = new Exit("gate", "Somehow, the interaction between the two orbs has opened a new gate in this room. Where could it lead?",
		"The orbs have opened a new gate.", false, NULL, tomb);

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
	Item* combination = new Item("paper", "It's a small piece of paper with a combination in it.", 
		"You can see a piece of paper sticking out.", true, true, true, true, cam_case, corpse);
	Item* crack = new Item("crack", "There is a small crack on the wall.", "You can now see a small crack on the wall", true, false, false, false, NULL);
	Item* blue_orb = new Item("blue orb", "It appears to a ceramic material with a crystaline structure but it glows in the dark and you can't fathom why.",
		"You can see a glowing blue orb.", true, true, true, true, crack);

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
	
	Item* torch = new Item("torch", "A flaming, bright torch you built yourself. You feel accomplished.", "A torch brightens the place.", true, true, true, true, chamber, NULL);

	combinations[new Combination("cables", "rod", "You roll the copper cable around the rod forming a coil.")] = coil;
	combinations[new Combination("coil", "battery", "By attaching a battery to the coil, you get a magnet. Yey physics!")] = magnet;
	combinations[new Combination("magnet", "sand", "As you explore the desert with your magnet, you find a rusted key burried in the sand.")] = rusted_key;
	combinations[new Combination("hammer", "lens", "You manage to losen the lens and take it out.")] = lens;
	combinations[new Combination("wood", "vase", "You submerge most of the wooden branch on the weird goo. You now have a soaked stick.")] = soaked_stick;
	combinations[new Combination("stick", "lens", "You use the camera lens to focus the solar rays and"
		" light your stick on fire. You now have a torch!", "desert")] = torch;
	combinations[new Combination("torch", "chamber", "The light of your torch reveal a crack on the wall.")] = crack;

	blue_orb->allowedInteractors.push_back(red_orb);
	red_orb->allowedInteractors.push_back(blue_orb);
	combinations[new Combination("blue orb", "red orb", "You hear a loud noise while a gate opens in the room.", "mural")] = mural_gates;

	// Enemies
	Enemy* king = new Enemy("king", "The rotten corpse of the las king of Anatria.", 3,
		"\n  You defeat the mummified corpse of the old king.\n  "
		"Now the tumb remains ungarded and all these vast amounts\n  "
		"of riches are yours for the taking. You are already dreaming\n  "
		"of traveling the world and relaxing in luxourios beaches in\n  "
		"the Caribbean. Oh, life!\n  "
		"Well, that is if you manage to find your way back to\n  "
		"civilization. You are in the middle of the desert after all.\n  ", tomb);

	this->current = desert;

	cout << "[DEBUG] ";
	for (list<Entity*>::iterator it = this->current->contains.begin(); it != this->current->contains.cend(); ++it)
		cout << (*it)->name << ", ";
	cout << endl << "  ";

	this->current->Look();
	SearchEnemy();
}

World::~World(void) 
{
	for (list<Entity*>::iterator it = this->zones.begin(); it != this->zones.cend(); ++it)
		delete *it;
}

void World::Update(ParsedInput msg)
{
	// Unspecified Actions
	// No action passed
	if (msg.action == NONE)
	{
		cout << "I don't understand what you want to do..." << endl << "  ";
		return;
	}

	// Help command
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

	
	if (this->enemy != NULL) FightState(msg);
	else NeutralState(msg);
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

	// special command
	world.push_back("room");
	world.push_back("place");

	return world;
}

void World::SearchEnemy(void)
{
	for (list<Entity*>::iterator it = current->contains.begin(); it != current->contains.cend(); ++it)
	{
		if ((*it)->type == ENEMY) this->enemy = (Enemy*)(*it);
	}
}

void World::NeutralState(ParsedInput msg)
{
	// special actions without target
	if (msg.action == LOOK && msg.target == "player")
		cout << this->player->descritption << endl << "  ";
	if (msg.action == INVENTORY || ((msg.action == LOOK && msg.target == "player")))
	{
		string text = this->player->ListContents();

		if (text == "")
			cout << "My inventory is empty." << endl << "  ";
		else
			cout << "I am currently carrying: " << text.substr(0, text.size() - 2) << "." << endl << "  ";
		return;
	}
	if (msg.action == LOOK && (msg.target == "room" || msg.target == "place"))
	{
		current->Look();
		return;
	}

	// Non targeted
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
		SearchEnemy();
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

	case ROCK:
		cout << "You are not currently in a fight!" << endl << "  ";
		break;

	case PAPER:
		cout << "You are not currently in a fight!" << endl << "  ";
		break;

	case SCISSORS:
		cout << "You are not currently in a fight!" << endl << "  ";
		break;

	default:
		break;
	}
}

void World::FightState(ParsedInput msg)
{
	if (msg.action == PAPER) cout << "You show paper ";
	else if (msg.action == ROCK) cout << "You show rock ";
	else if (msg.action == SCISSORS) cout << "You show scissors ";
	else 
	{
		cout << "You are in a life or death fight. Focus!" << endl << "  ";
		return;
	}

	Actions rps = this->enemy->Update();

	if (rps == PAPER) cout << "and the " << this->enemy->name << " shows paper. ";
	else if (rps == ROCK) cout << "and the " << this->enemy->name << " shows rock. ";
	else if (rps == SCISSORS) cout << "and the " << this->enemy->name << " shows scissors. ";

	int result = (3 + ((int)msg.action - (int)rps)) % 3;

	if (result == 0)
		cout << "It's a draw!" << endl << "  ";
	else if (result == 1)
	{
		cout << "You win!" << endl << "  ";
		this->enemy->Hit();
		if (!this->enemy->Alive())
		{
			if (this->enemy->name == "king") this->gameOver = true;
			delete this->enemy;
			this->enemy = NULL;
		}
	}
	else
	{
		cout << "You lose and take damage!" << endl << "  ";
		player->Hit();
	}
}