#include "ArrayList.h"
ArrayList::ArrayList() {
	capacidad = 1000;
	array = new Object*[1000];
}

ArrayList::~ArrayList() {
	for (int i = 0; i < size; i++) delete array[i];
	delete[] array;
}
bool ArrayList::inserta(Object* obj, int pos) {
	if (pos == size + 1 && pos > capacidad) resize();
	if (pos > 0 && pos <= size + 1 && pos <= capacidad) {
		for (int i = size-1; i >= pos-1; i--)
			if (i != capacidad - 1) array[i + 1] = array[i];
		array[pos - 1] = obj;
		size++;
		return true;
	}
	else
		return false;


}
 
Object* ArrayList::recupera(int pos) {
	if (pos > 0 && pos <= size)
		return array[pos - 1];
	else
		return NULL;
}

void ArrayList::suprimeTodos(Object* obj) {
	int newPos = 0;
	int tamanio = size;
	for (int i = 0; i < tamanio; i++) {
		
		if (!obj->equals(array[i])) {
			Object* pointer = array[i];
			array[i] = NULL;
			array[newPos] = pointer;
			newPos++;
		}	
		else {
			delete array[i]; 
			size--;
		}
		
	

	}
}

bool ArrayList::suprime(int pos) {
	if (!isEmpty()) {
		
		if (pos > 0 && pos <= size) {
			int movement = 0;
			for (int i = 0; i < size; i++) {
				if (pos - 1 == i) {
					delete array[i];
					movement++;
					
				}
				else {
					Object* temporal = array[i];
					array[i] = NULL;
					array[i - movement] = temporal;
				}
			}
			size--;
			return true;
			
		}
		return false;
	}
	return false;
}

void ArrayList::imprime() {
	for (int i = 0; i < size; i++) cout << "[" << array[i]->toString() << "]\n";
	cout << "\n";
}


void ArrayList::append(Object* obj) {
	inserta(obj, size + 1);
}

int ArrayList::localiza(Object* obj) {
	for (int i = 0; i < size; i++) if (array[i]->equals(obj)) return i+1;
	return -1;

}

Lista* ArrayList::localizaTodos(Object* obj) {
	ArrayList* nuevaLista = new ArrayList();
	for (int i = 0; i < size; i++) if (array[i]->equals(obj)) nuevaLista->append(new Integer(i+1));
	return nuevaLista;
}

Object* ArrayList::siguiente(int par) {
	if (par > 0 && par <= size) return array[par];
	return NULL;
}

Object* ArrayList::anterior(int par) {
	if (par > 0 && par - 2 <= size-1 && par - 2 >= 0) return array[par - 2];
	return NULL;
}

void ArrayList::anula() {
	for (int i = 0; i < size; i++) delete array[i];
	size = 0;
}

Object* ArrayList::primero() {
	if (!isEmpty()) return array[0];
}

void ArrayList::resize() {
	capacidad += 100;
	Object** array2 = new Object*[capacidad];
	for (int i = 0; i < size; i++) array2[i] = array[i];
	delete array;
	array = array2;
}