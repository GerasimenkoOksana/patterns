#pragma once
#include<iostream>
#include<string>

using namespace std;

class Pizza
{
	string name;
public:
	Pizza(string n) : name(n) {}
	string getName() { return name; }
	virtual int getCoast() = 0; //получить цену
};

class ItalianPizza : public Pizza
{
public:
	ItalianPizza() : Pizza("Итальянская пицца") {}
	int getCoast() override { return 100; }
};


class UkranianPizza : public Pizza
{
public:
	UkranianPizza() : Pizza("Украинская пицца") {}
	int getCoast() override { return 150; }
};

class PizzaDecorator : public Pizza
{
protected:
	Pizza* pizza;
public:
	PizzaDecorator(string n, Pizza* p): Pizza(n), pizza(p){}
	virtual ~PizzaDecorator() { delete pizza; }
};

class Tomato : public PizzaDecorator
{
public:
	Tomato(Pizza* p): PizzaDecorator(p->getName()+", с помидорами ",p) {}
	int getCoast() override
	{
		return pizza->getCoast() + 20;
	}
};

class Cheese : public PizzaDecorator
{
public:
	Cheese(Pizza * p) : PizzaDecorator(p->getName() + ", с сыром ",p) {}
	int getCoast() override
	{
		return pizza->getCoast() + 30;
	}
};