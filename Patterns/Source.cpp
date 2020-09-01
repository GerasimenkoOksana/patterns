#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"FactoryMethod.h"
#include"AbstractFactory.h"
#include"Builder.h"
#include"Singleton.h"
#include"Prototype.h"
#include"Decorator.h"

using namespace std;

int main()
{
	setlocale(0, "");
	
	Pizza* pizza1 = new ItalianPizza;
	pizza1 = new Tomato(pizza1);
	pizza1 = new Cheese(pizza1);
	cout << pizza1->getName() << endl;
	cout << "Цена: "<<pizza1->getCoast() << endl;

	system("pause");
}