#pragma once
#include<iostream>
using namespace std;
class C;
class D;

class A {
public:
	virtual void foo();

	virtual void accept(C* visitor);
};
class B :public A {
public:
	void foo();
};

class C {
public:
	virtual void fun(A* obj);
	virtual void fun(B* obj);
};

class D :public C {
public:
	void fun(A* obj);
	void fun(B* obj);
};

///end of header

#include"Source.h"


	void A::foo() { cout<<"A implementation"; }

	void A::accept(C* visitor) {
		visitor->fun(this);
	}


	void B::foo() { cout << "B implementation"; }


    void C::fun(A* obj) {
		cout << "C-A implementation";
		obj->foo();
	}

	void C::fun(B* obj) {
		cout << "C-B implementation";
		obj->foo();
	}


	void D::fun(A* obj) {
		cout << "D-A implementation";
		obj->foo();
	}
	void D::fun(B* obj) {
		cout << "D-B implementation";
		obj->foo();
	}


int main()
{
	A *obj = new B();

	C *c_obj = new D();
	obj->accept(c_obj);

	return 0;
}






