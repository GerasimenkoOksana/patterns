#pragma once
#include<iostream>
#include<string>
#include<map>
using namespace std;

class IPage  //����� ����������
{
public:
	virtual string getPage(int key) = 0;
};

class DataBase : public IPage
{
	map<int, string> pages; //���� ������ �� �������
public:
	DataBase()
	{
		pages[1] = "Pages1";
		pages[2] = "Pages2";
		pages[3] = "Pages3";
		pages[4] = "Pages4";
		pages[5] = "Pages5";
	}
	string getPage(int key) override
	{
		if (pages.count(key))
			return pages[key];
		else return "no page";
	}
};

class DataBaseProxy :public IPage
{
	map<int, string> cash;
	DataBase* base;
public:
	string getPage(int key) override
	{
		if (cash.count(key))
		{
			cout << "����� �� ����:  ";
			return cash[key];
		}
		{
			base = new DataBase;
			string page = base->getPage(key);
			cash[key] = page;
			delete base;
			cout << "����� �� ����:  ";
			return page;
		}

	}
};

//DataBaseProxy* dbproxy = new DataBaseProxy;
//int i = 1;
//while (i)
//{
//	cout << "��������: ";
//	cin >> i;
//	cout << dbproxy->getPage(i) << endl;
//}