#pragma once
#include<iostream>
#include<string>
#include<stack>

using namespace std;
 //дл€ сохранени€ состо€ни€ героев стрел€лки
class HeroMemento;

class Hero
{
	int patrons = 10;
	int hp = 100;  //жизнь
public:
	void shoot()  //стрел€ть
	{
		cout << "ѕроизведен выстрел. ќсталось " << --patrons << " патронов" << endl;
	}
	HeroMemento* saveHero(); //сохранить состо€ние геро€
	
	void restoreHero(HeroMemento* memento);  //отдать состо€ние геро€
	
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

HeroMemento* Hero::saveHero() //сохранить состо€ние геро€
{
	cout << "—охранение игры: патронов " << patrons << " , жизни " << hp << endl;
	return new HeroMemento(patrons, hp);
}

void Hero::restoreHero(HeroMemento* memento)  //отдать состо€ние геро€
{
	patrons = memento->patrons;
	hp = memento->hp;
	cout << "¬осстановление игры: патронов " << patrons << " , жизни " << hp << endl;
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