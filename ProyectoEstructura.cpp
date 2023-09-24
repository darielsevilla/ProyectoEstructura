#include <iostream>
#include <locale.h>
#include "Node.h"
#include "LinkedList.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "Simbolo.h"
#include "ArrayList.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "Alumno.h"

void listsMenu() {
	int opcion = 0;
	Lista* list = NULL;
	while (opcion != 3)
	{
		string eleccion = "\nMenú Tipo de Lista\n 1. Trabajar con ArrayList\n 2. Trabajar con Linked List\n 3. Volver a menú principal\nIngrese opción: ";
		while (cout << eleccion && (!(cin >> opcion) || (opcion < 1 || opcion > 3))) {
			cin.clear();
			cout << "\n*Ingrese opción valida*\n";
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
			sub += " 5. Ver si está vacía\n";
			sub += " 6. Obtener Elemento por Posición\n";
			sub += " 7. Obtener Siguiente\n";
			sub += " 8. Obtener Anterior\n";
			sub += " 9. Borrar todos los Elementos (Anula)\n";
			sub += " 10. Regresar al Menú Anterior\n";
			sub += "Ingrese opción: ";

			do {
				while (cout << sub && (!(cin >> menu) || menu < 1 || menu > 10)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n*Ingrese valor valido*\n";
				}

				switch (menu)
				{
				case 1: {
					cout << "Ingrese el elemento que desea agregar: ";
					Object* elemento = NULL;
					cout << "Ingrese la posición en la que desea agregar: ";
					int posicion;

				}
					  break;
				case 2: {

				}
					  break;
				case 3: {

				}
					  break;
				case 4: {

				}
					  break;
				case 5: {

				}
					  break;
				case 6: {

				}
					  break;
				case 7: {

				}
					  break;
				case 8: {

				}
					  break;
				case 9: {

				}
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
		string eleccion = "\nMenú Tipo de Pila\n 1. Trabajar con ArrayStack\n 2. Trabajar con LinkedStack\n 3. Volver a menú principal\nIngrese opción: ";
		while (cout << eleccion && (!(cin >> opcion) || (opcion < 1 || opcion > 3))) {
			cin.clear();
			cout << "\n*Ingrese opción valida*\n";
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
			sub += " 4. Verificar si está vacía\n";
			sub += " 5. Imprimir elementos\n";
			sub += " 6. Borrar todos los elementos\n";
			sub += " 7. Regresar al Menú anterior\n";
			sub += "Ingrese opción: ";

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
						cout << "\nEl siguiente símbolo salio de la pila : " << dynamic_cast<Simbolo*>(currentSymbol)->getCaracter() << "\n";
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
						cout << "\nEl siguiente símbolo esta a la cima de la pila : " << dynamic_cast<Simbolo*>(currentSymbol)->getCaracter() << "\n";
					}
					else {
						cout << "\nNo hay nada en la pila\n";
					}
					break;
				case 4:
					//verificaciond e si esta vacia o no
					if (stack->isEmpty()) cout << "\nEstá vacia\n";
					else cout << "\nNo esta Vacia\n";
					break;
				case 5:
					//impresion de los elementos de la stack
					if (!stack->isEmpty()) {
						cout << "\nImpresión de elementos: \n";
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

	while (opcionMenu != 3) {
		string eleccion = "\nMENÚ TIPO DE COLA\n 1. Trabajar con ArrayQueue\n 2. Trabajar con LinkedQueue\n 3. Volver a menú principal\nIngrese opción: ";
		while (cout << eleccion && (!(cin >> opcionMenu) || (opcionMenu < 1 || opcionMenu > 3))) {
			cin.clear();
			cout << "\nERROR - 404";
			cout << "\nIngrese opción valida...\n";
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
				//Valida hasta que se ingrese un valor válido
				cout << endl
					<< "ERROR - 404"
					<< "Ingrese un Valor de Menu Valido " << endl
					<< "Ingrese una opcion: ";
				cin >> opcion;
			}
		}
		else {//Entra al menú de opciones de Queue
			switch (opcion) {
			case 1: { //Encolar (Queue)

			}
				  break;

			case 2: { //Desencolar (Dequeue)

			}
				  break;


			case 3: { //Ver Frente (Peek)

			}
				  break;

			case 4: { //Vacia

			}
				  break;

			case 5: { //Imprimir Elementos

			}
				  break;

			case 6: { //Borrar los Elementos

			}
				  break;

			case 7: { //Regresar al Menu Anterior

			}
				  break;
			}
		}//Fin del menú de opciones de Queue
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
			//menu de opcion de listas
			break;
		case 2:
			//menu de opciones de pilas
			stackMenu();
			break;
		case 3:
			//menu de opcion de colas
			break;
		}
	} while (opcion != 4);
}

