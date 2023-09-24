#pragma once
#include <iostream>
#include "Alumno.h"
#include "Object.h"
#include <string>
using namespace std;

class Alumno : public Object {

private:
	string Nombre;
	int Cuenta;

public:
	Alumno(); // Constructor Vacio
	Alumno(string, int); // Constructor Sobrecargado
	~Alumno(); // Destructor
	virtual string toString(); // Todo a ToString
	virtual bool equals(Object*); // Encontrar Alumnos iguales
};