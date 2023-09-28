#pragma once
#include <string>

class Node {
private:
	int payload;
	Node* next; 

public:
	Node(int, Node* = nullptr);
	int getPayload();
	Node* getNext();
	void setNext(Node*);
};


class LinkedList {
private:
	Node* head;
	//
	void setHead(Node*);
	Node* getHead();

public:
	// Construct linked list with no nodes
	LinkedList();

	// Construct linked list with head as list's head node
	LinkedList(Node* head);

	// Construct linked list with val as head's value
	LinkedList(int val);
	
	// string representation of current list
	std::string toString();

	// place val at the beginning of list
	void insert(int val);

	// Place val at end of list
	void push(int val);

	// Removes first element from list matching val
	// Return indicates if a delete ocured
	bool remove(int val);

	// Removes all elements from list matching val
	// Return indicates if at least one delete occured
	bool removeAll(int val);

	// Removes element at idx. idx is zero based.
	// Return indicates if a delete occured 
	// Thorws out_of_range
	void removeAt(const int idx);

	// Returns value from node at idx. Idx is zero based.
	// Throws out_of_range
	int at(const int idx);

	// Returns the number of nodes in the list
	int length();

	// reverse indexing. Gets the node idx from last node
	int fromEnd(const int idx);
	
	// Destructor
	~LinkedList();
};