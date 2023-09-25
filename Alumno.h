#pragma once
#include <iostream>
#include "Alumno.h"
#include "Object.h"
#include <string>
using namespace std;

class Alumno : public Object {

private:
	string Nombre;
	string Cuenta;

public:
	Alumno(); // Constructor Vacio
	Alumno(string, string); // Constructor Sobrecargado
	~Alumno(); // Destructor
	virtual string toString() override; // Todo a ToString
	virtual bool equals(Object*) override; // Encontrar Alumnos iguales
	virtual Object* copy() override;
	string getNombre();
	string getCuenta();
	void setNombre(string);
	void setCuenta(string);
};