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
	//queue(Object*) -> inserta un elemento al final de la cola
	virtual void queue(Object*) override;
	//dequeue() -> saca un elemento del inicio lde la cola
	virtual Object* dequeue() override;
	//clear() -> elimina todos los elementos de la cola
	virtual void clear() override;
	//peek() -> retorna el elemento al frente de la cola sin sacarlo de la cola
	virtual Object* peek() override;
	//print() -> imprime todos los elementos de la cola en el orden en el que saldran
	virtual void print() override;
};

