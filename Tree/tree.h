#pragma once
#include <iostream>
#define null 0

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node* parent;
};

class Tree {
public:
	Node* root;

	void setRoot(Node* node) {
		this->root = node;
	}

	Node* getRoot() {
		return this->root;
	}

	//remove node
	void removeNode(Node* n) {
		n->data = null;
		n->left = null;
		n->right = null;
		n->parent = null;
	}

	//insert node
	Node* makeNode(Node* left, Node* right, int data) {
		Node* node = new Node;
		node->data = data;
		node->left = left;
		node->right = right;

		node->left->parent = node;
		node->right->parent = node;

		return node;
	}

	Node* makeNode(int data) { // for leaf
		Node* node = new Node;
		node->data = data;
		node->left = null;
		node->right = null;
		return node;
	}

	bool isLeaf(Node* node) {
		bool result = false;
		if (node->left == null && node->right == null) result = true;
		return result;
	}

	// traversal & print
	void inorder(Node* node) {
		if (node != null) {
			inorder(node->left);
			std::cout << node->data << ' ';
			inorder(node->right);
		}
	}

	void preorder(Node* node) {
		if (node != null) {
			std::cout << node->data << ' ';
			preorder(node->left);
			preorder(node->right);
		}
	}

	void postorder(Node* node) {
		if (node != null) {
			postorder(node->left);
			postorder(node->right);
			std::cout << node->data << ' ';
		}
	}

};
