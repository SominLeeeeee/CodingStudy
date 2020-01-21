//https://www.acmicpc.net/problem/2178

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define yes 49
#define no 48
using namespace std;

void check(int x, int y);
void visit(int x, int y);
void find(int x, int y, int leng);

vector< vector<int> > length;
queue< pair<int, int> > q;
vector< vector<char> > graph;

int main() {
	int N, M;
	cin >> N >> M;

	pair<int, int> temp;

	graph.resize(N+2);
	for (int i = 0; i < N+2; i++) {
		graph[i].resize(M+2, no);
	}	// 크기가 N+2 * M+2인 2차원 벡터 graph 생성
		// 가장자리의 주변을 탐색할 때를 위해 상하좌우 한줄씩 추가했음

	for (int i = 1; i < N+1; i++) {
		for (int j = 1; j < M+1; j++) {
			cin >> graph[i][j];
		}
	}	// graph 벡터 입력받음

	length.resize(N + 2);
	for (int i = 0; i < N + 2; i++) {
		length[i].resize(M + 2, 0);
	}	// 2차원 벡터 length 생성 및 초기화

	length[1][1] = 1;					// 시작점의 length는 1
	
	q.push(make_pair(1, 1));			// 시작점을 Q에 넣는다
	visit(1, 1);						// 시작점 방문했음

	while (!q.empty()) {				// q가 빌 때까지 계속한다
		temp = q.front();
		q.pop();						// q의 첫번째 pop
		check(temp.first, temp.second); // 꺼낸 vertex 인접vertex 검사
	}

	cout << length[N][M];				// 시작점->(N,M) 길이

}

void visit(int x, int y) {
	graph[x][y] = no;					// 방문한 곳은 못가는걸로 처리
}

void check(int x, int y) {
	find(x, y - 1, length[x][y]);		// 상하좌우 다 체크
	find(x, y + 1, length[x][y]);
	find(x - 1, y, length[x][y]);
	find(x + 1, y, length[x][y]);
}

void find(int x, int y, int leng) {
	if (graph[x][y] == yes) {			// 갈 수 있는 곳이라면
		q.push(make_pair(x, y));		// q에 추가
		visit(x, y);					// 방문 했음을 표시
		length[x][y] = leng + 1;		// 걸리는 거리 표시
	}
}