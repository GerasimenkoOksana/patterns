#pragma once
#include<iostream>
#include<string>
#include<stack>

using namespace std;
 //��� ���������� ��������� ������ ���������
class HeroMemento;

class Hero
{
	int patrons = 10;
	int hp = 100;  //�����
public:
	void shoot()  //��������
	{
		cout << "���������� �������. �������� " << --patrons << " ��������" << endl;
	}
	HeroMemento* saveHero(); //��������� ��������� �����
	
	void restoreHero(HeroMemento* memento);  //������ ��������� �����
	
};

class HeroMemento
{
	int patrons;
	int hp;
public:
	HeroMemento(int p, int hp): patrons(p), hp(hp) {}
	friend class Hero;
};

class GameHistory
{
public:
	stack<HeroMemento*> history;
};

HeroMemento* Hero::saveHero() //��������� ��������� �����
{
	cout << "���������� ����: �������� " << patrons << " , ����� " << hp << endl;
	return new HeroMemento(patrons, hp);
}

void Hero::restoreHero(HeroMemento* memento)  //������ ��������� �����
{
	patrons = memento->patrons;
	hp = memento->hp;
	cout << "�������������� ����: �������� " << patrons << " , ����� " << hp << endl;
}

/*Hero* h = new Hero;
h->shoot();
h->shoot();
h->shoot();
h->shoot();
GameHistory* gh = new GameHistory;
gh->history.push(h->saveHero());
h->shoot();
h->shoot();
h->shoot();
h->shoot();
h->restoreHero(gh->history.top());
h->shoot();
h->shoot();
h->shoot();*/