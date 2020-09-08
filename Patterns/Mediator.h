//Посредник
#pragma once
#include<iostream>
#include<string>

using namespace std;

class Collegue;

class Mediator //посредник
{
public:
	virtual void send(string message, Collegue* collegue) = 0; //руководитель получает инф/цию (message) от подчиненного collegue
};

class Collegue  //клас сотрудники-подчиненные
{
protected:
	Mediator* mediator;
public:
	Collegue(Mediator* med):mediator(med){}
	virtual void send(string message)  //отправить сообщение руководит.
	{
		mediator->send(message, this);
	}
	virtual void  notify(string message) = 0; //получение сообщение от рукводит и вывод оповещения
};

class SellerCollegue : public Collegue //продавец-работник
{
public:
	SellerCollegue(Mediator* mediator) : Collegue(mediator) {} //каждый работник знает своего руководит
	void  notify(string message) override
	{
		cout << "Сообщение для продавца: " << message << endl;
	}
};

class ProgrammerCollegue : public Collegue //программист-работник
{
public:
	ProgrammerCollegue(Mediator* mediator) : Collegue(mediator) {} //каждый работник знает своего руководит
	void  notify(string message) override
	{
		cout << "Сообщение для программиста: " << message << endl;
	}
};

class TesterCollegue : public Collegue //работник тестировщик
{
public:
	TesterCollegue(Mediator* mediator) : Collegue(mediator) {} //каждый работник знает своего руководит
	void  notify(string message) override
	{
		cout << "Сообщение для тестировщика: " << message << endl;
	}
};

class ManagerMediator : public Mediator //менеджер
{
public:
	Collegue* seller;    //подчиненные у менеджера
	Collegue* programmer;
	Collegue* tester;
	void send(string message, Collegue* collegue) override
	{
		if (collegue == seller)
			programmer->notify(message);
		else if (collegue == programmer)
			tester->notify(message);
		else if (collegue == tester)
			seller->notify(message);
	}
};

//ManagerMediator* manager = new ManagerMediator;
//Collegue* seller = new SellerCollegue(manager);
//Collegue* programmer = new ProgrammerCollegue(manager);
//Collegue* tester = new TesterCollegue(manager);
//manager->seller = seller;
//manager->programmer = programmer;
//manager->tester = tester;
//
//seller->send("Есть заказ, нужно сделать программу ");
//programmer->send("Программа готова, можно тестить");
//tester->send("Программа протестирована, можно продавать");