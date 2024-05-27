#include <iostream>
#include <string>

using namespace std;

struct Plane {
	int boardNumber;
	string type;
	string model;
	int cargoLoad;
	int flightRange;

	Plane() {};
	Plane(int boardNumber, string type, string model, int cargoLoad, int flightRange) :
		boardNumber(boardNumber), type(type), model(model), cargoLoad(cargoLoad), flightRange(flightRange) {}
	string toString() {
		return "Board Number: " + std::to_string(boardNumber) + ", Type: " + type +
			", Model: " + model + ", Cargo Load: " + std::to_string(cargoLoad) +
			", Flight Range: " + std::to_string(flightRange);
	}
};

struct ListNode {
	Plane plane;
	ListNode* next;
	ListNode* prev;
	ListNode(Plane plane) : plane(plane), next(NULL), prev(NULL) {}
};

struct ListOfPlanes {
	ListNode* head;
	ListNode* tale;

	ListOfPlanes() : head(NULL), tale(NULL){}
	void insert(Plane plane) {
		if (head == NULL) {
			head = new ListNode(plane);
			tale = head;
			return;
		}
		ListNode* newNode = new ListNode(plane);
		if (head->plane.boardNumber > plane.boardNumber) {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
			return;
		}
		if (tale->plane.boardNumber < plane.boardNumber) {
			newNode->prev = tale;
			tale->next = newNode;
			tale = newNode;
			return;
		}
		ListNode* cur = head;
		while (cur->plane.boardNumber < plane.boardNumber) {
			cur = cur->next;
		}
		newNode->prev = cur->prev;
		newNode->next = cur;
		cur->prev->next = newNode;
		cur->prev = newNode;
	}
	void writeList() {
		ListNode* cur = head;
		while (cur != NULL) {
			cout << cur->plane.toString() << " \n";
			cur = cur->next;
		}
	}
	void reverseWriteList() {
		ListNode* cur = tale;
		while (cur != NULL) {
			cout << cur->plane.toString() << " \n";
			cur = cur->prev;
		}
	}
};


ListOfPlanes listPlanes;

int main()
{
	int ans = 1;
	while (ans != 0) {
		cout << "\n\nvvedite 1 ili 2";
		cin >> ans;
		switch (ans)
		{
		case 1: {
			int boardNumber;
			string type;
			string model;
			int cargoLoad;
			int flightRange;
			cin >> boardNumber >> type >> model >> cargoLoad >> flightRange;
			Plane plane = Plane(boardNumber, type, model, cargoLoad, flightRange);
			listPlanes.insert(plane);
			break;
		}
		case 2:
			listPlanes.writeList();
			break;
		case 3:
			listPlanes.reverseWriteList();
			break;
		default:
			cout << "Некоректный ввод попробуйте ещё раз\n";
			break;
		}
	}
}




//одиночный список
/*
#include <iostream>
#include <string>

using namespace std;

struct Plane {
	int boardNumber;
	string type;
	string model;
	int cargoLoad;
	int flightRange;

	Plane() {};
	Plane(int boardNumber, string type, string model, int cargoLoad, int flightRange) :
		boardNumber(boardNumber), type(type), model(model), cargoLoad(cargoLoad), flightRange(flightRange) {}
	string toString() {
		return "Board Number: " + std::to_string(boardNumber) + ", Type: " + type +
			", Model: " + model + ", Cargo Load: " + std::to_string(cargoLoad) +
			", Flight Range: " + std::to_string(flightRange);
	}
};

struct ListNode {
	Plane plane;
	ListNode* next;
	ListNode(Plane plane) : plane(plane), next(NULL) {}
};

struct ListOfPlanes {
	ListNode* head;

	ListOfPlanes() : head(NULL) {}
	void insert(Plane plane) {
		if (head == NULL) {
			head = new ListNode(plane);
			return;
		}
		ListNode* cur = NULL;
		ListNode* next = head;
		while (next != NULL && next->plane.boardNumber < plane.boardNumber) {
			cur = next;
			next = next->next;
		}
		ListNode* newNode = new ListNode(plane);
		if (cur == NULL) {
			newNode->next = head;
			head = newNode;
		}
		else {
			cur->next = newNode;
			newNode->next = next;
		}
	}
	void writeList() {
		ListNode* cur = head;
		while (cur != NULL) {
			cout << cur->plane.toString() << " \n";
			cur = cur->next;
		}
	}
};


ListOfPlanes listPlanes;

int main()
{
	int ans = 1;
	while (ans != 0) {
		cout << "\n\nvvedite 1 ili 2";
		cin >> ans;
		switch (ans)
		{
		case 1: {
			int boardNumber;
			string type;
			string model;
			int cargoLoad;
			int flightRange;
			cin >> boardNumber >> type >> model >> cargoLoad >> flightRange;
			Plane plane = Plane(boardNumber, type, model, cargoLoad, flightRange);
			listPlanes.insert(plane);
			break;
		}
		case 2:
			listPlanes.writeList();
			break;
		default:
			cout << "Некоректный ввод попробуйте ещё раз\n";
			break;
		}
	}
}

*/