#pragma once
#include "Integer.h"
class TDACola
{
protected:
	int size;
public:
	TDACola();
	virtual void queue(Object*) = 0;
	virtual Object* dequeue() = 0;
	int getSize();
	bool isEmpty();
	virtual void clear() = 0;
	virtual Object* peek() = 0;
	virtual void print() = 0;

};

