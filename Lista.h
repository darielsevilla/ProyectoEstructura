#pragma once
#include "Object.h"
#include "Integer.h"
class Lista
{

public:
	int size;
	virtual bool inserta(Object*, int) = 0;
	virtual bool suprime(int) = 0;
	virtual Object* siguiente(int) = 0;
	virtual Object* anterior(int) = 0;
	virtual void anula() = 0;
	virtual int localiza(Object*) = 0;
	virtual void append(Object*) = 0;
	virtual Object* recupera(int) = 0;
	virtual Lista* localizaTodos(Object*) = 0;
	bool isEmpty() {return size == 0;};
	virtual void imprime() = 0;
	virtual void suprimeTodos(Object*) = 0;
	virtual Object* primero() = 0;


};

