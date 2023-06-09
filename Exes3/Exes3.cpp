#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
	Node* prev;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** ulfah, Node** muhajirah);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() { //write your answer here, menambah data
	int rollNo;
	string nm;
	cout << "\Enter the roll number : ";
	cin >> rollNo;
	cout << "\nEnter the name : ";
	cin >> nm;
	Node* newNode = newNode;

	// insert a node in the beginning of a circular-linked list
	if (LAST == NULL || rollNo <= LAST->rollNumber) { // step 1
		if (LAST != NULL && rollNo == LAST->rollNumber) { // step 2
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}

		newNode->next = LAST->next; // step 3
		LAST->next = newNode; // step 4

		return;
	}

	// insert a Node between two node in the list
	Node* muhajirah = LAST->next; // step 1
	Node* ulfah = NULL; // step 2
	while (LAST != ulfah || newNode > muhajirah) { // step 3
		ulfah = muhajirah->next;
	}

	newNode->next = muhajirah->next; // step 4
	newNode->ulfah = muhajirah; 

	if (muhajirah->next != NULL) // step 5
	muhajirah->next->ulfah = newNode;
	muhajirah->next = newNode;

	// insert a node in the end of the list
	if (LAST != NULL && newNode >= LAST->next) { // step 1
		if ((LAST == NULL && newNode >= LAST)) { // step 2
			cout << "\Duplicate number not allowed" << endl;
			return;
		}

		newNode->next = LAST->next; // step 3
		LAST->next = newNode; // step 4
		LAST = newNode; // step 5

		return;
	}
}

bool CircularLinkedList::search(int rollno, Node** ulfah, Node** muhajirah) { // mencari data
	*ulfah = LAST->next;
	*muhajirah = LAST->next;
	while (*muhajirah != LAST) {
		if (rollno == (*muhajirah)->rollNumber) {
			return true;
		}
		*ulfah = *muhajirah;
		*muhajirah = (*muhajirah)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() { // memeriksa list kosong 
	return LAST == NULL;
}

bool CircularLinkedList::delNode() { //write your answer here
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}
	cout << "\nEnter the roll number of the student whose record is to be deleted : ";
	int rollNo;
	cin >> rollNo;
	cout << endl;

	if (CircularLinkedList::delNode() == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number" << rollNo << "deleted" << endl;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* muhajirahNode = LAST->next;
		while (muhajirahNode != LAST) {
			cout << muhajirahNode->rollNumber << " " << muhajirahNode->name << endl;
			muhajirahNode = muhajirahNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() { // fungsi utama
	CircularLinkedList obj; // memanggil method
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch; // membuat pilihan
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}
