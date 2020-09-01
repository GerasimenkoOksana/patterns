#pragma once
#include<iostream>
#include<string>

using namespace std;


class IFigure
{
public:
	virtual IFigure* clone() = 0;
	virtual void print() = 0;
};

class Rectangle :public IFigure
{
	int w, h; //длина и ширина
public:
	Rectangle(int w, int h) : w(w), h(h) {}
	IFigure* clone() override
	{
		return new Rectangle(w, h);
	}
	void print() override
	{
		cout << "Rectangle " << endl;
		cout << "W: " << w<<endl;
		cout << "H: " << h<<endl;
	}
};

class Circle :public IFigure
{
	int r; //радиус
public:
	Circle(int r) : r(r) {}
	IFigure* clone() override
	{
		return new Circle(r);
	}
	void print() override
	{
		cout << "Circle " << endl;
		cout << "R: " << r << endl;
	}
};


//void method(IFigure* figure)
//{
//	figure->print();
//	IFigure* copy = figure->clone();
//	copy->print();
//}
//
//int main()
//{
//	setlocale(0, "");
//	IFigure* rect = new Rectangle(10, 20);
//	method(rect);
//
//	system("pause");
//}