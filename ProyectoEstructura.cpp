#include <iostream>
#include <locale.h>
#include "Node.h"
#include "LinkedList.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "Simbolo.h"
#include "ArrayList.h"

void stackMenu() {
    int opcion = 0;
    TDAPila* stack = NULL;
    //eleccion de tipo de pila
    do {
        string eleccion = "\nMenu Tipo de Pila\n 1. Trabajar con ArrayStack\n 2. Trabajar con LinkedStack\n 3. Volver a menu principal\nIngrese opcion: ";
        while (cout << eleccion && (!(cin >> opcion) || (opcion < 1 || opcion > 3))) {
            cin.clear();
            cout << "\n*Ingrese opcion valida*\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        //eleccion de stack
        if (opcion == 1)
            stack = new LinkedStack();
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
            sub += "Ingrese opcion: ";
           
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
                    while (cout << "\nIngrese un simbolo para agregar a la pila: " && cin >> validacionDeSimbolo && validacionDeSimbolo.size() > 1) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\n*Ingrese solo 1 caracter*\n";
                    }
                    currentSymbol = new Simbolo(validacionDeSimbolo.at(0));
                    stack->push(currentSymbol);
                    break;
                case 2:
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
                    if (!stack->isEmpty()) {
                        currentSymbol = stack->top();
                        cout << "\nEl siguiente s�mbolo esta a la cima de la pila : " << dynamic_cast<Simbolo*>(currentSymbol)->getCaracter() << "\n";
                    }
                    else {
                        cout << "\nNo hay nada en la pila\n";
                    }
                    break;
                case 4:
                    if (stack->isEmpty()) cout << "\nEst� vacia\n";
                    else cout << "\nNo esta Vacia\n";
                    break;
                case 5:
                    if (!stack->isEmpty()) {
                        cout << "\nImpresi�n de elementos: \n";
                        stack->print();
                    }
                    else {
                        cout << "\nNo hay elementos para imprimir\n";
                    }
                    break;
                case 6:
                    stack->clear();
                    cout << "\nLos elementos de la lista han sido borrados\n";
                    break;
                }
            } while (menu != 7);
            if (stack) delete stack;
        }
        
        
    } while (opcion != 3);
}
int main()
{
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
