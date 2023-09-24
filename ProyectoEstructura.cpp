#include <iostream>
#include <locale.h>
#include "Node.h"
#include "LinkedList.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "CircularQueue.h"
#include "Simbolo.h"
#include "ArrayList.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "Alumno.h"

//Revisa que los valores sea solamente numeros
bool isNumber(string recibido) {
	for (char c : recibido) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

void listsMenu() {
	int opcion = 0;
	Lista* list = NULL;
	while (opcion != 3)
	{
		string eleccion = "\nMen� Tipo de Lista\n 1. Trabajar con ArrayList\n 2. Trabajar con Linked List\n 3. Volver a men� principal\nIngrese opci�n: ";
		while (cout << eleccion && (!(cin >> opcion) || (opcion < 1 || opcion > 3))) {
			cin.clear();
			cout << "\n*Ingrese opci�n valida*\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		if (opcion == 1)
			list = new ArrayList();
		else if (opcion == 2)
			list = new LinkedList();

		//sub menu de opciones
		if (opcion != 3) {
			int menu = 0;
			string sub = "\nOperaciones de Listas:\n";
			sub += " 1. \Insertar Elemento\n";
			sub += " 2. \Imprimir Elementos\n";
			sub += " 3. Buscar Elemento\n";
			sub += " 4. Borrar Elemento\n";
			sub += " 5. Ver si est� vac�a\n";
			sub += " 6. Obtener Elemento por Posici�n\n";
			sub += " 7. Obtener Siguiente\n";
			sub += " 8. Obtener Anterior\n";
			sub += " 9. Borrar todos los Elementos (Anula)\n";
			sub += " 10. Regresar al Men� Anterior\n";
			sub += "Ingrese opci�n: ";

			do {
				while (cout << sub && (!(cin >> menu) || menu < 1 || menu > 10)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n*Ingrese valor valido*\n";
				}

				Object* estudiante = NULL;

				switch (menu)
				{
				case 1: {
					string nombreAlumno;
					string cuentaAlumno;
					cin.clear();
					cin.ignore();
					cout << "Ingrese el nombre del estudiante: " << endl;
					getline(cin, nombreAlumno);

					cout << "Ingrese el numero de cuenta del estudiante: " << endl;
					cin >> cuentaAlumno;

					while (!isNumber(cuentaAlumno))
					{
						cout << endl << "Ingrese un N�mero de Cuenta V�lido." << endl;
						cout << "Ingrese el N�mero de Cuenta del Alumno: ";
						cin >> cuentaAlumno;
					}

					estudiante = new Alumno(nombreAlumno, cuentaAlumno);

					list->append(estudiante);
					cout << "Alumno agregado correctamente" << endl;
				}//Inserta
					  break;
				case 2: {
					list->imprime();
				}//Imprimir Elementos
					  break;
				case 3: {
					if (list->isEmpty())
					{
						cout << "No se pueden buscar alumnos debido a que la lista se encuentra vacia" << endl;
					}
					else {
						printf("\n");
						cout << "Ingrese el numero de cuenta que desea buscar: " << endl;
						string strCuenta;
						cin >> strCuenta;

						while (!isNumber(strCuenta))
						{
							cout << endl << "Ingrese un N�mero de Cuenta V�lido." << endl;
							cout << "Ingrese el N�mero de Cuenta del Alumno: ";
							cin >> strCuenta;
						}

						int posicionBuscar = list->localiza(new Alumno("", strCuenta));
						if (posicionBuscar > 0 && posicionBuscar <= list->size)
						{
							cout << "Alumno encontrado" << endl;
							cout << list->recupera(posicionBuscar)->toString() << " Est� en la Posici�n " << posicionBuscar << "." << endl;
						}
					}
				}//Buscar Elemento
					  break;
				case 4: {
					int posAEliminar =0;
					cout << "Ingrese la posicion que desea eliminar: " << endl;
					cin >> posAEliminar;

					if (posAEliminar > 0 && posAEliminar <= list->size)
					{
						list->suprime(posAEliminar);
						cout << "Alumno eliminado correctamente" << endl;
					}
					else {
						cout << "Posicion fuera del rango" << endl;
					}
				}//Borrar Elemento
					  break;
				case 5: {
					printf("\n");
					if (list->isEmpty()) cout << "La lista se encuentra vacia actualmente" << endl;
					else cout << "La lista contiene elementos" << endl;

				}//Ver si la lista esta vacia
					  break;
				case 6: {
					cout << "Ingrese la posicion en la que desea conseguir el elemento: " << endl;
					int posicionElemento;
					cin >> posicionElemento;


					if (posicionElemento > 0 && posicionElemento <= list->size)
					{
						estudiante = new Alumno();
						estudiante = list->recupera(posicionElemento);

						cout << estudiante->toString();
					}
					else {
						cout << "Posicion fuera del rango" << endl;
					}
				}//Obtener elementos por posicion
					  break;
				case 7: {
					cout << "Ingrese la posicion en la que desea conseguir el elemento siguiente: " << endl;
					int posicionElemento;
					cin >> posicionElemento;


					if (posicionElemento > 0 && posicionElemento + 1 <= list->size)
					{
						estudiante = new Alumno();
						estudiante = list->siguiente(posicionElemento);

						cout << estudiante->toString();
					}
					else {
						cout << "Posicion fuera del rango" << endl;
					}
				}//Obtener siguiente
					  break;
				case 8: {
					cout << "Ingrese la posicion en la que desea conseguir el elemento siguiente: " << endl;
					int posicionElemento;
					cin >> posicionElemento;


					if (posicionElemento - 1 > 0 && posicionElemento <= list->size)
					{
						estudiante = new Alumno();
						estudiante = list->anterior(posicionElemento);

						cout << estudiante->toString();
					}
					else {
						cout << "Posicion fuera del rango" << endl;
					}
				}//Obtener anterior
					  break;
				case 9: {
					if (!list->isEmpty())
					{
						list->anula();
						cout << "Se ha eliminado la lista" << endl;
					}
					else {
						cout << "La lista ya se encuentra vacia" << endl;
					}
				}//Borrar todos los elementos(Anula)
					  break;
				}
			} while (menu != 10);
		}
	}//Llave while tipo de lista
}//Llave metodo
//stackmenu() -> metodo void que corre las operaciones del menu de pilas

void stackMenu() {
	int opcion = 0;
	TDAPila* stack = NULL;
	//eleccion de tipo de pila
	do {
		string eleccion = "\nMen� Tipo de Pila\n 1. Trabajar con ArrayStack\n 2. Trabajar con LinkedStack\n 3. Volver a men� principal\nIngrese opci�n: ";
		while (cout << eleccion && (!(cin >> opcion) || (opcion < 1 || opcion > 3))) {
			cin.clear();
			cout << "\n*Ingrese opci�n valida*\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		//eleccion de stack
		if (opcion == 1)
			stack = new ArrayStack();
		else if (opcion == 2)
			stack = new LinkedStack();

		//sub menu de opciones
		if (opcion != 3) {
			int menu;
			string sub = "\nOperaciones de pilas:\n";
			sub += " 1. \"Empujar\"(push)\n";
			sub += " 2. \"Sacar\"(pop)\n";
			sub += " 3. Ver Tope (top)\n";
			sub += " 4. Verificar si est� vac�a\n";
			sub += " 5. Imprimir elementos\n";
			sub += " 6. Borrar todos los elementos\n";
			sub += " 7. Regresar al Men� anterior\n";
			sub += "Ingrese opci�n: ";

			//validacion subMenu
			do {
				while (cout << sub && (!(cin >> menu) || menu < 1 || menu > 7)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n*Ingrese valor valido*\n";
				}

				//variables necesarias
				char simbolo;
				Object* currentSymbol = NULL;
				string validacionDeSimbolo;
				//operaciones de pilas
				switch (menu) {
				case 1:
					//ingresamiento de un caracter o simbolo (validado de que solo sea 1)
					while (cout << "\nIngrese un simbolo para agregar a la pila: " && cin >> validacionDeSimbolo && validacionDeSimbolo.size() > 1) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n*Ingrese solo 1 caracter*\n";
					}
					currentSymbol = new Simbolo(validacionDeSimbolo.at(0));
					stack->push(currentSymbol);
					break;
				case 2:
					//saca al ultimo elemento ingresado a la pila (validado para que imprima un mensaje diferente si la pila esta vacia)
					if (!stack->isEmpty()) {
						currentSymbol = stack->pop();
						cout << "\nEl siguiente s�mbolo salio de la pila : " << dynamic_cast<Simbolo*>(currentSymbol)->getCaracter() << "\n";
						delete currentSymbol;
					}
					else {
						cout << "\nNo hay nada que sacar de la pila\n";
					}
					break;
				case 3:
					//si existe, revisa el siguiente elemento a salir de la stack, sin sacarlo
					if (!stack->isEmpty()) {
						currentSymbol = stack->top();
						cout << "\nEl siguiente s�mbolo esta a la cima de la pila : " << dynamic_cast<Simbolo*>(currentSymbol)->getCaracter() << "\n";
					}
					else {
						cout << "\nNo hay nada en la pila\n";
					}
					break;
				case 4:
					//verificaciond e si esta vacia o no
					if (stack->isEmpty()) cout << "\nEst� vacia\n";
					else cout << "\nNo esta Vacia\n";
					break;
				case 5:
					//impresion de los elementos de la stack
					if (!stack->isEmpty()) {
						cout << "\nImpresi�n de elementos: \n";
						stack->print();
					}
					else {
						cout << "\nNo hay elementos para imprimir\n";
					}
					break;
				case 6:
					//vaciar la stack
					stack->clear();
					cout << "\nLos elementos de la lista han sido borrados\n";
					break;
				}
			} while (menu != 7);
			if (stack) delete stack;
		}


	} while (opcion != 3);
}




void queuesMenu() {
	int opcionMenu = 0;
	TDACola* queue = NULL;

	while (opcionMenu != 4) {
		string eleccion = "\nMEN� TIPO DE COLA\n 1. Trabajar con ArrayQueue\n 2. Trabajar con LinkedQueue\n 3.Trabajar con LinkedQueue\n 4. Volver a men� principal\nIngrese opci�n: ";
		while (cout << eleccion && (!(cin >> opcionMenu) || (opcionMenu < 1 || opcionMenu > 4))) {
			cin.clear();
			cout << "\nERROR - 404";
			cout << "\nIngrese opci�n valida...\n";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (opcionMenu) {
		case 1: {
			queue = new ArrayQueue();
		}
			  break;

		case 2: {
			queue = new LinkedQueue();
		}
			  break;

		case 3: {
			queue = new CircularQueue();
		}
			  break;
		}

		int opcion;
		int num;
		cout << endl
			<< " >> OPERACIONES DE COLAS <<" << endl
			<< "1. Encolar (Queue)" << endl
			<< "2. Desencolar (Dequeue)" << endl
			<< "3. Ver Frente (Peek)" << endl
			<< "4. Vacia" << endl
			<< "5. Imprimir Elementos" << endl
			<< "6. Borrar los Elementos" << endl
			<< "7. Regresar al Menu Anterior" << endl
			<< "Ingrese una opcion: ";
		cin >> opcion;

		if (opcion < 1 || opcion > 7) {
			//Entra si los valores no estan dentro del rango
			while (opcion < 1 || opcion > 7) {
				//Valida hasta que se ingrese un valor v�lido
				cout << endl
					<< "ERROR - 404"
					<< "Ingrese un Valor de Menu V�lido..." << endl
					<< "Ingrese una opcion: ";
				cin >> opcion;
			}
		}
		else {//Entra al men� de opciones de Queue
			Object* student = new Alumno();
			string Nombre = "";
			string Cuenta;

			switch (opcion) {
			case 1: { //Encolar (Queue)
				cin.ignore();
				cout << "Ingrese el nombre del alumno: ";
				cin >> Nombre;

				cout << "Ingrese el numero de cuenta del alumno: ";
				cin >> Cuenta;

				while (!isNumber(Cuenta)) {
					cout << endl << "ERROR - 404"
						<< "Ingrese un N�mero de Cuenta V�lido..." << endl
						<< endl;

					cout << "Ingrese el N�mero de Cuenta del Alumno: ";
					cin >> Cuenta;
				}

				queue->queue(new Alumno(Nombre, Cuenta));
				cout << "Alumno encolado correctamente" << endl;
			}
				  break;

			case 2: { //Desencolar (Dequeue)
				if (queue->isEmpty()) {
					cout << "La Cola est� vacia" << endl
						<< "No Hay Nada Que Sacar..." << endl;
				}
				else {
					cout << "El Alumno sacado de la cola es : " << queue->dequeue()->toString() << endl;
				}
			}
				  break;


			case 3: { //Ver Frente (Peek)
				if (queue->isEmpty()) {
					cout << "La Cola Est� Vac�a" << endl;
				}
				else {
					cout << "El elemento al frente de la cola es: " << queue->peek()->toString() << endl;
				}
			}
				  break;

			case 4: { //Vacia
				if (queue->isEmpty()) {
					cout << "La Cola Est� Vac�a" << endl;
				}
				else {
					cout << "La Cola Tiene Elementos en Ella" << endl;
				}
			}
				  break;

			case 5: { //Imprimir Elementos
				if (queue->isEmpty()) {
					cout << "La Cola Est� Vac�a" << endl;
				}
				else {
					cout << endl
						<< ">>>>>>>>>>>>> Pila <<<<<<<<<<<<<" << endl;
					queue->print();
				}
				break;
			}
				  break;

			case 6: { //Borrar los Elementos
				if (queue->isEmpty()) {
					cout << "La Cola Est� Vac�a" << endl;
				}
				else {
					queue->clear();
					cout << "Elementos han Sido Eliminados EXITOSAMENTE" << endl;
				}
			}
				  break;

			case 7: { //Regresar al Menu Anterior
				cout << "Regresando al Men� Anterior" << endl;
			}
				  break;

			default: {
				cout << "ERROR - 404!" << endl
					<< "Opcion de Men� Seleccionado NO V�lido" << endl
					<< endl << "Ingrese UNA Opci�n V�LIDA";
			}
			}
		}//Fin del men� de opciones de Queue
	}
}


int main() {
	setlocale(LC_ALL, "spanish");
	//validacion de entrada
	int opcion;
	do {
		string mensajeMenu = "\nMenu principal\n 1. Trabajar con Listas\n 2. Trabajar con Pilas\n 3. Trabajar con Colas\n 4. Salir\nIngrese opcion: ";
		while (cout << mensajeMenu && (!(cin >> opcion) || opcion < 1 || opcion > 4)) {


			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n*Ingrese opcion valida*\n";

			// || opcion < 1 || opcion > 4

		}


		//entrada a opciones
		switch (opcion) {
		case 1:
			listsMenu();
			//menu de opcion de listas
			break;
		case 2:
			//menu de opciones de pilas
			stackMenu();
			break;
		case 3:
			queuesMenu();
			//menu de opcion de colas
			break;
		}
	} while (opcion != 4);
}

