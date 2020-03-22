#pragma once
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node(int n) {
		this->data = n;
	}
};

class Stack {
private:
	int maxSize = 0;
	int sp;
	Node** n;

public:
	Stack(int maxSz) {
		this->maxSize = maxSz;
		n = new Node*[maxSz];
		sp = 0;
	}

	~Stack() {
		for (int i = 0; i < maxSize; i++) {
			delete n[i];
		}
		delete[] n;
	}

	void push(int data);
	int pop();
};

void Stack::push(int data) {
	if (sp == maxSize) {
		cout << "stack is full!\n";
		return;
	}

	Node* temp = new Node(data);
	n[sp++] = temp;
}

int Stack::pop() {
	if (sp > 0) {
		cout << n[--sp]->data << endl;
		return n[sp]->data;
	}

	else cout << "no more data on stack\n";
	return 0;
}
