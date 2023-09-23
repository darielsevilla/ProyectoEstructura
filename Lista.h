#pragma once
#include "Object.h"
#include "Integer.h"
class Lista
{

public:
	int size;
	//inserta(Object*, int) -> inserta un elemento a la lista en la posicion dada (entre 1 y n+1)
	virtual bool inserta(Object*, int) = 0;
	//suprime(int) -> elimina el elemento de la lista en la posicion dada (entre 1 y n)
	virtual bool suprime(int) = 0;
	virtual Object* siguiente(int) = 0;
	virtual Object* anterior(int) = 0;
	//anula() -> elimina todos los elementos de la lista
	virtual void anula() = 0;
	//localiza(Object*) -> retorna la primera posicion donde se encuentre el object enviado como parametro
	virtual int localiza(Object*) = 0;
	virtual void append(Object*) = 0;
	virtual Object* recupera(int) = 0;
	virtual Lista* localizaTodos(Object*) = 0;
	bool isEmpty() {return size == 0;};
	virtual void imprime() = 0;
	virtual void suprimeTodos(Object*) = 0;
	//primero() -> regresa el primer elemento de la lista, si existe 
	virtual Object* primero() = 0;


};

