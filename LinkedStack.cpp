#include "LinkedStack.h"
LinkedStack::LinkedStack() {
	topNode = NULL;
}

void LinkedStack::push(Object* obj) {
	Node* nodo = new Node(obj);
	if (!topNode)
		topNode = nodo;
	else {
		topNode->setPrior(nodo);
		nodo->setNext(topNode);
		topNode = topNode->getPrior();
	}
	size++;
}

Object* LinkedStack::pop() {
	if (size) {
		Node* retorno = topNode;
		Object* ptr = topNode->getObj()->copy();
		
		topNode = topNode->getNext();
		topNode->setPrior(NULL);
		retorno->setNext(NULL);
		delete retorno;
		size--;
		return ptr;
		
	}
	else {
		return NULL;
	}
}

Object* LinkedStack::top() {
	if (size)
		return topNode->getObj();
	return NULL;
}

bool LinkedStack::isEmpty() {
	if (size)
		return false;
	return true;
}

void LinkedStack::clear() {
	delete topNode;
	topNode = NULL;
	size = 0;
}

void LinkedStack::print() {
	Node* temp = NULL;
	for (int i = 0; i < size; i++) {
		if (!i) temp = topNode;
		else temp = temp->getNext();
		cout << "[" << temp->getObj()->toString() << "]";
	}
	cout << "\n";
}

LinkedStack::~LinkedStack() {
	if (topNode) delete topNode;
}