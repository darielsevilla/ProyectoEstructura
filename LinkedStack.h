#pragma once
#include "TDAPila.h"
class LinkedStack :
    public TDAPila
{
public:
	Node* topNode;
	LinkedStack();
	virtual void push(Object*) override; 
	virtual Object* pop() override;
	virtual Object* top() override;
	virtual bool isEmpty() override;
	virtual void clear() override;
	virtual void print() override;
	~LinkedStack();
};

