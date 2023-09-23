#pragma once
#include "Integer.h"
class TDACola
{
protected:
	int size;
public:
	TDACola();
	//queue(Object*) -> inserta un object al final de la cola
	virtual void queue(Object*) = 0;
	//dequeue() -> elimina un object del frente de la cola
	virtual Object* dequeue() = 0;
	//getSize() -> devuelve la cantidad de elementos en la cola
	int getSize();
	//isEmpty() -> si no hay elementos en la cosa regresa true. de lo contrario regresa false
	bool isEmpty();
	//clear() -> elimina todos los elementos de la cola
	virtual void clear() = 0;
	//peek()-> retorna el primer elemento de la cola sin eliminarlo
	virtual Object* peek() = 0;
	//print()-> imrpime cada elemento de la cola
	virtual void print() = 0;

};

