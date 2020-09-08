//цепочка обязанностей платеж в банке
#pragma once
#include<iostream>
#include<string>

using namespace std;

class Handler
{
protected:
	Handler* nextHandler; //след. обработчик
public:
	Handler() {}
	Handler(Handler* nh): nextHandler(nh){}
	virtual void sendPayment(int cum) = 0; //сделать платеж
	Handler* setHandler(Handler* nh) { nextHandler = nh; return nextHandler; }
};

class Client
{
	Handler* nextHandler;
public:
	Client(){}
	Client(Handler* nh):nextHandler(nh) {}
	  void sendPayment(int sum)
	  {
		  if (nextHandler)
			  nextHandler->sendPayment(sum);
	  }
	  Handler* setHandler(Handler* nh) { nextHandler = nh; return nextHandler; }
};

class EconomistHandler :public Handler
{
	
public:
	EconomistHandler(){}
	EconomistHandler(Handler* nh) :Handler(nh) {}
	  void sendPayment(int sum)
	  {
		  if (sum > 1000)
		  {
			  if (nextHandler)
				  nextHandler->sendPayment(sum);
		  }
		  else cout << "Платеж проведен экономистом" << endl;
	  }
	  Handler* setHandler(Handler* nh) { nextHandler = nh; return nextHandler; }
};

class Buhgalter :public Handler
{
	
public:
	Buhgalter() {}
	Buhgalter(Handler* nh) :Handler(nh) {}
	void sendPayment(int sum)
	{
		if (sum > 5000)
		{
			if (nextHandler)
				nextHandler->sendPayment(sum);
		}
		else cout << "Платеж проведен бухгалтером" << endl;
	}
	Handler* setHandler(Handler* nh) { nextHandler = nh; return nextHandler; }

};


class DirectoR :public Handler
{
	
public:
	DirectoR(){}
	DirectoR(Handler* nh) :Handler(nh) {}
	void sendPayment(int sum)
	{
		if (sum > 10000)
		{
			if (nextHandler)
				nextHandler->sendPayment(sum);
			else cout << "нужен совет директоров, а у нас его нет, платеж не проведен" << endl;
		}
		else cout << "Платеж проведен директором" << endl;
	}
	Handler* setHandler(Handler* nh) { nextHandler = nh; return nextHandler; }

};

//Client* client = new Client;
//client->setHandler(new EconomistHandler)->
//setHandler(new Buhgalter)->
//setHandler(new DirectoR);
//client->sendPayment(18000);