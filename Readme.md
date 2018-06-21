# myZork
myZork is a short text adventure game made in C++.

## How to play
The objective of the game is to find the secret tresure on an ancient tomb and retrieve all its riches by solving some contextual puzzles
using the objects and tool at their disposal. 

To interact with the environment, the player should type the action they want to carry out using commands like Look, Open, Close, Grab,
Drop, Use,...

Fights are carried out using Rock-Paper-Scissors and, thus, the player should type their prefferred option until the end of the fight.
No fleeing allowed.

Other commands include 'help' to show a small text exposing the basic mechanics of the game and 'exit' to quit the game.

While playing, the character will keep getting dehidrated, therefore the player has to complete the game in about a 100 actions
to avoid dying of thirst.

## Notes
### Positives
It has been quite some time since I last built a project in C++ from scratch and it has been a nice refreshing experience. 
Development-wise, it has been interesting building this game layer by layer and adding new functionalities to expand 
gameplay capabilities (adding new types of interactions) and include more flexible ways to communicate with the player. 

### What to improve
For starters, I got kind of anxious and uneasy at the beggining (again, it had been quite some time since I takled a challenge
in C++) and got right into the code without a clear development plan and, even though, I like to keep expanding the requirements
for my code as I get creative and think of new ideas, it clearly makes for a not optimal solution. Some preproduction time would
have been wise in terms of determining the needs I had for each class and comming up with cleaner ways to communicate among them.

## Walkthrough
### MAP
(dark chamber)===(    mural    )
      ||               ||
(  workshop  )   (   entrance  )===(rubble room)
                       ||
				 (    desert   )

				      North
			       West   East
				      South

### Blue orb

* Go to the workshop
* Grab rod
* Go to the mural room (Go north, Go east)
* Grab cables
* Use cables with rod --> to create a coil
* Go to desert (Go south, Go south)
* Open bag
* Open flashlight
* Use coil with battery --> to create a magnet
* Use magnet on sand --> to get a rusted key
* Go to the entrance (Go north)
* Use the key on the door --> to unlock the door
* Cross the door to get into the rubble room (Go door)
* Grab the blue orb

### Red Orb
* Go to the workshop
* Grab the hammer
* Grab the wood
* Go to the dark chamber (Go north)
* Grab the paper
* Use the wood with the vase --> to get a stick
* Go to the room with the mural (Go east)
* Use the paper with the case --> to unlock the paddlock
* Use the hammer on the lens --> to release the lens from the camera
* Go to the desert (Go south, Go south)
* Use the lens on the stick --> to get a torch
* Go to the dark chamer (Go north, Go north, Go west)
* Use the torch on the dark chamber --> to reveal a crack on the wall with the blue orb
* Grab the blue orb

### End game
* Go to the mural room
* Use blue orb with red orb --> to reveal the gates to the tomb
* Go gates
* Play a Rock-Paper-Scissors game with the mummified king
* Win to get the 'good' ending



## Built With
Microsoft Visual Studio Community 2017

## Authors
Jordi Tudela Alcacer

## License
This project is licensed under the MIT License - see the [LICENSE.md](/LICENSE.md) file for details

## Acknowledgements
* [Zork](http://textadventures.co.uk/games/view/5zyoqrsugeopel3ffhz_vq/zork)
