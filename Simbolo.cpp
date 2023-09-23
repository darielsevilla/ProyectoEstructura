#include "Simbolo.h"

//Simbolo(char) -> genera un objeto Simbolo con su elemento caracter. Si el usuario no ingresa un character, el caracter por defecto es ' '
Simbolo::Simbolo(char caracter) {
	this->caracter = caracter;
}

//getCharacter() -> returna el elemento caracter
char Simbolo::getCaracter() {
	return caracter;
}

//setCharacter(char) -> setea el elemento caracter del objeto
void Simbolo::setCharacter(char caracter) {
	this->caracter = caracter;
}

//toString() -> retorna una cadena con el caracter del objeto
string Simbolo::toString() {
	string newString;
	newString += caracter;
	return newString;
}

//equals() -> compara los caracteres del pointer a simbolo con el del objeto actual. si son el mismo,retorna true. Si no son el mismo o no se envia un Simbolo* retorna false
bool Simbolo::equals(Object* obj) {
	if (dynamic_cast<Simbolo*>(obj))
		if (dynamic_cast<Simbolo*>(obj)->getCaracter() == this->caracter) return true;
	return false;
}

void Simbolo::copy(Object* obj) {
	if (dynamic_cast<Simbolo*>(obj))
		this->setCharacter(dynamic_cast<Simbolo*>(obj)->getCaracter());
}