#pragma once
#include "Object.h"
class Simbolo : public Object
{
private:
	char caracter;
public:
	Simbolo(char caracter = ' ');
	virtual string toString() override;
	virtual bool equals(Object*) override;
	virtual Object* copy() override;
	//getCharacter() -> retorna el atribulo 'caracter' de la instancia
	char getCaracter();
	//setCharacter() -> setea el atribulo 'caracter' de la instancia
	void setCharacter(char);

};

