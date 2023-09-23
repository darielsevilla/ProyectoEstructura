#include "Integer.h"
Integer::Integer(int x) {
	this->elemento = x;
}

bool Integer::equals(Object* obj) {
	if (dynamic_cast<Integer*>(obj))
		if (elemento == dynamic_cast<Integer*>(obj)->elemento) return true;
	return false;
}

string Integer::toString() {
	return to_string(elemento);
}

void Integer::copy(Object* obj) {
	if (dynamic_cast<Integer*>(obj))
		this->elemento = dynamic_cast<Integer*>(obj)->elemento;
}