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

//validacionYesNo(string) -> valida que la string enviada sea 'y', 'Y','n', 'N'. en caso de que sea cualquiera de esos, retorna true. De otra forma retorna false.
bool validacionYesNo(string parametro) {
	if (parametro.size() != 1 || (parametro.at(0) != 'n' && parametro.at(0) != 'N' && parametro.at(0) != 'y' && parametro.at(0) != 'Y')) return false;
	return true;
}

//castNumber(string, int&, int, int) -> recibe una string, verifica que es un numero y lo almacena en la direccion en memoria de la variable enviada. en caso de que no lo sea, o que este fuera del rango establecido, retornada falso. de otro modo retorna verdadero
bool castNumber(string recibido, int& var, int lowest, int highest) {
	for (char c : recibido) {
		if (!isdigit(c)) {
			return false;
		}
	}

	var = stoi(recibido);
	if (var < lowest || var > highest) return false;
	return true;
}

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
	string buffer;
	int posicion = 0;
	int opcion = 0;
	Lista* list = NULL;
	while (opcion != 3) {
		string eleccion = "\n\n\033[33m>>>> MENÚ TIPOS DE LISTAS <<<<\033[0m\n 1) Trabajar con ArrayList\n 2) Trabajar con LinkedList\n 3) Volver a menú principal\n\033[33m- Ingrese Opción del Menú: \033[0m";
		while (cout << eleccion && (cin >> buffer) && !castNumber(buffer, opcion, 1, 3)) {
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

			string sub = "\n\n\033[33m--> OPERACIONES EN LISTAS <--\033[0m\n";
			sub += "  1) Insertar Elemento\n";
			sub += "  2) Imprimir Elementos\n";
			sub += "  3) Buscar Elemento\n";
			sub += "  4) Borrar Elemento\n";
			sub += "  5) Ver si está vacía\n";
			sub += "  6) Obtener Elemento por Posición\n";
			sub += "  7) Obtener Siguiente\n";
			sub += "  8) Obtener Anterior\n";
			sub += "  9) Borrar todos los Elementos (Anula)\n";
			sub += "  10) Regresar al Menú Anterior\n";
			sub += "\033[33m- Ingrese Opción del Menú: \033[0m";

			do {
				while (cout << sub && (cin >> buffer) && !castNumber(buffer, menu, 1, 10)) {
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
					cout << "\n\033[36m";
					cout << "> OPCIÓN 1 - LISTS <";
					cout << "\033[0m";
					string nombreAlumno;
					string cuentaAlumno;

					bool repeat = true;
					do {
						cin.clear();
						cin.ignore();
						cout << "\n\033[33m> Ingrese el nombre del alumno: \033[0m";
						getline(cin, nombreAlumno);
						cout << "\033[33m> Ingrese el numero de cuenta del alumno: \033[0m";
						cin >> cuentaAlumno;

						while (!isNumber(cuentaAlumno) || isRepeat(list, cuentaAlumno)) {
							cout << "\033[31m"; // Cambio Color a Anaranjado
							cout << "ERROR 404 - Something went wrong...\n"
								<< "OPCIÓN INVÁLIDA!!!\n";
							cout << "Ingrese un Número de Cuenta Válida\n\n";
							cout << "\033[0m"; // Cambio de Color a Blanco

							cout << "\033[33m> Ingrese el numero de cuenta del alumno: \033[0m";
							cin >> cuentaAlumno;
						}

						estudiante = new Alumno(nombreAlumno, cuentaAlumno);

						while (cout << "\033[33m> Ingrese posicion de alumno: \033[0m" && cin >> buffer && !castNumber(buffer, posicion, 1, list->getSize() + 1)) {
							cout << "\033[31m"; // Cambio Color a Anaranjado
							cout << "ERROR 404 - Something went wrong...\n"
								<< "OPCIÓN INVÁLIDA!!!\n";
							cout << "Ingrese una Posición Válida\n\n";
							cout << "\033[0m"; // Cambio de Color a Blanco
						}

						list->inserta(estudiante, posicion);
						cout << "\033[32mAlumno Insertado correctamente!\033[0m" << endl;

						while (cout << "\n\033[33m>Desea ingresar de nuevo? [y/n] \033[0m: " && cin >> buffer && !validacionYesNo(buffer)) {
							cout << "\033[31m"; // Cambio Color a Anaranjado
							cout << "ERROR 404 - Something went wrong...\n"
								<< "OPCIÓN INVÁLIDA!!!\n";
							cout << "Ingrese un 'y' o 'n'\n";
							cout << "\033[0m"; // Cambio de Color a Blanco
						}
						if (buffer.at(0) == 'n' || buffer.at(0) == 'N') repeat = false;

					} while (repeat);
				}//Inserta
					  break;
				case 2: {
					cout << "\n\033[36m";
					cout << "> OPCIÓN 2 - LISTS <";
					cout << "\033[0m";

					cout << "\n\033[32m>>>>>>>>>>>>> Lista <<<<<<<<<<<<<\n\033[0m";
					list->imprime();
					cout << endl;
				}//Imprimir Elementos
					  break;

				case 3: {
					cout << "\n\033[36m";
					cout << "> OPCIÓN 3 - LISTS <";
					cout << "\033[0m";

					if (list->isEmpty()) {
						cout << "\033[31m"; // Cambio Color a Rojo
						cout << "ERROR 404 - Something went wrong...\n"
							<< "OPCIÓN INVÁLIDA!!!\n";
						cout << "No se pueden buscar alumnos debido a que la lista se encuentra vacia\n\n";
						cout << "\033[0m"; // Cambio de Color a Blanco
					}
					else {
						printf("\n");
						cout << "\033[33m> Ingrese el numero de cuenta que desea buscar: \033[0m" << endl;
						string strCuenta;
						cin >> strCuenta;

						while (!isNumber(strCuenta)) {
							cout << "\033[31m"; // Cambio Color a Rojo
							cout << "ERROR 404 - Something went wrong...\n"
								<< "OPCIÓN INVÁLIDA!!!\n";
							cout << "Ingrese un Número de Cuenta Válido.\n\n";
							cout << "\033[0m"; // Cambio de Color a Blanco

							printf("\n");
							cout << "\033[33m> Ingrese el numero de cuenta que desea buscar: \033[0m" << endl;
							string strCuenta;
						}

						int posicionBuscar = list->localiza(new Alumno("", strCuenta));
						if (posicionBuscar > 0 && posicionBuscar <= list->getSize()) {

							cout << "\n\033[32mAlumno encontrado!\033[0m" << endl;
							cout << list->recupera(posicionBuscar)->toString() << ", Posición -> " << posicionBuscar << "." << endl;
						}
					}
				}//Buscar Elemento
					  break;

				case 4: {
					cout << "\n\033[36m";
					cout << "> OPCIÓN 4 - LISTS <";
					cout << "\033[0m";

					int posAEliminar = 0;
					cout << "\n\033[33m> Ingrese la posicion que desea eliminar: \033[0m" << endl;
					cin >> posAEliminar;

					if (posAEliminar > 0 && posAEliminar <= list->getSize())
					{
						list->suprime(posAEliminar);
						cout << "\033[32mAlumno eliminado correctamente!\033[0m\n\n" << endl;
					}
					else {
						cout << "\033[31m"; // Cambio Color a Rojo
						cout << "ERROR 404 - Something went wrong...\n"
							<< "OPCIÓN INVÁLIDA!!!\n";
						cout << "Posicion fuera del rango\n\n";
						cout << "\033[0m"; // Cambio de Color a Blanco
					}
				}//Borrar Elemento
					  break;

				case 5: {
					cout << "\n\033[36m";
					cout << "> OPCIÓN 5 - LISTS <";
					cout << "\033[0m";

					printf("\n");
					if (list->isEmpty()) cout << "\033[31mLa lista se encuentra vacia actualmente\033[0m" << endl;
					else printf("La lista contiene %d elementos\n", list->getSize());

				}//Ver si la lista esta vacia
					  break;

				case 6: {
					cout << "\n\033[36m";
					cout << "> OPCIÓN 6 - LISTS <";
					cout << "\033[0m";

					cout << "\n\033[33mIngrese la posicion en la que desea conseguir el elemento: \033[0m" << endl;
					int posicionElemento;
					cin >> posicionElemento;

					if (posicionElemento > 0 && posicionElemento <= list->getSize())
					{
						estudiante = new Alumno();
						estudiante = list->recupera(posicionElemento);

						cout << "\033[32mPosición Encontrada Correctamente!\033[0m\n" << endl;
						cout << estudiante->toString();
					}
					else {
						cout << "\033[31m"; // Cambio Color a Rojo
						cout << "ERROR 404 - Something went wrong...\n"
							<< "OPCIÓN INVÁLIDA!!!\n";
						cout << "Posicion fuera del rango" << endl;
						cout << "\033[0m"; // Cambio de Color a Blanco
					}
				}//Obtener elementos por posicion
					  break;

				case 7: {
					cout << "\n\033[36m";
					cout << "> OPCIÓN 7 - LISTS <";
					cout << "\033[0m";

					cout << "\n\033[33mIngrese la posicion en la que desea conseguir el elemento siguiente: \033[0m" << endl;
					int posicionElemento;
					cin >> posicionElemento;

					if (posicionElemento > 0 && posicionElemento + 1 <= list->getSize())
					{
						estudiante = new Alumno();
						estudiante = list->siguiente(posicionElemento);

						cout << "\033[32mPosición Encontrada Correctamente!\033[0m\n" << endl;
						cout << estudiante->toString();
					}
					else {
						cout << "\033[31m"; // Cambio Color a Rojo
						cout << "ERROR 404 - Something went wrong...\n"
							<< "OPCIÓN INVÁLIDA!!!\n";
						cout << "Posicion fuera del rango" << endl;
						cout << "\033[0m"; // Cambio de Color a Blanco
					}
				}//Obtener siguiente
					  break;

				case 8: {
					cout << "\n\033[36m";
					cout << "> OPCIÓN 8 - LISTS <";
					cout << "\033[0m";

					cout << "\n\033[33mIngrese la posicion en la que desea conseguir el elemento siguiente: \033[0m" << endl;
					int posicionElemento;
					cin >> posicionElemento;


					if (posicionElemento - 1 > 0 && posicionElemento <= list->getSize())
					{
						estudiante = new Alumno();
						estudiante = list->anterior(posicionElemento);

						cout << "\033[32mPosición Encontrada Correctamente!\033[0m\n" << endl;
						cout << estudiante->toString();
					}
					else {
						cout << "\033[31m"; // Cambio Color a Rojo
						cout << "ERROR 404 - Something went wrong...\n"
							<< "OPCIÓN INVÁLIDA!!!\n";
						cout << "Posicion fuera del rango" << endl;
						cout << "\033[0m"; // Cambio de Color a Blanco

					}
				}//Obtener anterior
					  break;

				case 9: {
					cout << "\n\033[36m";
					cout << "> OPCIÓN 9 - LISTS <";
					cout << "\033[0m";
					if (!list->isEmpty())
					{
						list->anula();
						cout << "\n\033[32mSe ha Eliminado la Lista Correctamente!\033[0m\n" << endl;
					}
					else {
						cout << "\n\033[31mLa lista ya se encuentra Vacia!\033[0m\n" << endl;
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
	string buffer;
	//eleccion de tipo de pila
	do {
		string eleccion = "\n\033[33m>>>> MENÚ TIPOS DE PILAS <<<<\033[0m\n  1) Trabajar con ArrayStack\n  2) Trabajar con LinkedStack\n  3) Volver a menú principal\n\033[33m- Ingrese Opción del Menú: \033[0m";

		while (cout << eleccion && (cin >> buffer) && !castNumber(buffer, opcion, 1, 3)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\033[31m"; // Cambio Color a Rojo
			cout << "ERROR 404 - Something went wrong...\n"
				<< "OPCIÓN INVÁLIDA!!!\n";
			cout << "Ingrese una Nueva Opción Válida\n";
			cout << "\033[0m"; // Cambio de Color a Blanco

			cin.clear();
		}

		//eleccion de stack
		if (opcion == 1)
			stack = new ArrayStack();
		else if (opcion == 2)
			stack = new LinkedStack();

		//sub menu de opciones
		if (opcion != 3) {
			int menu;
			string sub = "\n\n\033[33m--> OPERACIONES EN PILAS <--\033[0m\n";
			sub += "  1) \"Empujar\"(push)\n";
			sub += "  2) \"Sacar\"(pop)\n";
			sub += "  3) Ver Tope (top)\n";
			sub += "  4) Verificar si está vacía\n";
			sub += "  5) Imprimir elementos\n";
			sub += "  6) Borrar todos los elementos\n";
			sub += "  7) Regresar al Menú anterior\n";
			sub += "\033[33mIngrese opción: \033[0m";

			//validacion subMenu
			do {
				while (cout << sub && (cin >> buffer) && !castNumber(buffer, menu, 1, 7)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\033[31m"; // Cambio Color a Rojo
					cout << "ERROR 404 - Something went wrong...\n"
						<< "OPCIÓN INVÁLIDA!!!\n";
					cout << "Ingrese una Nueva Opción Válida\n";
					cout << "\033[0m"; // Cambio de Color a Blanco;
				}

				//variables necesarias
				char simbolo;
				Object* currentSymbol = NULL;
				string validacionDeSimbolo;
				//operaciones de pilas

				switch (menu) {
				case 1:
					cout << "\n\033[36m";
					cout << "> OPCIÓN 1 - STACKS <";
					cout << "\033[0m";

					//ingresamiento de un caracter o simbolo (validado de que solo sea 1)
					while (cout << "\n\033[33m>Ingrese un simbolo para agregar a la pila: \033[0m" && cin >> validacionDeSimbolo && validacionDeSimbolo.size() > 1) {
						cout << "\033[31m"; // Cambio Color a Anaranjado
						cout << "ERROR 404 - Something went wrong...\n"
							<< "OPCIÓN INVÁLIDA!!!\n";
						cout << "\n*Ingrese solo 1 caracter*\n";
						cout << "\033[0m"; // Cambio de Color a Blanco

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					currentSymbol = new Simbolo(validacionDeSimbolo.at(0));
					stack->push(currentSymbol);
					cout << "\033[32mSimbolo Insertado correctamente!\033[0m" << endl;
					break;

				case 2:
					cout << "\n\033[36m";
					cout << "> OPCIÓN 2 - STACKS <";
					cout << "\033[0m";

					//saca al ultimo elemento ingresado a la pila (validado para que imprima un mensaje diferente si la pila esta vacia)
					if (!stack->isEmpty()) {
						currentSymbol = stack->pop();
						cout << "\n\033[33mEl siguiente símbolo salio de la pila : \033[0m" << dynamic_cast<Simbolo*>(currentSymbol)->getCaracter() << "\n";
						delete currentSymbol;
					}
					else {
						cout << "\n\033[31m"; // Cambio Color a Anaranjado
						cout << "ERROR 404 - Something went wrong...\n"
							<< "OPCIÓN INVÁLIDA!!!\n";
						cout << "\nNo hay nada que sacar de la Pila\n";
						cout << "\033[0m"; // Cambio de Color a Blanco
					}
					break;

				case 3:
					cout << "\n\033[36m";
					cout << "> OPCIÓN 3 - STACKS <";
					cout << "\033[0m";

					//si existe, revisa el siguiente elemento a salir de la stack, sin sacarlo
					if (!stack->isEmpty()) {
						currentSymbol = stack->top();
						cout << "\n\033[33mEl siguiente símbolo esta a la cima de la pila : \033[0m" << dynamic_cast<Simbolo*>(currentSymbol)->getCaracter() << "\n";
					}
					else {
						cout << "\n\033[31m"; // Cambio Color a Anaranjado
						cout << "ERROR 404 - Something went wrong...\n"
							<< "OPCIÓN INVÁLIDA!!!\n";
						cout << "\nNo hay nada en la Pila\n";
						cout << "\033[0m"; // Cambio de Color a Blanco
					}
					break;

				case 4:
					cout << "\n\033[36m";
					cout << "> OPCIÓN 4 - STACKS <";
					cout << "\033[0m";

					//verificaciond e si esta vacia o no
					if (stack->isEmpty()) cout << "\033[32m\nLa Pila Está vacia\033[0m\n";
					else cout << "\n\033[31mLa Pila No esta Vacia\033[0m\n";
					break;

				case 5:
					cout << "\n\033[36m";
					cout << "> OPCIÓN 5 - STACKS <";
					cout << "\033[0m";

					//impresion de los elementos de la stack
					if (!stack->isEmpty()) {
						cout << "\n\033[32m>>>>>>>>>>>>> Pila <<<<<<<<<<<<<\n\033[0m";
						stack->print();
					}
					else {
						cout << "\n\033[31m"; // Cambio Color a Anaranjado
						cout << "ERROR 404 - Something went wrong...\n"
							<< "OPCIÓN INVÁLIDA!!!\n";
						cout << "\nNo hay elementos para imprimir\n";
						cout << "\033[0m"; // Cambio de Color a Blanco
					}
					break;

				case 6:
					cout << "\n\033[36m";
					cout << "> OPCIÓN 6 - STACKS <";
					cout << "\033[0m";

					//vaciar la stack
					stack->clear();
					cout << "\n\033[32mLos elementos de la lista han sido borrados correctamente!\033[0m" << endl;
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
		string eleccion = "\n\033[33m>>>> MENÚ TIPOS DE COLAS <<<<\033[0m\n  1) Trabajar con ArrayQueue\n  2) Trabajar con LinkedQueue\n  3) Trabajar con CircularQueue\n  4) Volver a menú principal\n\033[33m- Ingrese Opción del Menú: \033[0m";
		while (cout << eleccion && (!(cin >> opcionMenu) || (opcionMenu < 1 || opcionMenu > 4))) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\033[31m"; // Cambio Color a Rojo
			cout << "ERROR 404 - Something went wrong...\n"
				<< "OPCIÓN INVÁLIDA!!!\n";
			cout << "Ingrese una Nueva Opción Válida\n";
			cout << "\033[0m"; // Cambio de Color a Blanco

			cin.clear();
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
				string buffer;
				string menuCola = " \n\n\033[33m--> OPERACIONES EN COLAS <--\033[0m\n";
				menuCola += "  1) Encolar (Queue)\n";
				menuCola += "  2) Desencolar (Dequeue)\n";
				menuCola += "  3) Ver Frente (Peek)\n";
				menuCola += "  4) Vacia\n";
				menuCola += "  6) Borrar los Elementos\n";
				menuCola += "  7) Regresar al Menu Anterior\n";
				menuCola += "\033[33mIngrese opción: \033[0m";

				while (cout << menuCola && (cin >> buffer) && !castNumber(buffer, opcion, 1, 7)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n\033[31m"; // Cambio Color a Rojo
					cout << "ERROR 404 - Something went wrong...\n"
						<< "OPCIÓN INVÁLIDA!!!\n";
					cout << "Ingrese una Nueva Opción Válida\n";
					cout << "\033[0m"; // Cambio de Color a Blanco;
				}

				Object* student = new Alumno();
				string Nombre = "";
				string Cuenta;

				switch (opcion) {
				case 1: { //Encolar (Queue)
					cout << "\n\033[36m";
					cout << "> OPCIÓN 1 - QUEUES <";
					cout << "\033[0m";

					cin.ignore();
					cout << "\n\033[33m> Ingrese el nombre del alumno: \033[0m";
					cin >> Nombre;

					cout << "\033[33m> Ingrese el numero de cuenta del alumno: \033[0m";
					cin >> Cuenta;

					while (!isNumber(Cuenta)) {
						cout << "\n\033[31m"; // Cambio Color a Anaranjado
						cout << "ERROR 404 - Something went wrong...\n"
							<< "OPCIÓN INVÁLIDA!!!\n";
						cout << "Ingrese una Nueva Cuenta Válida\n\n";
						cout << "\033[0m"; // Cambio de Color a Blanco

						cout << "\033[33m> Ingrese el numero de cuenta del alumno: \033[0m";
						cin >> Cuenta;
					}

					queue->queue(new Alumno(Nombre, Cuenta));
					cout << "\033[32mAlumno encolado correctamente!\033[0m" << endl;
				}
					  break;

				case 2: { //Desencolar (Dequeue)
					cout << "\n\033[36m";
					cout << "> OPCIÓN 2 - QUEUES <";
					cout << "\033[0m";

					if (queue->isEmpty()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\033[31m"; // Cambio Color a Rojo
						cout << "ERROR 404 - Something went wrong...\n"
							<< "OPCIÓN INVÁLIDA!!!\n";
						cout << "La Cola está vacia" << endl
							<< "No Hay Nada Que Sacar..." << endl;
						cout << "\033[0m"; // Cambio de Color a Blanco;
					}
					else {
						cout << "\n\033[33mEl Alumno sacado de la cola es : \033[0m" << queue->dequeue()->toString() << endl;
					}
				}
					  break;


				case 3: { //Ver Frente (Peek)
					cout << "\n\033[36m";
					cout << "> OPCIÓN 3 - QUEUES <";
					cout << "\033[0m";

					if (queue->isEmpty()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\033[31m"; // Cambio Color a Rojo
						cout << "ERROR 404 - Something went wrong...\n"
							<< "OPCIÓN INVÁLIDA!!!\n";
						cout << "La Cola está vacia" << endl;
						cout << "\033[0m"; // Cambio de Color a Blanco;
					}
					else {
						cout << "\n\033[33mEl elemento al frente de la cola es: \033[0m" << queue->peek()->toString() << endl;
					}
				}
					  break;

				case 4: { //Vacia
					cout << "\n\033[36m";
					cout << "> OPCIÓN 4 - QUEUES <";
					cout << "\033[0m";

					if (queue->isEmpty()) {
						cout << "\n\033[32mLa Cola Está Vacía\033[0m" << endl;
					}
					else {
						cout << "\n\033[31mLa Cola Tiene Elementos en Ella\033[0m" << endl;
					}
				}
					  break;

				case 5: { //Imprimir Elementos
					cout << "\n\033[36m";
					cout << "> OPCIÓN 5 - QUEUES <";
					cout << "\033[0m";

					if (queue->isEmpty()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\033[31m"; // Cambio Color a Rojo
						cout << "ERROR 404 - Something went wrong...\n"
							<< "OPCIÓN INVÁLIDA!!!\n";
						cout << "La Cola está vacia" << endl;
						cout << "\033[0m"; // Cambio de Color a Blanco;
					}

					else {
						cout << endl
							<< "\n\033[32m>>>>>>>>>>>>> Cola <<<<<<<<<<<<<\n\033[0m";
						queue->print();
					}
					break;
				}
					  break;

				case 6: { //Borrar los Elementos
					cout << "\n\033[36m";
					cout << "> OPCIÓN 6 - QUEUES <";
					cout << "\033[0m";

					if (queue->isEmpty()) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\033[31m"; // Cambio Color a Rojo
						cout << "ERROR 404 - Something went wrong...\n"
							<< "OPCIÓN INVÁLIDA!!!\n";
						cout << "La Cola está vacia" << endl;
						cout << "\033[0m"; // Cambio de Color a Blanco;
					}
					else {
						queue->clear();
						cout << "\n\033[31mElementos han Sido Eliminados EXITOSAMENTE\033[0m" << endl;
					}
				}
					  break;

				case 7: { //Regresar al Menu Anterior
					cout << "\n\033[36m";
					cout << "> OPCIÓN 7 - QUEUES <";
					cout << "\033[0m";

					cout << "\nRegresando al Menú Anterior..." << endl;
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
		<< "Víctor Romero - 12211079\n";
	cout << "\033[0m"; // Cambio de Color a Blanco

	do {
		cout << "\033[33m"; // Cambio Color a Anaranjado
		cout << "\n---------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "========== MENU PRINCIPAL ==========\n";
		cout << "\033[0m";
		string buffer;
		string mensajeMenu = "  1) Trabajar con Listas\n  2) Trabajar con Pilas\n  3) Trabajar con Colas\n  4) Salir\n\033[33m- Ingrese Opción del Menú: \033[0m";
		while (cout << mensajeMenu && (cin >> buffer) && !castNumber(buffer, opcion, 1, 4)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\033[31m"; // Cambio Color a Anaranjado
			cout << "ERROR 404 - Something went wrong...\n"
				<< "OPCIÓN INVÁLIDA!!!\n";
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

