#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"FactoryMethod.h"
//#include"AbstractFactory.h"
#include"Builder.h"
#include"Singleton.h"
#include"Prototype.h"
#include"Decorator.h"
#include"Adapter.h"
#include"Bridge.h"
#include"Composit.h"
#include"Proxy.h"
#include"State.h"
#include"ChainOfResponsibility.h"
#include"Command.h"
#include"Mediator.h"
using namespace std;

int main()
{
	setlocale(0, "");
	ManagerMediator* manager = new ManagerMediator;
	Collegue* seller = new SellerCollegue(manager);
	Collegue* programmer = new ProgrammerCollegue(manager);
	Collegue* tester = new TesterCollegue(manager);
	manager->seller = seller;
	manager->programmer = programmer;
	manager->tester = tester;

	seller->send("���� �����, ����� ������� ��������� ");
	programmer->send("��������� ������, ����� �������");
	tester->send("��������� ��������������, ����� ���������");

	system("pause");
}