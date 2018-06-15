#pragma once
#ifndef _ZORK_ENTITY_
#define _ZORK_ENTITY_

#include <string>;
#include <list>;

using namespace std;

class Entity 
{
	public:
		Entity(std::string name, std::string description);
		Entity(string name, string description, Entity* parent);

		~Entity();
		
		void Add(Entity* entity);
		Entity* Find(string name);
		list<string> Visible();

		virtual void Look(void);
		virtual void Go(void);

	private:
		string name;
		string descritption;
		bool visible;
		list<Entity*> contains;
};


#endif // !_ZORK_ENTITY_