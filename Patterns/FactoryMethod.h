#pragma once
#include<iostream>
#include<string>

using namespace std;

class Transport
{
public:
	virtual ~Transport() {}
	virtual void delivery(string adress) = 0;
	virtual string getName() = 0;
};

//конкретный транспорт
class Track :public Transport
{
public:
	void delivery(string adress) override
	{
		cout << "груз доставлен по адресу " << adress << endl;
    }
	string getName() override
	{
		return "Использован грузовик, ";
	}
};

class Ship:public Transport
{
public:
	void delivery(string adress) override
	{
		cout << "груз доставлен по адресу " << adress << endl;
	}
	string getName() override
	{
		return "Использован корабль, ";
	}
};

class Plane:public Transport
{
	void delivery(string adress) override
	{
		cout << "груз доставлен по адресу " << adress << endl;
	}
	string getName() override
	{
		return "Использован самолет, ";
	}
};
class Creator
{
public:
	virtual ~Creator(){}
	virtual Transport* createTransport() = 0;
	Transport* create()
	{
		Transport* transport = this->createTransport();		
		return transport;
	}
};

class TrackCreator : public Creator
{
public:
	Transport* createTransport() override
	{
		return new Track;
	}
};
class ShipCreator : public Creator
{
public:
	Transport* createTransport() override
	{
		return new Ship;
	}
};
class PlaneCreator : public Creator
{
public:
	Transport* createTransport() override
	{
		return new Plane;
	}
};


/*Creator* creator = new TrackCreator;
Transport* track = creator->create();
cout<<track->getName();
track->delivery("in Nikolaev");

creator = new ShipCreator;
Transport* ship = creator->create();
cout<<ship->getName();
ship->delivery("in Kiev");*/

/*Creator* creator;
Transport* transport;
int n;
cout << "1 - грузовик, 2 - корабль, 3 - самолет" << endl;
cin >> n;
switch (n)
{
case 1: creator = new TrackCreator; break;
case 2: creator = new ShipCreator; break;
case 3: creator = new PlaneCreator; break;
default:creator = nullptr; break;
}
if (creator)
{
	transport = creator->create();
	cout << transport->getName();
	transport->delivery("in Rovno");
}
else cout << "такого транспорта нет" << endl;*/