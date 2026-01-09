#include <iostream>
#include "LinkedList.h"

// Constructor
LinkedList::LinkedList() : head(nullptr) {}

// Destructor to free nodes
LinkedList::~LinkedList() {
	Node* cur = head;
	while (cur) {
		Node* next = cur->next;
		delete cur;
		cur = next;
	}
}

// Insert at front
void LinkedList::insert(int val) {
	Node* node = new Node{val, head};
	head = node;
}

bool LinkedList::isEmpty() {
	return head == nullptr;
}

void LinkedList::update(int oldVal, int newVal) {
	Node* cur = head;
	while (cur) {
		if (cur->data == oldVal) {
			cur->data = newVal;
		}
		cur = cur->next;
	}
}

void LinkedList::remove(int val) {
	Node* cur = head;
	Node* prev = nullptr;
	while (cur) {
		if (cur->data == val) {
			Node* toDelete = cur;
			if (prev)
				prev->next = cur->next;
			else
				head = cur->next;
			cur = cur->next;
			delete toDelete;
		} else {
			prev = cur;
			cur = cur->next;
		}
	}
}

void LinkedList::display() {
	Node* cur = head;
	if (!cur) {
		std::cout << "List is empty\n";
		return;
	}
	while (cur) {
		std::cout << cur->data;
		if (cur->next)
			std::cout << " -> ";
		cur = cur->next;
	}
	std::cout << '\n';
}

// Small test runner to demonstrate expected behaviour
int main() {
	LinkedList list;
	list.insert(3);
	list.insert(2);
	list.insert(1);
	std::cout << "Initial list: ";
	list.display();

	list.update(2, 20);
	std::cout << "After update 2->20: ";
	list.display();

	list.remove(20);
	std::cout << "After remove 20: ";
	list.display();

	return 0;
}

