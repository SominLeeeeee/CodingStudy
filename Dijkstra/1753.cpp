#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> p;

int main() {
	int V, E;		// V는 정점의 개수, E는 간선의 개수
	cin >> V >> E;
	
	int start;
	cin >> start;

	priority_queue<p> pq;

	int to, from, weight;
	for(int i = 0; i<E; i++) {
		cin >> from >> to >> weight;
	}
}
