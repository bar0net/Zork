#pragma once
#ifndef _ZORK_EXIT_
#define _ZORK_EXIT_

#include "entity.h"

class Exit : public Entity
{
	public:
		Exit(string name, string description, string placement, Entity* parent, Entity* destination);
		Exit(string name, string description, string placement, bool locked, Entity* parent, Entity* destination);
		~Exit();

		Entity* Go(void);
		void UsedOn(void);
		void SeeContents(void);
		void Open(void);
		void Close(void);

	private:
		bool locked;
		Entity* destination;
		string placementText;
};

#endif // !_ZORK_EXIT_
