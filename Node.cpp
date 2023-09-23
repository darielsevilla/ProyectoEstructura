#include "Node.h"
Node::Node() {

}

Node::Node(Object* par) {
	this->nodeObj = par;
}

Node::~Node() {
	if (nodeObj) delete nodeObj;
	if (siguiente) delete siguiente;
	anterior = NULL;
}

void Node::setNext(Node* nodo) {
	this->siguiente = nodo;
}

void Node::setPrior(Node* nodo) {
	this->anterior = nodo;
}

Object* Node::getObj() {
	if(nodeObj) return nodeObj;
	return NULL;
}

void Node::setObj(Object* newObj) {
	if (nodeObj) delete nodeObj;
	nodeObj = newObj;
}

Node* Node::getPrior() {
	if(anterior) return anterior;
	return NULL;
}

Node* Node::getNext() {
	if(siguiente) return siguiente;
	return NULL;
}