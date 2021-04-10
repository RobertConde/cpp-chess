#ifndef A_H_INCLUDED
#define A_H_INCLUDED

class B;

class A
{
public:
	B* m_a_num;

	A();
	void memberB();
};

#include "B.h"
A::A() {
	m_a_num = new B(this);
}
void A::memberB() {
	B n(this);
	n.memberA();

}
//B functionB()     { B n(2);        return n; }

#endif