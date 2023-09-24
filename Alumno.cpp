#include <iostream>
#include "Alumno.h"
#include "Object.h"
#include <string>
using namespace std;

Alumno::Alumno(string nombre, int cuenta) {
    this->Nombre = nombre;
    this->Cuenta = cuenta;
}

Alumno::~Alumno() {
    delete& Nombre;
    delete& Cuenta;
}

string Alumno::toString() {
    string infoAlumno = "Nombre: " + this->Nombre + ", No. Cuenta: " + to_string(Cuenta);
    return infoAlumno;
}

bool Alumno::equals(Object* objetoCompara) {
    Alumno* alumnoCompara = dynamic_cast<Alumno*>(objetoCompara);
    if (alumnoCompara->Cuenta == this->Cuenta) {
        return true;
    }
    return false;
}