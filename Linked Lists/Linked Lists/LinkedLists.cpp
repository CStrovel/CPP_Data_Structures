#include "LinkedLists.h"
#include <stdexcept>
#include <iostream>

using namespace std;

/* default Node Class definitions */
Node::Node(int val, Node* next) {
	this->payload = val;
	this->next = next;
}

int Node::getPayload() {
	return this->payload;
}

Node* Node::getNext() {
	return this->next;
}

void Node::setNext(Node* next) {
	this->next = next; 
}

/* default LinkedList class definitions */
LinkedList::LinkedList() {
	this->head = nullptr;
}

LinkedList::LinkedList(int val) {
	this->head = new Node(val);
}

LinkedList::LinkedList(Node* node) {
	this->head = node;
}

Node* LinkedList::getHead() {
	return this->head;
}

void LinkedList::setHead(Node* node) {
	this->head = node;
}

string LinkedList::toString() {
	string rtn = "";
	Node* node = this->getHead();
	while (node != nullptr) {
		rtn += "[" + to_string(node->getPayload()) + "]";
		node = node->getNext();
		if (node != nullptr) {
			rtn += "->";
		}
	}
	return rtn; 
}

void LinkedList::insert(int val) {
	Node* node = new Node(val, this->getHead());
	this->setHead(node);
}

void LinkedList::push(int val) {
	Node* node = new Node(val);
	Node* last = this->getHead();
	
	// if the linked list has no nodes, push() must
	// place at head
	if(last == nullptr){
		this->setHead(node);
		return;
	}

	// if the linked list has nodes, place after last
	while (last->getNext() != nullptr) {
		last = last->getNext();
	}

	last->setNext(node);
	return;
}

bool LinkedList::remove(int val) {
	Node* current = this->getHead();

	if (current != nullptr) { // validate head exists
		// first node needs special attention
		if (current->getPayload() == val) {
			this->setHead(current->getNext());
			delete current;
			return true;
		}

		// search linked list for number to remove
		while (current->getNext() != nullptr) {
			if (current->getNext()->getPayload() == val) {
				Node* deleteMe = current->getNext();
				current->setNext(current->getNext()->getNext());
				delete deleteMe;
				return true;
			}
			current = current->getNext();
		}
	}
	return false; 
}

bool LinkedList::removeAll(int val) {
	Node* deleteMe;
	Node* current;
	bool headCleared = false;
	bool deleteOccured = false;

	while (this->getHead() != nullptr && headCleared == false) {
		if (this->getHead()->getPayload() == val) {
			deleteMe = this->getHead();
			this->setHead(this->getHead()->getNext());
			delete deleteMe; 
			deleteOccured = true;
		}
		else {
			headCleared = true; 
		}
	}

	current = this->getHead();
	while (current->getNext() != nullptr) {
		if (current->getNext()->getPayload() == val) {
			deleteMe = current->getNext();
			current->setNext(current->getNext()->getNext());
			delete deleteMe;
			deleteOccured = true;
		}
		else {
			current = current->getNext();
		}
	}
	
	return deleteOccured;
}

void LinkedList::removeAt(const int idx) {
	// variables 
	Node* deleteMe; // pointer for node to be deleted
	Node* current = this->getHead(); // iteration pointer

	// if 0 index, head needs to be removed
	if (idx == 0 && this->getHead() != nullptr) {
		deleteMe = this->getHead();
		this->setHead(this->getHead()->getNext());
		delete deleteMe;
		return;
	}
	else {
		// move the current pointer to the node to be removed
		for (int i = 1; i < idx && current != nullptr; i++) {
			current = current->getNext();
		}
	}

	// if we are at the end of chain or the index was negative
	// throw an error
	if (current == nullptr || idx < 0) {
		throw out_of_range("Linked list has no node at " + to_string(idx));
	}

	// remove the indexed node
	deleteMe = current->getNext();
	current->setNext(current->getNext()->getNext());
	delete deleteMe;
}

int LinkedList::length() {
	Node* current = this->getHead();
	int count = 0;
	while (current != nullptr) {
		count++;
		current = current->getNext();
	}
	return count;
}

int LinkedList::at(const int idx) {
	Node* current = this->getHead();
	for (int i = idx; i > 0 && current != nullptr; i--) {
		current = current->getNext();
	}
	if (current == nullptr || idx < 0) {
		throw out_of_range("Linked list has no node at " + to_string(idx));
	}

	return current->getPayload();
}

int LinkedList::fromEnd(const int rIdx) {
	int idx = this->length() - 1 - rIdx;
	if (idx < 0) {
		throw out_of_range("List not long enough for reverse index specified");
	}
	return this->at(idx);
}

LinkedList::~LinkedList() {
	Node* current = this->getHead();
	Node* deleteMe = this->getHead();

	while (current != nullptr) {
		current = current->getNext();
		delete deleteMe;
		deleteMe = current;
	}
}
