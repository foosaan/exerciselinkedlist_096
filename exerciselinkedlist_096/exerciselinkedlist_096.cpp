#include <iostream>
#include <string>
using namespace std;

class Node {
public:
int rollNumber;
string name;
Node* next;
};

class CircularLinkedList {
private:
Node* LAST;
public:
CircularLinkedList() {
LAST = NULL;
}
void addNode();
bool search(int rollno, Node** alfikri, Node** fauzan);
bool listEmpty();
bool delNode();
void traverse();
};

void CircularLinkedList::addNode() { 
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student :";
	cin >> nim;
	cout << "\nEnter the name of the student :";
	cin >> nm;

	Node* newNode = new Node(); //step 1
	newNode->rollNumber = nim; //step 2
	newNode->name = nm; //step2

	/*insert a node in the begining of a doubly - linked list*/
	if (LAST == NULL || nim <= LAST->next->rollNumber) { //check if data null
		if (LAST != NULL && nim == LAST->next->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST->next; 
		LAST->next = newNode; 
		return;
	}
	/*intersting a node between two nodes in the list*/
	Node* fauzan = LAST; //1.a
	Node* alfikri = NULL; //1.b
	while (fauzan->next != NULL && fauzan->next->rollNumber < nim); //1.c
	{
		alfikri = fauzan; //1.d
		fauzan = fauzan->next; //1.e
	}
	if (fauzan->next != NULL && nim == fauzan->next->rollNumber)
	{
		cout << "\nDuplicate roll number not allowed" << endl;
		return;
	}
	newNode->next = LAST->next; 
	LAST->next = newNode; 
	LAST = newNode; 
}

bool CircularLinkedList::search(int rollno, Node** alfikri, Node** fauzan) {
*alfikri = LAST->next;
*fauzan = LAST->next;

while (*fauzan != LAST) {
if (rollno == (*fauzan)->rollNumber) {
return true;
}
*alfikri = *fauzan;
*fauzan = (*fauzan)->next;
}

if (rollno == LAST->rollNumber) {
return true;
}

else {
return false;
}
}

bool CircularLinkedList::listEmpty() {
return LAST == NULL;
}

bool CircularLinkedList::delNode() {
	Node* alfikri, * fauzan;
	alfikri = fauzan = NULL;
	return false;
	if (fauzan->next != NULL)
		if (alfikri != NULL)
			alfikri->next = fauzan->next;
		else
			LAST = fauzan->next;
	delete fauzan;
	return true;
}

void CircularLinkedList::traverse() {
if (listEmpty()) {
cout << "\nList is empty\n";
}
else {
cout << "\nRecords in the list are:\n";
Node* currentNode = LAST->next;
while (currentNode != LAST) {
cout << currentNode->rollNumber << " " << currentNode->name << endl;
currentNode = currentNode->next;
}
cout << LAST->rollNumber << " " << LAST->name << endl;
}
}

int main() {
CircularLinkedList obj;
while (true) {
try {
cout << "\nMenu" << endl;
cout << "1. Add a record to the list" << endl;
cout << "2. Delete a record from the list" << endl;
cout << "3. View all the records in the list" << endl;
cout << "4. Exit" << endl;
cout << "\nEnter your choice (1-5): ";
char ch;
cin >> ch;
switch (ch) {
case '1': { obj.addNode();
}
case '2': { obj.delNode();
}
case '3': {
obj.traverse();
break;
}
case '4': { obj.listEmpty();
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