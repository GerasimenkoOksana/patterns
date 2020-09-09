#pragma once
#include<iostream>
#include<string>

using namespace std;

class Strategy
{
public:
	virtual float move(int len) = 0;
};

class OnFootStrategy : public Strategy
{
	int speed = 3;
public:
	float move(int len) override
	{
		cout << "������ ����� - ������" << endl;
		return(float)len / speed;
	}
};

class OnBusStrategy : public Strategy
{
	int speed = 40;
public:
	float move(int len) override
	{
		cout << "������ ����� - ������������ ���������" << endl;
		return(float)len / speed;
	}
};

class OnAutoStrategy : public Strategy
{
	int speed = 60;
public:
	float move(int len) override
	{
		cout << "������ ����� - ����������" << endl;
		return(float)len / speed;
	}
};

class Navigator
{
	Strategy* strategy;
public:
	void setStrategy(Strategy* strategy)
	{
		this->strategy = strategy;
	}
	void getTime(int len)
	{
		float t = strategy->move(len);
		cout << "��������� ����� � ���� - " << t << " �" << endl;
	}
};

/*Navigator* navi = new Navigator;
	navi->setStrategy(new OnBusStrategy);
	navi->getTime(100);

	Strategy* strategy = nullptr;
	int len, i;
	cout << "������� ����������: ";
	cin >> len;
	cout << "������� �������: 1 - ������, 2 - �� ������������ ����������, 3 - ����������: ";
	cin >> i;
	switch (i)
	{
	case 1: strategy = new OnFootStrategy; break;
	case 2: strategy = new OnBusStrategy; break;
	case 3: strategy = new OnAutoStrategy; break;
	default: break;
	}
	navi->setStrategy(strategy);
	navi->getTime(len);*/
