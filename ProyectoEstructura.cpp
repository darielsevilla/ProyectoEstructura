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

//isRepeat(Lista*, string) -> recibe una lista y una string del numero de cuenta. compara todos los elementos de la lista buscando repeticion
bool isRepeat(Lista* list, string numeroDeCuenta) {
	Alumno* temporal = new Alumno("Temporal", numeroDeCuenta);
	for (int i = 1; i <= list->getSize(); i++) {
		if (dynamic_cast<Alumno*>(list->recupera(i))->equals(temporal)) {
			delete temporal;
			return true;
		}
	}
	delete temporal;
	return false;
}
//listsMenu() -> metodo void que corre las operaciones del menu de listas
void listsMenu() {
	int opcion = 0;
	Lista* list = NULL;
	while (opcion != 3) {
		string eleccion = "\n\n\033[33m>>>> MENÚ TIPOS DE LISTAS <<<<\033[0m\n 1) Trabajar con ArrayList\n 2) Trabajar con LinkedList\n 3) Volver a menú principal\n\n\033[33m- Ingrese Opción del Menú: \033[0m";
		while (cout << eleccion && (!(cin >> opcion) || (opcion < 1 || opcion > 3))) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			
			cout << "\033[31m"; // Cambio Color a Rojo
			cout << "ERROR 404 - Something went wrong...\n"
				<< "OPCIÓN INVÁLIDA!!!\n";
			cout << "Ingrese una Nueva Opción Válida\n";
			cout << "\033[0m"; // Cambio de Color a Blanco
			
			cin.clear();
		}

		if (opcion == 1)
			list = new ArrayList();
		else if (opcion == 2)
			list = new LinkedList();

		//sub menu de opciones
		if (opcion != 3) {
			int menu = 0;
			string sub = "\>> Operaciones de Listas <<\n";
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
					cout << "\033[31m"; // Cambio Color a Rojo
					cout << "ERROR 404 - Something went wrong...\n"
						<< "OPCIÓN INVÁLIDA!!!\n";
					cout << "Ingrese una Nueva Opción Válida\n";
					cout << "\033[0m"; // Cambio de Color a Blanco;
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

					while (!isNumber(cuentaAlumno) || isRepeat(list, cuentaAlumno))
					{
						cout << endl << "Ingrese un Número de Cuenta Válido." << endl;
						cout << "Ingrese el Número de Cuenta del Alumno: ";
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
							cout << endl << "Ingrese un Número de Cuenta Válido." << endl;
							cout << "Ingrese el Número de Cuenta del Alumno: ";
							cin >> strCuenta;
						}

						int posicionBuscar = list->localiza(new Alumno("", strCuenta));
						if (posicionBuscar > 0 && posicionBuscar <= list->getSize())
						{
							cout << "Alumno encontrado" << endl;
							cout << list->recupera(posicionBuscar)->toString() << " Está en la Posición " << posicionBuscar << "." << endl;
						}
					}
				}//Buscar Elemento
					  break;
				case 4: {
					int posAEliminar = 0;
					cout << "Ingrese la posicion que desea eliminar: " << endl;
					cin >> posAEliminar;

					if (posAEliminar > 0 && posAEliminar <= list->getSize())
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


					if (posicionElemento > 0 && posicionElemento <= list->getSize())
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


					if (posicionElemento > 0 && posicionElemento + 1 <= list->getSize())
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


					if (posicionElemento - 1 > 0 && posicionElemento <= list->getSize())
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
			if (list)
				delete list;
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
			if (stack)
				delete stack;
		}


	} while (opcion != 3);
}


//queuesMenu() -> metodo void que corre las operaciones del menu de colas
void queuesMenu() {
	int opcionMenu = 0;
	TDACola* queue = NULL;

	do {
		string eleccion = "\nMENÚ TIPO DE COLA\n 1. Trabajar con ArrayQueue\n 2. Trabajar con LinkedQueue\n 3. Trabajar con CircularQueue\n 4. Volver a menú principal\nIngrese opción: ";
		while (cout << eleccion && (!(cin >> opcionMenu) || (opcionMenu < 1 || opcionMenu > 4))) {
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

		case 3: {
			queue = new CircularQueue();
		}
			  break;
		}

		int opcion = -1;
		int num;
		if (opcionMenu != 4) {
			do {
				string menuCola = " >> OPERACIONES DE COLAS <<\n";
				menuCola += "1. Encolar (Queue)\n";
				menuCola += "2. Desencolar (Dequeue)\n";
				menuCola += "3. Ver Frente (Peek)\n";
				menuCola += "4. Vacia\n";
				menuCola += "6. Borrar los Elementos\n";
				menuCola += "7. Regresar al Menu Anterior\n";
				menuCola += "Ingrese una opcion: ";

				while (cout << menuCola && (!(cin >> opcion) || opcion < 1 || opcion > 7)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << endl
						<< "ERROR - 404"
						<< "Ingrese un Valor de Menu Válido..." << endl;

				}

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
							<< "Ingrese un Número de Cuenta Válido..." << endl
							<< endl;

						cout << "Ingrese el Número de Cuenta del Alumno: ";
						cin >> Cuenta;
					}

					queue->queue(new Alumno(Nombre, Cuenta));
					cout << "Alumno encolado correctamente" << endl;
				}
					  break;

				case 2: { //Desencolar (Dequeue)
					if (queue->isEmpty()) {
						cout << "La Cola está vacia" << endl
							<< "No Hay Nada Que Sacar..." << endl;
					}
					else {
						cout << "El Alumno sacado de la cola es : " << queue->dequeue()->toString() << endl;
					}
				}
					  break;


				case 3: { //Ver Frente (Peek)
					if (queue->isEmpty()) {
						cout << "La Cola Está Vacía" << endl;
					}
					else {
						cout << "El elemento al frente de la cola es: " << queue->peek()->toString() << endl;
					}
				}
					  break;

				case 4: { //Vacia
					if (queue->isEmpty()) {
						cout << "La Cola Está Vacía" << endl;
					}
					else {
						cout << "La Cola Tiene Elementos en Ella" << endl;
					}
				}
					  break;

				case 5: { //Imprimir Elementos
					if (queue->isEmpty()) {
						cout << "La Cola Está Vacía" << endl;
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
						cout << "La Cola Está Vacía" << endl;
					}
					else {
						queue->clear();
						cout << "Elementos han Sido Eliminados EXITOSAMENTE" << endl;
					}
				}
					  break;

				case 7: { //Regresar al Menu Anterior
					cout << "Regresando al Menú Anterior" << endl;
				}
					  break;


				}

			} while (opcion != 7);
			if (queue)
				delete queue;
		}
	} while (opcionMenu != 4);
}


int main() {
	setlocale(LC_ALL, "spanish");
	//validacion de entrada
	int opcion;
	cout << "\033[32m"; // Cambio Color a Verde
	cout << "Dariel Sevilla - 12241006 \n"
		<< "Josué Ham - 12141190 \n"
		<< "Víctor Romero - 12211079\n\n";
	cout << "\033[0m"; // Cambio de Color a Blanco

	do {
		cout << "\033[33m"; // Cambio Color a Anaranjado
		cout << "========== MENU PRINCIPAL ==========\n";
		cout << "\033[0m";

		string mensajeMenu = "  1) Trabajar con Listas\n  2) Trabajar con Pilas\n  3) Trabajar con Colas\n  4) Salir\n\033[33m- Ingrese Opción del Menú: \033[0m";
		while (cout << mensajeMenu && (!(cin >> opcion) || opcion < 1 || opcion > 4)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\033[31m"; // Cambio Color a Anaranjado
			cout << "ERROR 404 - Something went wrong...\n"
				<<"OPCIÓN INVÁLIDA!!!\n";
			cout << "Ingrese una Nueva Opción Válida\n\n";
			cout << "\033[0m"; // Cambio de Color a Blanco
			
			cout << "\033[33m"; // Cambio Color a Anaranjado
			cout << "========== MENU PRINCIPAL ==========\n";
			cout << "\033[0m";

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

