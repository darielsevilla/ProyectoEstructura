#pragma once
#include "TDACola.h"
class ArrayQueue :
    public TDACola
{
private:
	int capacidad;
	Object** array;
	void resize();
public:
	ArrayQueue();
	~ArrayQueue();
	virtual void queue(Object*) override;
	virtual Object* dequeue() override;
	virtual void clear() override;
	virtual Object* peek() override;
	virtual void print() override;
};

