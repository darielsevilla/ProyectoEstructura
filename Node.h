#pragma once
#include "Object.h"
class Node
{
private:
	Node* anterior;
	Node* siguiente;
	Object* nodeObj;
public:
	void setPrior(Node*);
	void setNext(Node*);
	Node* getNext();
	Node* getPrior();
	void setObj(Object*);
	Object* getObj();
	Node();
	Node(Object*);
	~Node();
};

