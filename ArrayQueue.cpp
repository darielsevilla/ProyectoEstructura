#include "ArrayQueue.h"

ArrayQueue::ArrayQueue() {
	size = 0;
	capacidad = 100;
	array = new Object * [capacidad];
}


void ArrayQueue::queue(Object* obj) {
	if (size + 1 == capacidad) resize();
	array[size] = obj;
	size++;
}



Object* ArrayQueue::dequeue() {
	if (size) {
		Object* out = array[0];
		array[0] = NULL;
		for (int i = 1; i < size; i++)array[i - 1] = array[i];
		array[size - 1] = NULL;
		size--;
		return out;
	}
	else {
		return NULL;
	}
}

void ArrayQueue::resize() {
	capacidad += 100;
	Object** newArray = new Object * [capacidad];
	for (int i = 0; i < size; i++) {
		newArray[i] = array[i];
	}
	delete[] array;
	array = newArray;
}


Object* ArrayQueue::peek() {
	if (size) return array[0];
	return NULL;
}

void ArrayQueue::print() {
	for (int i = 0; i < size; i++) cout << "[" << array[i]->toString() << "]\n";
	cout << "\n";
}

void ArrayQueue::clear() {
	for (int i = 0; i < size; i++) delete array[i];
	delete[] array;
	size = 0;
}

ArrayQueue::~ArrayQueue() {
	for (int i = 0; i < size; i++) delete array[i];
	delete[] array;
	size = 0;
}