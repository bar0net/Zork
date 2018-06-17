#pragma once
#ifndef _ZORK_ENTITY_
#define _ZORK_ENTITY_

#include <string>;
#include <list>;

using namespace std;

// Anything that is physically present in the game world
class Entity 
{
	public:
		// name of the entity
		string name;

		// player can only see visible entities when looking
		bool visible;

		// Constructor & Destructor
		Entity(std::string name, std::string description);
		~Entity();
		
		// Checks itself and its contents for an entity with name "name"
		// returns that entity if it exists
		// returns NULL if it does not exist
		Entity* Find(string name);

		// Checks itself and its contents for visible entities
		// returns a list of all visible entities found
		list<string> Visible();

		// Add/Remove entity to the contains list
		void Add(Entity* entity);
		void Remove(Entity* entity);

		// Returns an inline-list of its contents
		string ListContents(void);

		// Action default methods
		virtual void Look(void);
		virtual Entity* Go(void);
		virtual void Open(void);
		virtual void Close(void);
		virtual void Take(Entity* parent);
		virtual void Drop(void);
		virtual void Use(void);
		virtual void Use(Entity* recipient);
		virtual void UsedOn(void) {};

		// Visible 'Objects' will reveal themselves when you
		// look at their parent entity
		virtual void SeeContents(void) {};

	protected:

		// text displayed when the entity is looked at
		string descritption;

		// list of entities contained within this entity
		list<Entity*> contains;
};


#endif // !_ZORK_ENTITY_