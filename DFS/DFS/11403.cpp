#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector< vector<int> > graph;
vector< vector<int> > result;
vector<int> visited;
stack<int> s;
int cache;

void dfs(int start);

int main() {

	int N;
	cin >> N;

	graph.resize(N+1);
	result.resize(N+1);
	for(int i = 0; i < N+1; i++) {
		for(int j = 0; j < N+1; j++) {
			graph[i].resize(N+1, 0);
			result[i].resize(N+1, 0);
		}
	}	// graph 할당

	for(int y = 1; y <= N; y++) {
		for(int x = 1; x <= N; x++) {
			cin >> graph[y][x];
		}
	}	// graph 입력받기, y는 to, x는 from

	for(int i = 1; i<= N; i++) {
		visited.assign(N+1, 1);
		cache = i;
		dfs(i);
	}

	for(int y = 1; y<=N; y++) {
		for(int x = 1; x <= N; x++) {
			cout << result[y][x] << " ";
		}
		cout << endl;
	}


}

void dfs(int start) {
	for(int i = 1; i < graph[0].size(); i++) {
		if(graph[start][i] == 1 && visited[i]) {	// 갈 수 있고 아직 방문 안했다면
			visited[i] = 0;			// 방문했음 표시
			result[cache][i] = 1;	// cache부터 i까지 갈수 있다고 표시 
			dfs(i);					// i를 시작점으로 dfs 실행
		}
	}
	return;	
}
