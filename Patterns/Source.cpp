#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
//#include"FactoryMethod.h"
//#include"AbstractFactory.h"
//#include"Builder.h"
//#include"Singleton.h"
//#include"Prototype.h"
//#include"Decorator.h"
//#include"Adapter.h"
//#include"Bridge.h"
//#include"Composit.h"
//#include"Proxy.h"  
//#include"State.h"
//#include"ChainOfResponsibility.h"
//#include"Command.h"
//#include"Mediator.h"
//#include"Strategy.h"
//#include"Observer.h"
//#include"Memento.h"
#include"Visiter.h"
#include"TemplateMethod.h"
using namespace std;

int main()
{
	setlocale(0, "");

	HouseBuilder* stHouse = new StandartHouse;
	stHouse->buildHouse(4);
	cout << stHouse->getHouse() << endl;;
	HouseBuilder* stHouse1 = new SuoerPuperHouse;
	stHouse1->buildHouse(25);
	cout << stHouse1->getHouse();

	system("pause");
}