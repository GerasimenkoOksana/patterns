#pragma once
#include<iostream>
#include<string>

using namespace std;
class Water;

class IWaterState
{
public:
	virtual void heat(Water* water) = 0; //метод воды нагреваться
	virtual void frost(Water* water) = 0; //метод воды остывать
};

class Water
{
	IWaterState* state;
public:
	Water(IWaterState* ws): state(ws){}
	void setState(IWaterState* ws)
	{
		if (state)
			delete state;
		state = ws;
	}
	void heat()
	{
		state->heat(this);
	}
	void frost()
	{
		state->frost(this);
	}
};

class SolidWaterState : public IWaterState //твердая вода - лед
{
public:
	void heat(Water* water)override;
	
	void frost(Water* water)override
	{
		cout << "Продолжаем замораживать лед" << endl;
	}
};

class LiquiWaterState : public IWaterState  //жидкая вода
{
public:
	void heat(Water* water)override;
	
	void frost(Water* water)override
	{
		cout << "вода превращается в лед" << endl;
		water->setState(new SolidWaterState);
	}
};

class GasWaterState : public IWaterState
{
public:
	void heat(Water* water)override
	{
		cout << "повышаем температуру пара" << endl;
	}
	void frost(Water* water)override
	{
		cout << "пар конденсируется в воду" << endl;
		water->setState(new LiquiWaterState);
	}
};

void SolidWaterState::heat(Water* water)
{
	cout << "лед плавится" << endl;
	water->setState(new LiquiWaterState);
}

void LiquiWaterState::heat(Water* water)
{
	cout << "вода превращается в пар" << endl;
	water->setState(new GasWaterState);
}

//Water* water = new Water(new SolidWaterState);
//water->heat();
//water->heat();
//water->heat();
//water->heat();
//water->frost();
//water->frost();
//water->frost();