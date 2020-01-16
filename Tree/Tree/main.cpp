#include "bst.h"
#include "heap.h"
#include "tree.h"
#include <iostream>
#define null 0
using namespace std;

void testBST();
void printHeap(Heap* h);
void testHeap();
void testTree();

int main() {

	int test;
	cout << "what do you want to test?\n"
		<< "1.Tree traversal, 2.Heap, 3.Binary Search Tree ";
	cin >> test;

	cout << endl;

	switch (test) {
	case 1:
		testTree();
		break;

	case 2:
		testHeap();
		break;

	case 3:
		testBST();
		break;
	}

	cout << endl;
	return 0;
}

void testBST() {

	Tree* t = new Tree;

	push_root(10, t);
	push_bst(4, t);
	push_bst(16, t);
	push_bst(13, t);
	push_bst(14, t);
	push_bst(30, t);
	push_bst(20, t);
	push_bst(42, t);
	push_bst(18, t);
	push_bst(25, t);
	push_bst(35, t);

	t->inorder(t->getRoot());

	pop_bst(18, t);

	cout << endl;
	t->inorder(t->getRoot());

	cout << "\nMax is " << searchMax(t->getRoot())->data;
	cout << "\nMin is " << searchMin(t->getRoot())->data;

}

void printHeap(Heap* h) {
	for (int i = 1; i < h->v.size(); i++) {
		if (i == 1 || i == 2 || i == 4 || i == 8) {
			std::cout << endl;
			for (int j = 0; j < 8 - i; j++) {
				std::cout << "  ";
			}
		}
		std::cout << h->v[i] << "  ";

	}
}

void testHeap() {
	Heap* h = new Heap;
	h->makeHeap();

	for (int i = 0; i < 14; i++) {
		h->push(rand() % 50);
	}

	std::cout << "---insert result\n";
	printHeap(h);

	h->pop();

	std::cout << "\n\n---pop result \n";
	printHeap(h);
}

void testTree() {
	/*
			(1)
		   /   \
		(2)	   (3)
	   /   \
	(4)	   (5)
	*/
	Tree* t = new Tree;
	Node* n4 = t->makeNode(4);
	Node* n5 = t->makeNode(5);
	Node* n2 = t->makeNode(n4, n5, 2);
	Node* n3 = t->makeNode(3);
	Node* n1 = t->makeNode(n2, n3, 1);

	t->setRoot(n1);

	std::cout << "this is inorder\n";
	t->inorder(t->getRoot());

	std::cout << "\nthis is preorder\n";
	t->preorder(t->getRoot());

	std::cout << "\nthis is postorder\n";
	t->postorder(t->getRoot());
}