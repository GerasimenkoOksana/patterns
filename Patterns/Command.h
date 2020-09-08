#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include<vector>
using namespace std;

class TV  //ресивер - приемник команд
{
public:
	void on()
	{
		cout << "TV on" << endl;
	}
	void off()
	{
		cout << "TV off" << endl;
	}
};

class ICommand
{
public:
	virtual void execute() = 0; //команда выполнить
};

class TVCommandON : public ICommand
{
	TV* tv;
public:
	TVCommandON(TV* tv) :tv(tv) {}
	void execute() override
	{
		tv->on();
	}
};

class TVCommandOFF : public ICommand
{
	TV* tv;
public:
	TVCommandOFF(TV* tv) :tv(tv) {}
	void execute() override
	{
		tv->off();
	}
};

class Pult //invoker - исполнитель
{
	vector<ICommand*> command;
public:
	Pult(int num) { command.resize(num); }
	void setCommand(int num, ICommand* com) 
	{ 
		command[num] = com; 
	}
	void pressButton(int num) //нажатие кнопки
	{
		command[num]->execute();
	}
};

class Multivarka
{
public:
	void start(int t)
	{
		cout << "Готовим еду" << endl;
		for (size_t i = 0; i < t; i++)
		{
			cout << ".";
			Sleep(1000);
		}
		cout << endl;
	}
	void stop()
	{
		cout << "Еда готова" << endl;
	}
};

class MVCommand : public ICommand
{
	Multivarka* mv;
	int t;
public:
	MVCommand(Multivarka* mv, int t):mv(mv), t(t){}
	void execute() override
	{
		mv->start(t);
		mv->stop();
	}
};

/*TV* tv = new TV;
	Pult* pult = new Pult;
	pult->setCommand(new TVCommandON(tv));
	pult->pressButton();

	Multivarka* mv = new Multivarka;
	pult->setCommand(new MVCommand(mv, 10));
	pult->pressButton()*/

//TV* tv = new TV;
//Multivarka* mv = new Multivarka;
//Pult* pult = new Pult(3);
//pult->setCommand(0, new TVCommandON(tv));
//pult->setCommand(1, new TVCommandOFF(tv));
//pult->setCommand(2, new MVCommand(mv, 10));
//int n;
//while (true)
//{
//	cin >> n;
//	pult->pressButton(n);
//}