#include <iostream>
#include <random>
#include "LinkedLists.h"

using namespace std;

int main() {
	int choice = 0;
	LinkedList* ll = new LinkedList();
	for (int i = 0; i < 50; i++) {
		ll->push(rand() % 1000);
	}

	cout << ll->toString()<<endl<<endl;

	
	while (choice != 999) {
		cin >> choice; 

		try {
			cout << ll->fromEnd(choice) << endl;
		}

		catch (out_of_range e) {
			cout << e.what() << endl;
		}
	}
}
