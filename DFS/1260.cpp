#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > graph;
queue<int> bfsq;
vector<int> visited;

void dfs(int start);
void bfs();

int main() {
	int node, edge, start;
	cin >> node >> edge >> start;

	graph.resize(node+1);
	for(int i = 0; i <= node; i++) {
		graph[i].resize(node+1);	// graph vector 할당하기 
	}
	visited.resize(node+1, 1);		// visited vector 1로 초기화  

	int to, from;
	for(int i = 0; i < edge; i++) {
		cin >> to >> from;			// 간선의 양 끝 입력받기
		graph[to][from] =
		graph[from][to] = 1;		// graph에 표시
	}

	dfs(start);						// dfs 먼저 실행하기
	cout << endl;
	
	visited.assign(node+1, 1);		// visited 다시 1로 초기화(bfs 위해)
	bfsq.push(start);				// 시작점 bfsq에 넣기
	visited[start] = 0;				// bfs 시작점 방문했음
	bfs();							// bfs 실행 

}

void dfs(int start) {
	cout << start << " ";	// dfs 과정 표시
	visited[start] = 0;		// 방문했다	
	for(int i = 1; i < graph[start].size(); i++) {
		if(graph[start][i] == 1 && visited[i] == 1) {	
			// start에서 i로 갈 수 있고 아직 방문 안했다면
			dfs(i);			// i를 시작점으로 dfs를 실시한다
		}
	}
}

void bfs() {
	int temp;
	while(!bfsq.empty()) {
		temp = bfsq.front();
		bfsq.pop();					// 가장 첫번째 꺼 팝
		cout << temp << " ";
		for(int i = 1; i < graph[temp].size(); i++) {		// 작은 정점부터 검사
			if(graph[temp][i] == 1 && visited[i] == 1) {	// 갈수 있다면
				visited[i] = 0;		// 방문햇다고 표시
				bfsq.push(i);		// 큐에 넣는다
			}
		}
	}
}
