#include "Alumno.h"
#include "Object.h"
#include <string>
using namespace std;

// Constructor
Alumno::Alumno() {
}

Alumno::Alumno(string name, int account) {
	this->Nombre = name;
	this->Cuenta = account;
}

// Destructor
Alumno::~Alumno() {
	//Eliminanos al Alumno;
}

// Valor a ToString
string Alumno::toString() {
	//String de Informaci�n Completa del Alumno
	string info_Alumno;
	info_Alumno = "Nombre: " + this->Nombre + ", Numero de Cuenta: " + to_string(Cuenta);

	return info_Alumno;
}

// Comparaci�n de Alumnos
bool Alumno::equals(Object* Object_Compare) {
	Alumno* Alumno_Compare = dynamic_cast<Alumno*>(Object_Compare);
	// Verificar si la conversi�n a Alumno fue exitosa
	if (Alumno_Compare != nullptr) {
		// Comparar los n�meros de cuenta de los alumnos
		if (Alumno_Compare->Cuenta == this->Cuenta) {
			return true;
		}
	}
	return false;
}