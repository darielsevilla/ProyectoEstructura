#pragma once
#include <iostream>
#include <string>
using namespace std;

class Object{	
public:    
	//equals(Object*) -> recibe un pointer a un object y lo compara con el objeto actual. si son iguales, retorna true. si no, retorna false.
	virtual bool equals(Object*) = 0;
	//toString() -> retorna una representación en cadena de objeto
	virtual string toString() = 0;
	//copy() -> copia los elementos del objeto en otra instancia y la retorna
	virtual Object* copy() = 0;
};

