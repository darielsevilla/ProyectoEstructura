#pragma once
#include "Lista.h"
#include "Node.h"
class LinkedList :
    public Lista
{
public:
	Node* nodo;
	LinkedList(); //
	~LinkedList(); //
	virtual bool inserta(Object*, int) override; // 
	virtual bool suprime(int) override; //
	virtual Object* siguiente(int) override; //
	virtual Object* anterior(int) override; //
	virtual void anula() override; //
	virtual int localiza(Object*) override; 
	virtual void append(Object*) override; //
	virtual Object* recupera(int) override; //
	virtual Lista* localizaTodos(Object*) override;
	virtual void imprime() override; //
	virtual void suprimeTodos(Object*) override; //
	virtual Object* primero() override;//
};

