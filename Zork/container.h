#pragma once
#ifndef _ZORK_ITEM_CONTAINER_
#define _ZORK_ITEM_CONTAINER_

#include "item.h"

class Container : public Item 
{
	public:
		Container(string name, string openText, string closedText, bool isOpen, string placementText, bool visible, Entity* parent);
		~Container();

		void Open(void);
		void Close(void);

	private:
		bool isOpen;
		string otherText;

		void SwapDescription(void);
		void ToogleContentVisibility(bool visible);
};

#endif // !_ZORK_ITEM_CONTAINER_
