#pragma once
#ifndef _ZORK_ITEM_CONTAINER_
#define _ZORK_ITEM_CONTAINER_

#include "object.h"

class Container : public Object
{
	public:
		// Constructor & Destructor
		Container(string name, string lockedText, bool isLocked, string openText, string closedText, 
					bool isOpen, string placementText, bool canPick, bool visible, Entity* parent);
		~Container();

		// Container's Actions
		void Look(void);
		void Open(void);
		void Close(void);
		void UsedOn(void);

	private:
		// is the container open?
		bool isOpen;

		// is the container locked?
		bool isLocked;
		
		// if the container is open, text to display when it's closed
		// if the container is closed, text to display when it's opened
		string otherText;

		// if the container is locked, text to display when it's unlocked
		string unlockText;

		// Swap entity's description and otherText
		void SwapDescription(void);

		// Sets all contained entities visibility to 'visible'
		void ToogleContentVisibility(bool visible);
};

#endif // !_ZORK_ITEM_CONTAINER_
