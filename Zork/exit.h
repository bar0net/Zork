#pragma once
#ifndef _ZORK_EXIT_
#define _ZORK_EXIT_

#include "entity.h"

class Exit : public Entity
{
	public:
		// Constructors & Destructors
		Exit(string name, string description, string placement, Entity* parent, Entity* destination);
		Exit(string name, string description, string placement, bool locked, Entity* parent, Entity* destination);
		~Exit();

		// Actions
		Entity* Go(void);
		void UsedOn(void);
		void SeeContents(void);
		void Open(void);
		void Close(void);

	private:
		// If the exit is locked, the player cannot go through it
		bool locked;

		// The room its connected to
		Entity* destination;		
		
		// The text that will be shown when the player "Looks" at the parent
		string placementText;
};

#endif // !_ZORK_EXIT_
