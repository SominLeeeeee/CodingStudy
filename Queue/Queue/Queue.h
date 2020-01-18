#pragma once
#include "dLinkedList.h"
using namespace std;

class Queue {
private:
	List* l;

public:
	Queue() {
		l = new List;
	}
	
	void push(int data);
	void pop();
	void print();
};

void Queue::push(int data) {
	l->addNodeLast(data);
}

void Queue::pop() {
	if (l->isEmpty()) { 
		cout << "no more data on queue" << endl;
		return; 
	}
	cout << l->delNodeFirst() << endl;
}

void Queue::print() {
	l->printList();
}