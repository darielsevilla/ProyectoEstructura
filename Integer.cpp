#include "Integer.h"
Integer::Integer(int x) {
	this->elemento = x;
}

// Getter
int Integer::getElemento() {
	return elemento;
}

// Setter
void Integer::setElemento(int nuevoElemento) {
	this->elemento = nuevoElemento;
}


bool Integer::equals(Object* obj) {
	if (dynamic_cast<Integer*>(obj))
		if (elemento == dynamic_cast<Integer*>(obj)->elemento) return true;
	return false;
}

string Integer::toString() {
	return to_string(elemento);
}

Object* Integer::copy() {
	Object* temporal = new Integer(elemento);
	return temporal;
}