#pragma once

#include<iostream>
#include<string>

using namespace std;

namespace Adapter
{
	class ITransport
	{
	public:
		virtual void drive() = 0;
	};


	class Car:public ITransport
	{
	public:
		void drive()
		{
			cout << "Машина едет" << endl;
		}
	};

	class Driver
	{
	public:
		void travel(ITransport* tr)
		{
			tr->drive();
		}
	};

	class Camel
	{
	public:
		void move()
		{
			cout << "Верблюд идёт по пустыне" << endl;
		}
	};

	class CamelToTransport : public ITransport
	{
		Camel* camel;
	public:
		CamelToTransport(Camel* c):camel(c) {}
		void drive() override
		{
			camel->move();
		}
	};

	class Ship
	{
	public:
		void sail()
		{
			cout << "Корабль плывет по морю" << endl;
		}
	};

	class ShipToTransport :public ITransport
	{
		Ship* ship;
	public:
		ShipToTransport(Ship* s):ship(s){}
		void drive() override
		{
			ship->sail();
		}
	};
}

//Adapter::Car* car = new Adapter::Car;
//Adapter::Driver* driver = new Adapter::Driver;
//driver->travel(car);
//Adapter::Camel* camel = new Adapter::Camel;
//Adapter::ITransport* camelTransport = new Adapter::CamelToTransport(camel);
//driver->travel(camelTransport);
//
//Adapter::Ship* ship = new Adapter::Ship;
//Adapter::ITransport* shipTransport = new Adapter::ShipToTransport(ship);
//driver->travel(shipTransport);