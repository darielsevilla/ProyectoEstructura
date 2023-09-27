#include "CircularQueue.h"
CircularQueue::CircularQueue() {
	capacidad = 100;
	array = new Object * [capacidad];
	primero = -1;
	ultimo = -1;
	size = 0;
}

void CircularQueue::queue(Object* obj) {
	if (size + 1 > capacidad) resize();
	if (ultimo + 1 == capacidad) ultimo = 0;
	array[ultimo + 1] = obj;
	if (!size) primero = size;
	ultimo++;
	size++;
}

Object* CircularQueue::dequeue() {
	if (primero != -1) {
		Object* retorno = array[primero];
		array[primero] = NULL;
		if (primero == ultimo) {
			primero = -1;
			ultimo = -1;
		}
		else {
			primero++;
		}

		if (primero >= capacidad) primero = 0;

		size--;
		return retorno;
	}
	return NULL;
	
}

void CircularQueue::print() {
	for (int i = primero; ; i++) {
		if (i == -1) break;
		if (i >= capacidad) i = 0;
		cout << "[" << array[i]->toString() << "]\n";
		if (i == ultimo) break;
	}
}

void CircularQueue::clear() {
	for (int i = primero; ; i++) {
		if (i == -1) break;
		if (i >= capacidad) i = 0;
		delete array[i];
		array[i] = NULL;
		if (i == ultimo) break;
		
	}
	primero = -1;
	ultimo = -1;
	size = 0;
}

Object* CircularQueue::peek() {
	if (primero != -1) return array[primero];
	return NULL;
}

CircularQueue::~CircularQueue() {
	for (int i = primero; ; i++) {
		if (i == -1) break;
		if (i >= capacidad) i = 0;
		delete array[i];
		if (i == ultimo) break;
	}
	delete[] array;
}

void CircularQueue::resize() {
	capacidad += 100;
	Object** newArray = new Object * [capacidad];
	for (int i = primero; ; i++) {
		if (i == -1) break;
		if (i >= capacidad) i = 0;
		newArray[i] == array[i];
		if (i == ultimo) break;
	}
	delete[] array;
	array = newArray;
}