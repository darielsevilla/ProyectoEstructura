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
	virtual void copy(Object*) override;
	char getCaracter();
	void setCharacter(char);

};

