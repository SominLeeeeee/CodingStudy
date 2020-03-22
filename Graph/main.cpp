#include "graph.h"

int main() {
	int vertex;
	cout << "how many vertex? ";
	cin >> vertex;

	Graph* g = new Graph(vertex);

	g->inputEdge(1, 2, 3);
	g->inputEdge(2, 3, 4);
	g->inputEdge(3, 2, 1);
	g->inputEdge(3, 4, 7);
	g->inputEdge(1, 4, 5);
	g->inputEdge(4, 1, 2);

	g->printGraph();
	cout << endl;

	g->delVertex(3);

	g->printGraph();
	cout << endl;

	g->inputVertex();
	g->inputEdge(5, 1, 3);
	g->inputEdge(2, 5, 6);
	g->inputEdge(6, 3, 5);

	g->printGraph();
	cout << endl;

	
}