//посетитель
#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;
class Visitor;
class IFigure
{
public:
	virtual void print() = 0; virtual void accept(Visitor* v) = 0;
};

class Point : public IFigure
{
public:
	int x, y;

	Point(int x, int y) : x(x), y(y){}
	void print()
	{
		cout << " Point: X = " << x << " Y = " << y << endl;
	}
	void accept(Visitor* v);
	
};

class Circle : public IFigure
{
public:
	int x, y,r;

	Circle(int x, int y,int r) : x(x), y(y), r(r) {}
	void print()
	{
		cout << " Circle: X = " << x << " Y = " << y <<" R = "<<r<< endl;
	}
	void accept(Visitor* v);
};

class Rectangl : public IFigure
{
public:
	int x1, y1,x2,y2;

	Rectangl(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
	void print()
	{
		cout << " Rectangle: P1(" << x1<<", " << y1<<"),  P2("<<x2<<", "<< y2<<")" << endl;
	}
	void accept(Visitor* v);
	
};

class Visitor
{
public:
	virtual void visit(Point* p) = 0;
	virtual void visit(Circle* c) = 0;
	virtual void visit(Rectangl* r) = 0;
};

class HTMLExportVisitor : public Visitor
{
	string fname;
public:
	HTMLExportVisitor(string fn) : fname(fn){}
	void visit(Point* p)
	{
		string res = "";
		res += "<table><tr><td>Point </td><td> x =";
		char buff[10];
		_itoa(p->x, buff, 10);
		res += buff;
		res += "</td><td> y =";
		_itoa(p->y, buff, 10);
		res += buff;
		res += "</td></tr></table>";
		ofstream out(fname, ios::app);
		out << res << endl;
		out.close();
	}
	void visit(Circle* c)
	{
		string res = "";
		res += "<table><tr><td>Circle </td><td> x =";
		char buff[10];
		_itoa(c->x, buff, 10);
		res += buff;
		res += "</td><td> y =";
		_itoa(c->y, buff, 10);
		res += buff;
		res += "</td><td> r =";
		_itoa(c->r, buff, 10);
		res += buff;
		res += "</td></tr></table>";
		ofstream out(fname, ios::app);
		out << res << endl;
		out.close();
	}
	void visit(Rectangl* r)
	{
		string res = "";
		res += "<table><tr><td>Rectangle</td><td>P1(";
		char buff[10];
		_itoa(r->x1, buff, 10);
		res += buff;
		res += ", ";
		_itoa(r->y1, buff, 10);
		res += buff;
		res += ")</td><td>P2(";
		_itoa(r->x2, buff, 10);
		res += buff;
		res += ", ";
		_itoa(r->y2, buff, 10);
		res += buff;
		res += ")</td></tr></table>";
		ofstream out(fname, ios::app);
		out << res << endl;
		out.close();
	}
};

class TXTExportVisitor : public Visitor
{
	string fname;
public:
	TXTExportVisitor(string fn) : fname(fn) {}
	void visit(Point* p)
	{
		string res = "";
		res += "Point x =";
		char buff[10];
		_itoa(p->x, buff, 10);
		res += buff;
		res += " y =";
		_itoa(p->y, buff, 10);
		res += buff;		
		ofstream out(fname, ios::app);
		out << res << endl;
		out.close();
	}
	void visit(Circle* c)
	{
		string res = "";
		res += "Circle x =";
		char buff[10];
		_itoa(c->x, buff, 10);
		res += buff;
		res += " y =";
		_itoa(c->y, buff, 10);
		res += buff;
		res += " r =";
		_itoa(c->r, buff, 10);
		res += buff;
		ofstream out(fname, ios::app);
		out << res << endl;
		out.close();
	}
	void visit(Rectangl* r)
	{
		string res = "";
		res += "Rectangle P1(";
		char buff[10];
		_itoa(r->x1, buff, 10);
		res += buff;
		res += ", ";
		_itoa(r->y1, buff, 10);
		res += buff;
		res += ") P2(";
		_itoa(r->x2, buff, 10);
		res += buff;
		res += ", ";
		_itoa(r->y2, buff, 10);
		res += buff;
		res += ")";
		ofstream out(fname, ios::app);
		out << res << endl;
		out.close();
	}
};

class Perimetr : public Visitor
{
public:
	void visit(Point* p)
	{
	}

	void visit(Circle* c)
	{
		cout <<"Длина окружности: "<<3.14 * (float)c->r * c->r << endl;
	}
	void visit(Rectangl* r)
	{
		cout << "Периметр прямоугольника: "<<2*abs(r->x1 - r->x2)+2*abs(r->y1 - r->y2) << endl;
	}
};

void Point::accept(Visitor* v)
{
	v->visit(this);
}

void Circle::accept(Visitor* v)
{
	v->visit(this);
}

void Rectangl::accept(Visitor* v)
{
	v->visit(this);
}

/*IFigure* arr[] = { new Point(2,4), new Circle(3,6,5), new Circle(2,5,6), new Rectangl(2,4,6,7) };
for (auto x : arr)
x->print();

	Visitor* visitor = new HTMLExportVisitor("index.html");
	for (auto x : arr)
		x->accept(visitor);

	visitor = new TXTExportVisitor("index.txt");
	for (auto x : arr)
		x->accept(visitor);
IFigure* arr1[] = { new Circle(3,6,5), new Circle(2,5,6), new Rectangl(2,4,6,7) };
Visitor* visitor1 = new Perimetr;
for (auto x : arr1)
x->accept(visitor1);*/
