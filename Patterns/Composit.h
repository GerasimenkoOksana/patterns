#pragma once
#include<iostream>
#include<string>
#include<list>

using namespace std;

class Component
{
protected:
	string name;
	static int t;
public:
	Component(string n) : name(n) {}
	virtual void add(Component* comp) {}
	virtual void print()
	{
		for (size_t i = 0; i < t; i++)
		{
			cout << "    ";
		}
		cout << name << endl;
	}
};
int Component::t = 0;

class Folder : public Component
{
	list<Component*> components;
public:
	Folder(string n): Component(n){}
	void add(Component* comp)
	{
		components.push_back(comp);
	}
	void print()
	{
		for (size_t i = 0; i < t; i++)
		{
			cout << "    ";
		}
		t++;
		cout << "Folder: " << name << endl;
		for (auto c : components)
			c->print();
		t--;
	}
};

class File : public Component
{
public:
	File(string n) : Component(n) {}
};

