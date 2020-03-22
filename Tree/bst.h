#pragma once
#include "tree.h"

// search
Node* searchMin(Node* node) {
	if (node->left != null) searchMin(node->left);
	else return node;
}

Node* searchMax(Node* node) {
	if (node->right != null) searchMax(node->right);
	else return node;
}

Node* searchNode(int n, Node* root) {
	Node* point = root;
	while (true) {
		if (n < point->data) {
			point = point->left;
		}
		else if (n > point->data) {
			point = point->right;
		}
		else return point;
	}
}

// insert
void push_bst(int data, Tree* t) {
	Node* n = t->makeNode(data);
	Node* where = t->getRoot();
	while (true) {
		if (data > where->data) {
			if (where->right == null) {
				where->right = n;
				n->parent = where;
				break;
			}
			else where = where->right;
		}
		else {
			if (where->left == null) {
				where->left = n;
				n->parent = where;
				break;
			}
			else where = where->left;
		}
	}
}

void push_root(int data, Tree* t) {
	Node* node = new Node;
	node->data = data;
	node->left = null;
	node->right = null;
	t->setRoot(node);
}

// delete
void pop_bst(int data, Tree* t) {
	Node* point = searchNode(data, t->getRoot());

	Node* r = point->right;
	Node* l = point->left;
	Node* p = point->parent;

	if (t->isLeaf(point)) { // 삭제하려는 node의 자식이 없는 경우
		if (p->left == point) p->left = null;
		else p->right = null;
	}

	else if (l != null && r != null) { // 자식 둘 다 있는 경우
		r->parent = p;
		p->right = r;

		Node* least = searchMin(r);
		least->left = l;
		l->parent = least;
	}

	else { // 자식이 한쪽만 있는 경우
		if (l == null) { // 오른쪽 자식만 있는 경우
			if (p->right == point) { // 부모의 오른쪽 자식이였다면
				r->parent = p;
				p->right = r;
			}
			else {
				r->parent = p;
				p->left = r;
			}
		}
		else {
			if (p->right == point) {
				l->parent = p;
				p->right = l;
			}
			else {
				l->parent = p;
				p->left = l;
			}
		}
	}

	t->removeNode(point);


}

// test
void testBST();