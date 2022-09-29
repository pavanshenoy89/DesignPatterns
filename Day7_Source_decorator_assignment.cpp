#include<iostream>
using namespace std;


class ITeaInterface
{
public:
	virtual void makeTea() = 0;
};

class NormalTea : public ITeaInterface
{
public:
	void makeTea()  override
	{
		cout << "Preparing Normal Tea";
	}
};

class AddOnTea : public ITeaInterface
{
	ITeaInterface *tea;
protected:
	AddOnTea(ITeaInterface *t) :tea(t) {}
public:
	void makeTea()
	{
		tea->makeTea();
	}
};

class Addon1Milk :public AddOnTea
{
	
public:
	Addon1Milk(ITeaInterface* t) :AddOnTea(t){}

	void makeTea() override
	{
		AddOnTea::makeTea();
		cout << " + adding extra milk";
	}
};

class Addon2Sugar :public AddOnTea
{
public:

	Addon2Sugar(ITeaInterface* t) :AddOnTea(t) {}

	void makeTea() override
	{
		AddOnTea::makeTea();
		cout << " + adding extra sugar";
	}
};

class Addon3Masala :public AddOnTea
{
	
public:
	Addon3Masala(ITeaInterface* t) :AddOnTea(t) {}

	void makeTea() override
	{
		AddOnTea::makeTea();
		cout << " + adding extra masala";
	}
};


int main()
{
	ITeaInterface* Tea_type1 = new NormalTea();
	Tea_type1 = new Addon2Sugar(Tea_type1);
	Tea_type1 = new Addon3Masala(Tea_type1);

	Tea_type1->makeTea();
	return 0;


}



