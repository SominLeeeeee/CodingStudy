// https://acmicpc.net/problem/11724
#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > graph;
vector<int> visit;	// 1이 방문 안한 곳, 0이 방문한 곳

void dfs(int start);

int main() {
	int N, M;
	cin >> N >> M;

	visit.resize(N, 1);
	graph.resize(N);
	for(int i = 0; i < N; i++) {
		graph[i].resize(N);
	}

	int to, from;
	for(int i = 0; i < M; i++) {
		cin >> to >> from;
		graph[to-1][from-1] = graph[from-1][to-1] = 1;
	}

	int num = 0;
	for(int i = 0; i<N; i++) {
		if(visit[i]) {
			num++;
			visit[i] = 0;
			dfs(i);
		}
	}

	cout << num;
}

void dfs(int start) {
	for(int i = 0; i<graph[0].size(); i++) {
		if(graph[start][i] == 1 && visit[i]) {
			visit[i] = 0;
			dfs(i);
		}
	}
}
