#include "LinkedQueue.h"
LinkedQueue::LinkedQueue() {

}

LinkedQueue::~LinkedQueue() {
	if (last) delete last;
}

void LinkedQueue::queue(Object* obj) {
	if (!first) {
		first = new Node(obj);
		last = first;
	}
	else {
		Node* newLast = new Node(obj);
		last->setPrior(newLast);
		newLast->setNext(last);
		last = newLast;
	}
	size++;
}

Object* LinkedQueue::dequeue() {
	if (first) {
		Object* returnObj = first->getObj()->copy();
		
		Node* oldFirst = first;
		if (first->getPrior()) first = first->getPrior();
		delete oldFirst;
		
		first->setNext(NULL);
		
		size--;
		return returnObj;
	}
	return NULL;
}

Object* LinkedQueue::peek() {
	if (first) {
		Object* returnObj = first->getObj();
		return returnObj;
	}
	return NULL;
}

void LinkedQueue::clear() {
	if (last) delete last;
	last = NULL;
	first = NULL;
	size = 0;
}

void LinkedQueue::print() {
	Node* tempNode = NULL;
	if (size) {
		for (int i = 0; i < size; i++) {
			if (!i) tempNode = first;
			else tempNode = tempNode->getPrior();
			cout << "[" << tempNode->getObj()->toString() << "]";
		}
		cout << "\n";
	}
}