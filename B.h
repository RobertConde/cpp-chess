#ifndef B_H_INCLUDED
#define B_H_INCLUDED

class A;

class B
{

public:
	A* m_b_big;

	B(A* big) : m_b_big(big) { };
	A memberA();
};

#include "A.h"

A B::memberA() {
	m_b_big->m_a_num;   // Just a test

}
//A functionA()     { A e();        return e; }

#endif