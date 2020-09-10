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
	virtual void buildRoof() = 0;   //�����
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
		house += "�������� ����� \n";
	}
	void buildDoor()
	{
		house += "���������� ����� \n";
	}
	void buildWindow(int count)
	{
		house += "������� ���� -";
		char buff[10];
		_itoa(count, buff, 10);
		house += buff;
		house += "\n";
	}
	void buildRoof()
	{
		house += "���������� ����� \n";
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
		house += "��������  ����� \n";
	}
	void buildDoor()
	{
		house += "�������� ������ \n";
	}
	void buildWindow(int count)
	{
		house += "����������� ���� -";
		char buff[10];
		_itoa(count, buff, 10);
		house += buff;
		house += "\n";
	}
	void buildRoof()
	{
		house += "����� �� ��������������� \n";
	}
	void hookbuildLift()
	{
		house += "���� �� 5 ������� \n";
	}
	string getHouse() { return house; }
};