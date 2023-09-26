#include "Alumno.h"
#include "Object.h"
#include <string>
using namespace std;

// Constructor
Alumno::Alumno() {
}

Alumno::Alumno(string name,string account) {
	this->Nombre = name;
	this->Cuenta = account;
}

// Destructor
Alumno::~Alumno() {
	//Eliminanos al Alumno;
}

// Valor a ToString
string Alumno::toString() {
	//String de Información Completa del Alumno
	string info_Alumno;
	info_Alumno = "Nombre: " + this->Nombre + ", Numero de Cuenta: " + this->Cuenta;

	return info_Alumno;
}

// Comparación de Alumnos
bool Alumno::equals(Object* Object_Compare) {
	if (dynamic_cast<Alumno*>(Object_Compare)) {
		Alumno* Alumno_Compare = dynamic_cast<Alumno*>(Object_Compare);
		// Verificar si la conversión a Alumno fue exitosa
		if (Alumno_Compare != nullptr) {
			// Comparar los números de cuenta de los alumnos
			if (Alumno_Compare->Cuenta == this->Cuenta) {
				return true;
			}
		}
	}
	return false;
}

Object* Alumno::copy() {
	return new Alumno(Nombre, Cuenta);
}

string Alumno::getCuenta() {
	return Cuenta;
}

string Alumno::getNombre() {
	return Nombre;
}

void Alumno::setNombre(string nombre) {
	this->Nombre = nombre;
}

void Alumno::setCuenta(string cuenta) {
	this->Cuenta = cuenta;
}