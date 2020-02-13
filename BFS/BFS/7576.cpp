// https://www.acmicpc.net/problem/7576

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> p;
vector< vector<int> > day;		// 몇일 걸리는지 나타낼 2차원 벡터
queue<p> q;						// 집어넣을 큐
vector< vector<int> > graph;	// 인접행렬

void check(int x, int y);
void visit(int x, int y);
void find(int x, int y, int d);

int main() {
	int N, M;
	cin >> N >> M;

	graph.resize(M + 2);
	for (int i = 0; i < M + 2; i++) {
		graph[i].resize(N + 2, -1);
	}	// 크기가 N+2 * M+2인 2차원 벡터 graph 생성
		// 가장자리의 주변을 탐색할 때를 대비해 상하좌우 한줄씩 추가했음

	bool all = true;	// 전부 다 익은 상태인지 확인하는 변수
	p temp;

	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) all = false;
		}
	}	// graph 벡터 입력받음

	if (all == true) {
		cout << 0;
		return 0;
	}	// 전부 다 익었다면 0일 걸린다고 출력하고 프로그램 종료

	day.resize(M + 2);
	for (int i = 0; i < M + 2; i++) {
		day[i].resize(N + 2);
	}	// 2차원 벡터 day 생성

	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			day[i][j] = graph[i][j];
		}
	}	// day = graph

	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (graph[i][j] == 1) {
				q.push(make_pair(i, j));
				visit(i,j);
			}
		}
	}	// 모든 시작점을 q에 넣는다
		// 시작점의 day값이 1이니까 값 출력할 때 -1

	while (!q.empty()) {				// q가 빌 때까지 계속한다
		temp = q.front();
		q.pop();						// q의 첫번째 pop
		check(temp.first, temp.second); // 꺼낸 vertex 인접vertex 검사
	}

	int max = -1;
	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (day[i][j] == 0) {
				cout << -1;
				return 0;
			} // 모두 다 익지는 못하는 상황인가?

			if (day[i][j] > max) max = day[i][j];
		}
	}

	cout << max - 1;
	return 0;
}

void visit(int x, int y) {
	graph[x][y] = -1;				// 방문한 곳은 못가는걸로 처리
}

void check(int x, int y) {
	find(x, y - 1, day[x][y]);		// 상하좌우 다 체크
	find(x, y + 1, day[x][y]);
	find(x - 1, y, day[x][y]);
	find(x + 1, y, day[x][y]);
}

void find(int x, int y, int d) {
	if (graph[x][y] != -1) {		// 갈 수 있는 곳이라면
		q.push(make_pair(x, y));	// q에 추가
		visit(x, y);				// 방문 했음을 표시
		day[x][y] = d + 1;			// 걸리는 시간 표시
	}
}