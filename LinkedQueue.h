#pragma once
#include "TDACola.h"
#include "Node.h"
class LinkedQueue :
    public TDACola
{
private:
    Node* first;
	Node* last;
public:
    LinkedQueue();
    ~LinkedQueue();
	virtual void queue(Object*) override;
	virtual Object* dequeue() override;
	virtual void clear() override;
	virtual Object* peek() override;
	virtual void print() override;
    
};

