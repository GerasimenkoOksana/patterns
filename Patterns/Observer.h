//����������� - ��� ������������, ��������� - ���������� ������ �� ����� � �.�.
#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
class Buyer;    // ����������
class Product  //�������, �� ������������� ����������
{
public:
	virtual void addBuyer(Buyer* buyer) = 0;  //�������� ���������� � ������ ������������  � ������
	virtual void removeBuyer(Buyer* buyer) = 0; //������� �� ������
	virtual void notify() = 0;  //��������� ��������� �� ��������� ����
	virtual string getName() { return ""; }
	virtual float getPrice() { return 0; }
};

class Computer : public Product
{
	string name;
	float price;
	vector<Buyer*> buyers;
public:
	Computer(string n, float p) : name(n),price(p) {}
	void addBuyer(Buyer* buyer) override
	{
		buyers.push_back(buyer);
	}
	void removeBuyer(Buyer* buyer) override
	{
		auto del = find(buyers.begin(), buyers.end(), buyer);
		if (del != buyers.end())
			buyers.erase(del);
	}
	void notify() override;
	
	void setPrice(float price)
	{
		if (this->price != price)
		{
			this->price = price;
			notify();
		}
	}
	string getName() { return name; }
	float getPrice() { return price; }
};

class Buyer
{
public:
	virtual void update(Product* product) = 0; //���������� ��������� � ������
};

class UkranianBuyer : public Buyer
{
	string name;
public:
	UkranianBuyer(string n) : name(n){}
	void update(Product* product) override
	{
		cout << "��������� ��� " << name << " �� �������� " << product->getName()
			<< " ����� ����: " << product->getPrice() << endl;
	}
};

void Computer::notify()
{
	for (auto b : buyers)
		b->update(this);
}

//Computer* comp = new Computer("IBM", 10000);
//UkranianBuyer* b1 = new UkranianBuyer("Ivan");
//UkranianBuyer* b2 = new UkranianBuyer("Svetlana");
//UkranianBuyer* b3 = new UkranianBuyer("Denis");
//comp->addBuyer(b1);
//comp->addBuyer(b2);
//comp->addBuyer(b3);
//comp->setPrice(9000);
//cout << endl;
//
//comp->setPrice(8000);
//cout << endl;
//
//comp->removeBuyer(b2);
//comp->setPrice(7000);
//cout << endl;