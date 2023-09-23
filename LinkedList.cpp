#include "LinkedList.h"
LinkedList::LinkedList() {
	size = 0;
}

LinkedList::~LinkedList() {
	if (nodo) delete nodo;
}

bool LinkedList::inserta(Object* obj, int pos) {
	int actualPos = pos - 1;
	if (pos >= 0 && pos <= size+1) {
		if (isEmpty()) {
			nodo = new Node(obj);
			
		}
		else {
			Node* insert = new Node(obj);
			Node* actual = nodo;
			for (int i = 0; i < actualPos-1; i++)
				actual = actual->getNext();
			insert->setPrior(actual);
			if (actual->getNext()) {
				insert->setNext(actual->getNext());
				insert->getNext()->setPrior(insert);
			}
			actual->setNext(insert);
		}
		
		
		size++;
		return true;
	}

	return false;

}

void LinkedList::append(Object* obj) {
	inserta(obj, size+1);
}

Object* LinkedList::recupera(int pos) {
	
	if (pos > 0 && pos <= size) {
		Node* node = NULL;
		for (int i = 0; i < pos; i++)
			if (!i) node = nodo;
			else node = node->getNext();
		return node->getObj();
	}
	return NULL;
}

Object* LinkedList::siguiente(int pos) {
	if (pos > 0 || pos < size - 1) return recupera(pos+1);
	return NULL;
}

Object* LinkedList::anterior(int pos) {
	int actualPos = pos - 1;
	if(pos > 1 || pos <= size){
		if (actualPos >= 0 && actualPos < size) return recupera(actualPos);
	}

	return NULL;
}

void LinkedList::anula() {
	delete nodo;
	size = 0;
}

void LinkedList::imprime() {
	if (!isEmpty()) {
		Node* node = nodo;
		cout << "[" << nodo->getObj()->toString() << "]";
		while (node = node->getNext()) cout << "[" << node->getObj()->toString() << "]";
		
		cout << "\n";
	}
}


bool LinkedList::suprime(int pos) {
	int actualPos = pos - 1;
	if (actualPos >= 0 && actualPos < size) {
		Node* temp = NULL;
		if (!actualPos) {
			temp = nodo;
			nodo = nodo->getNext();
		}
		else if (actualPos == size - 1) {
			for (int i = 0; i < size; i++)
				if (!i) temp = nodo;
				else temp = temp->getNext();
			temp->getPrior()->setNext(NULL);
		}
		else {
			for (int i = 0; i < pos; i++) 
				if (!i) temp = nodo;
				else temp = temp->getNext();
			temp->getPrior()->setNext(temp->getNext());
			temp->getNext()->setPrior(temp->getPrior());
			
		}
		temp->setNext(NULL);
		delete temp;
		size--;
		return true;
	}
	return false;
}

void LinkedList::suprimeTodos(Object* obj) {
	Node* temp = nodo;
	while (temp) {
		Node* borrado = NULL;
		if (temp->getObj()->equals(obj)) 
			borrado = temp;
		temp = temp->getNext();
		if (borrado) {
			if (borrado->getNext() && borrado->getPrior()) {
				borrado->getNext()->setPrior(borrado->getPrior());
				borrado->getPrior()->setNext(borrado->getNext());
			}
			else if (borrado == nodo) {
				if (borrado->getNext())
					nodo = borrado->getNext();
			}
			else {
				borrado->getPrior()->setNext(NULL);
			}
				
			borrado->setNext(NULL);
			delete borrado;
			size--;
		}
		
	}

}

Object* LinkedList::primero() {
	if (nodo) return nodo->getObj();
	return NULL;
}

int LinkedList::localiza(Object* ptr) {
	Node* temp = NULL;
	for (int i = 0; i < size; i++) {
		if (!i) temp = nodo;
		else temp = temp->getNext();
		if (temp->getObj()->equals(ptr)) return i + 1;
	}
	return -1;
}

Lista* LinkedList::localizaTodos(Object* ptr) {
	LinkedList* answer = new LinkedList();
	Node* temp = NULL;
	for (int i = 0; i < size; i++) {
		if (!i) temp = nodo;
		else temp = temp->getNext();
		if (temp->getObj()->equals(ptr)) answer->append(new Integer((i+1)));
	}
	return answer;
}