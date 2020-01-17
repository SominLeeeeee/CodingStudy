#pragma once
#include <iostream>
#define null 0
using namespace std;

class Node {
	friend class List;
private:
	int data;
	Node* prev = null;
	Node* next = null;

public:
	// ������
	Node(int i) {
		data = i;
	}
};

class List {
private:
	Node* head = null;
	Node* tail = null;
	int size = 0;

public:
	//List�� ����°�?
	bool isEmpty();

	//node �߰� (�� ��, �� ��, ���ϴ� ��ġ)
	void addNodeFirst(int data);
	void addNodeLast(int data);
	void addNode(int data, int position);

	//node ���� (�� ��, �� ��, ���ϴ� ��ġ)
	void delNodeFirst();
	void delNodeLast();
	void delNode(int position);
	void removeNode(Node* node);

	//List ����ϱ�
	void printList();
};

bool List::isEmpty() {
	if (head == null) return true;
	else return false;
}

void List::addNodeLast(int data) {
	Node* temp = new Node(data);

	if (isEmpty()) {
		head = temp;
		tail = temp;
	}

	else {
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}

	size++;
}

void List::addNodeFirst(int data) {
	Node* temp = new Node(data);

	if (isEmpty()) {
		*head = *temp;
		*tail = *temp;
	}

	else {
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	size++;
}

void List::addNode(int data, int position) {
	Node* temp = new Node(data);
	Node* curr = head;

	if (position == 1) {
		addNodeFirst(data);
		return;
	}

	else if (position - 1 == size) {
		addNodeLast(data);
		return;
	}

	else if (position-1 > size) {
		std::cout << "you enter wrong position\n";
		return;
	}

	for (int i = 1; i < position-1; i++) {
		curr = curr->next;
	}

	temp->next = curr->next;
	temp->prev = curr;
	temp->next->prev = temp;
	curr->next = temp;
	size++;
}

void List::removeNode(Node* node) {
	node->data = null;
	node->prev = null;
	node->next = null;
	size--;
}

void List::delNodeFirst() {
	if (isEmpty()) return;
	head = head->next;
	removeNode(head->prev);
	head->prev = null;
}

void List::delNodeLast() {
	if (isEmpty()) return;
	tail = tail->prev;
	removeNode(tail->next);
	tail->next = null;
}

void List::delNode(int position) {
	Node* curr = head;

	if (position == 1) {
		delNodeFirst();
		return;
	}

	else if (position - 1 == size) {
		delNodeLast();
		return;
	}

	else if (position - 1 > size) {
		std::cout << "you enter wrong position\n";
		return;
	}

	for (int i = 1; i < position; i++) {
		curr = curr->next;
	}

	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	removeNode(curr);
}

void List::printList() {
	Node* curr = head;
	for (int i = 1; i <= size; i++) {
		cout << curr->data;
		if (i != size) cout << " -> ";
		curr = curr->next;
	}
	cout << endl;
}