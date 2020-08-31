#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"FactoryMethod.h"
#include"AbstractFactory.h"
#include"Builder.h"

using namespace std;

int main()
{
	setlocale(0, "");

	/*Director* director = new Director();
	MusicCenterBuilder* builderMC = new MusicCenterBuilder();
	director->setBuilder(builderMC);
	director->BuildMaxiMC();
	MusicCenter* mc = builderMC->getResult();
	mc->print();
	director->BuildMiniMC();
	MusicCenter* mc = builderMC->getResult();
	mc->print();*/
	
	/*MusicCenterBuilder* builderMC = new MusicCenterBuilder();
	cout << "����� �����? 1 - �� 2- ���" << endl;
	int a;
	cin >> a;
	if (a==1)
	builderMC->createRadio();
	cout << "CD �����? 1 - �� 2- ���" << endl;
	cin >> a;
	if (a == 1)
		builderMC->createCD();
	cout << "BlueRay �����? 1 - �� 2- ���" << endl;
	cin >> a;
	if (a == 1)
		builderMC->createBR();
	cout << "SubWoofer �����? 1 - �� 2- ���" << endl;
	cin >> a;
	if (a == 1)
		builderMC->createSW();
	MusicCenter* mc = builderMC->getResult();
	mc->print();*/

	Director* director = new Director();
	MusicCenterBuilder* builderMC = new MusicCenterBuilder();
	director->setBuilder(builderMC);
	director->BuildMiniMC();

	MusicCenter* mc = builderMC->getResult();
	mc->print();
	ManualBuilder* builderManual = new ManualBuilder;
	director->setBuilder(builderManual);
	director->BuildMiniMC();

	Manual* manual = builderManual->getResult();
	cout << manual->getText() << endl;
	system("pause");
}