#pragma once
#ifndef _ZORK_ITEM_CONTAINER_
#define _ZORK_ITEM_CONTAINER_

#include "object.h"

class Container : public Object
{
	public:
		Container(string name, string lockedText, bool isLocked, string openText, string closedText, bool isOpen, string placementText, bool visible, Entity* parent);
		~Container();

		void Open(void);
		void Close(void);
		void UsedOn(void);

	private:
		bool isOpen;
		bool isLocked;
		
		string otherText;
		string unlockText;

		void SwapDescription(void);
		void ToogleContentVisibility(bool visible);
};

#endif // !_ZORK_ITEM_CONTAINER_