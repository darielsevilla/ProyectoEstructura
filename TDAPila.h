#pragma once
#include "Object.h"
#include "Node.h"
#include "Integer.h"
class TDAPila
{

public:
	int size = 0;
	virtual void push(Object*) = 0;
	virtual Object* pop() = 0;
	virtual Object* top() = 0; 
	virtual bool isEmpty() = 0;
	virtual void clear() = 0;
	virtual void print() = 0;
};

