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
	// 생성자
	Node(int i) {
		data = i;
	}
};

class List {
private:
	Node* head;
	Node* tail;
	int size;

public:
	List() {
		head = null;
		tail = null;
		size = 0;
	}

	//List가 비었는가?
	bool isEmpty();

	//node 추가 (맨 앞, 맨 뒤, 원하는 위치)
	void addNodeFirst(int data);
	void addNodeLast(int data);
	void addNode(int data, int position);

	//node 삭제 (맨 앞, 맨 뒤, 원하는 위치)
	int delNodeFirst();
	int delNodeLast();
	int delNode(int position);
	void removeNode(Node* node);

	//List 출력하기
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

	else if (position - 1 > size) {
		std::cout << "you enter wrong position\n";
		return;
	}

	for (int i = 1; i < position - 1; i++) {
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

int List::delNodeFirst() {
	if (isEmpty()) return 0;

	int result = head->data;

	Node* temp = head;
	head = head->next;
	removeNode(temp);
	if(!isEmpty()) head->prev = null;

	return result;
}

int List::delNodeLast() {
	if (isEmpty()) return 0;

	int result = tail->data;

	Node* temp = tail;
	tail = tail->prev;
	removeNode(temp);
	if(!isEmpty()) tail->next = null;

	return result;
}

int List::delNode(int position) {
	Node* curr = head;

	if (position == 1) {
		return delNodeFirst();
	}

	else if (position - 1 == size) {
		return delNodeLast();
	}

	else if (position - 1 > size) {
		std::cout << "you enter wrong position\n";
		return 0;
	}

	for (int i = 1; i < position; i++) {
		curr = curr->next;
	}

	int result = curr->data;
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	removeNode(curr);

	return result;
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