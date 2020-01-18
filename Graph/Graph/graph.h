//graph - adjacency matrix
#pragma once
#include <vector>
#include <iostream>
#define INFINITY 2147483647
using namespace std;

class Graph {
private: // �ܹ��⼺ ����ġ��
	int vertex = 0;
	vector < vector<int> > graph;

public:

	Graph(int v) {
		this->vertex = v;
		graph.resize(vertex+1);
		for (int i = 0; i <= vertex; i++) {
			graph[i].resize(vertex+1, INFINITY);
		}

		for (int i = 1; i <= vertex; i++) {
			graph[i][i] = 0; // �ڱ� �ڽ����� ���� ���� 0
		}
	}

	void inputEdge(int from, int to, int weight); // edit ��ɵ� ���Ѵ�
	void inputVertex();
	void delVertex(int v);
	void printGraph();
};

void Graph::inputEdge(int from, int to, int weight) {
	if (from > vertex || to > vertex) {
		cout << "please add vertex first" << endl;
		return;
	}

	graph[from][to] = weight;
	return;
}

void Graph::inputVertex() {
	vertex++;
	graph.resize(vertex + 1);
	for (int i = 0; i <= vertex; i++) {
		graph[i].resize(vertex+1, INFINITY);
	}
}

void Graph::delVertex(int v) {
	for (int i = 0; i <= vertex; i++) {
		graph[v][i] = INFINITY;
		graph[i][v] = INFINITY;
	}
}

void Graph::printGraph() {
	for (int i = 0; i <= vertex; i++) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 1; i <= vertex; i++) {
		cout << i << " ";
		for (int j = 1; j <= vertex; j++) {
			if (graph[i][j] == INFINITY) cout << "x ";
			else cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}