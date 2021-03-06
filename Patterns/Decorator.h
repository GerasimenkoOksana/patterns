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
	virtual int getCoast() = 0; //�������� ����
};

class ItalianPizza : public Pizza
{
public:
	ItalianPizza() : Pizza("����������� �����") {}
	int getCoast() override { return 100; }
};


class UkranianPizza : public Pizza
{
public:
	UkranianPizza() : Pizza("���������� �����") {}
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
	Tomato(Pizza* p): PizzaDecorator(p->getName()+", � ���������� ",p) {}
	int getCoast() override
	{
		return pizza->getCoast() + 20;
	}
};

class Cheese : public PizzaDecorator
{
public:
	Cheese(Pizza * p) : PizzaDecorator(p->getName() + ", � ����� ",p) {}
	int getCoast() override
	{
		return pizza->getCoast() + 30;
	}
};


//Pizza* pizza1 = new ItalianPizza;
//pizza1 = new Tomato(pizza1);
//pizza1 = new Cheese(pizza1);
//cout << pizza1->getName() << endl;
//cout << "����: " << pizza1->getCoast() << endl;