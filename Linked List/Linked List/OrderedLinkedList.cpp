#pragma once
#include <iostream>
#include "OrderedLinkedList.h"

OOLList::OOLList() {
	this->start = nullptr;
}

int OOLList::getListSize() {
	OOLNode* nodePointer = start;
	int listCount = 0;
	if (nodePointer != nullptr) {
		listCount++;
		while (nodePointer->next != nullptr) {
			nodePointer = nodePointer->next;
			listCount++;
		}
	}

	return listCount;
}

int OOLList::getListSizeInBytes() {
	int totalBytes = 0;
	OOLNode* nodePointer = this->start;

	// get the size of the base object
	totalBytes += sizeof(this);

	// add on the size of each OOLNode
	while (nodePointer != nullptr) {
		totalBytes += sizeof(*nodePointer);
		nodePointer = nodePointer->next;
	}

	return totalBytes;
}

int OOLList::getListElements(int* populateMeWithElements) {
	int counter = 0;
	OOLNode* nodePointer = this->start;
	while (nodePointer != nullptr) {
		std::cout << "test";
		populateMeWithElements[counter] = nodePointer->payload;
		counter++;
		nodePointer = nodePointer->next;
	}

	return counter;
}

int OOLList::addElement(int addMe) {
	// create a new node
	OOLNode* newNode = new OOLNode;
	newNode->next = nullptr;
	newNode->payload = addMe;

	// check for the list having a first element,
	// if not create it
	if (this->start == nullptr) {
		this->start = newNode;
	}
	// if there was a starting element, but the new element is
	// lower than it, we need to replace it
	else if (this->start->payload > newNode->payload) {
		newNode->next = this->start;
		this->start = newNode;
	}
	// if neither of the previous two apply, we just need to slip
	// the new element into the proper place in the ordered list
	else {
		OOLNode* nodePointer = this->start;
		while (nodePointer->next != nullptr && nodePointer->next->payload < newNode->payload) {
			nodePointer = nodePointer->next;
		}
		newNode->next = nodePointer->next;
		nodePointer->next = newNode;
	}
	return OK;
}

bool OOLList::deleteElement(int deleteMe) {
	OOLNode* previousNode = nullptr;
	OOLNode* nodePointer = this->start;
	bool foundTgt = false;

	// find the element in the ordered list
	while (nodePointer != nullptr) {
		if (nodePointer->payload == deleteMe) {
			foundTgt = true;
			break;
		}
		previousNode = nodePointer;
		nodePointer = nodePointer->next;
	}
	if (foundTgt && previousNode != nullptr) {
		previousNode->next = nodePointer->next;
		delete nodePointer;
	}
	else if (foundTgt) {
		start = nodePointer->next;
		delete nodePointer;
	}

	return foundTgt;
}

int OOLList::operator+(int addMe) {
	return this->addElement(addMe);
}

bool OOLList::operator-(int deleteMe) {
	return this->deleteElement(deleteMe);
}