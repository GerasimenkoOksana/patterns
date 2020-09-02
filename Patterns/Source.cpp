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

using namespace std;

int main()
{
	setlocale(0, "");
	Component* fs = new Folder("FileSystem");
	Component* folder1 = new Folder("Folder1");
	Component* folder2 = new Folder("Folder2");
	Component* folder3 = new Folder("Folder3");
	Component* file1 = new File("File1");
	Component* file2 = new File("File2");
	Component* file3 = new File("File3");
	fs->add(folder1);
	fs->add(folder2);
	fs->add(file1);
	folder1->add(folder3);
	folder3->add(file2);
	folder3->add(file3);
	fs->print();
	folder3->print();
	file2->print();
	system("pause");
}