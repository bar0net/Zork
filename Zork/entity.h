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
		Entity(string name, string description, string placementText, Entity* parent);

		~Entity();
		
		void Add(Entity* entity);
		Entity* Find(string name);
		list<string> Visible();

		virtual void Look(void);
		virtual void Go(void);
		virtual void Open(void);
		virtual void Close(void);
		virtual void Take(void);
		virtual void Drop(void);
		virtual void Use(void);

		void SeeContents(void);

	private:
		string name;
		string descritption;
		string placementText;
		bool visible;
		list<Entity*> contains;
};


#endif // !_ZORK_ENTITY_