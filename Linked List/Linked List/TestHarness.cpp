#include "OrderedLinkedList.h"
#include <iostream>

int main() {
	OOLList* orderedList = new OOLList;
	int* integerArray = new int[11];
	*orderedList + 5;
	*orderedList + 8;
	*orderedList + 6;
	*orderedList + 1; 
	*orderedList + 9;
	*orderedList + 10;
	*orderedList + 4;
	*orderedList + 2;
	*orderedList + 3;
	*orderedList + 7;
	*orderedList + 11;
	orderedList->getListElements(integerArray);
	for (int i = 0; i < 11; i++) {
		std::cout << integerArray[i] << " ";
	}
	*orderedList - 1;
	orderedList->getListElements(integerArray);
	for (int i = 0; i < 11; i++) {
		std::cout << integerArray[i] << " ";
	}
	std::cout << std::endl << orderedList->getListSize();
	std::cout << std::endl << orderedList->getListSizeInBytes();
}
