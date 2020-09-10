#pragma once
#include<iostream>
#include<string>

using namespace std;

class HouseBuilder
{
protected:
	virtual void buildWall() = 0;
	virtual void buildDoor() = 0;
	virtual void buildWindow(int count) = 0;
	virtual void hookbuildLift() = 0;
	virtual void buildRoof() = 0;   //крыша
public:
	void buildHouse(int wind)
	{
		buildWall();
		buildDoor();
		buildWindow(wind);
		hookbuildLift();
		buildRoof();
	}
	virtual string getHouse() { return ""; }
};

class StandartHouse : public HouseBuilder
{
	string house = "";
public:
	void buildWall()
	{
		house += "Глиняные стены \n";
	}
	void buildDoor()
	{
		house += "Деревянные двери \n";
	}
	void buildWindow(int count)
	{
		house += "Обычные окна -";
		char buff[10];
		_itoa(count, buff, 10);
		house += buff;
		house += "\n";
	}
	void buildRoof()
	{
		house += "Соломенная крыша \n";
	}
	void hookbuildLift()
	{

	}
	string getHouse() { return house; }
};


class SuoerPuperHouse : public HouseBuilder
{
	string house = "";
public:
	void buildWall()
	{
		house += "Каменные  стены \n";
	}
	void buildDoor()
	{
		house += "Гаражные ворота \n";
	}
	void buildWindow(int count)
	{
		house += "Пластиковые окна -";
		char buff[10];
		_itoa(count, buff, 10);
		house += buff;
		house += "\n";
	}
	void buildRoof()
	{
		house += "Крыша из металлочерепицы \n";
	}
	void hookbuildLift()
	{
		house += "лифт на 5 человек \n";
	}
	string getHouse() { return house; }
};