// https://www.acmicpc.net/problem/3055

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
//#include <Windows.h>
using namespace std;

typedef pair<int, int> p;
typedef vector< vector<int> > vec;
p dest;			// 목적지 (비버굴)
vec day;		// 몇일 걸리는지 나타낼 2차원 벡터
vec dayWater;	// 물이 퍼지는ㄷㅔ 며칠 걸리는지
queue<p> q;		// 집어넣을 큐
queue<p> qWater;
vec graph;		// 인접행렬
vec visitedWater;
vec visited;

void bfs();
void bfsWater();
void check(int x, int y);
void checkWater(int x, int y);
void visit(int x, int y);
void find(int x, int y, int d);
void findWater(int x, int y, int d);
//void printVector(vec v, int N, int M);
//void printQueue(queue<p> que);

int N, M;

int main() {
	//int N, M;
	cin >> N >> M;
	
	graph.resize(N + 2);
	for (int i = 0; i < N + 2; i++) {
		graph[i].resize(M + 2, -1);
	}	// 크기가 N+2 * M+2인 2차원 벡터 graph 생성
		// 가장자리의 주변을 탐색할 때를 대비해 상하좌우 한줄씩 추가했음

	day.resize(N + 2);
	for (int i = 0; i < N + 2; i++) {
		day[i].resize(M + 2, 0);
	}

	dayWater.resize(N + 2);
	for (int i = 0; i < N + 2; i++) {
		dayWater[i].resize(M + 2, 0);
	}

	visitedWater.resize(N + 2);
	for (int i = 0; i < N + 2; i++) {
		visitedWater[i].resize(M + 2, -1);
	}

	visited.resize(N + 2);
	for (int i = 0; i < N + 2; i++) {
		visited[i].resize(M + 2, -1);
	}

	char temp;
	//p dest;
	for (int y = 1; y < N + 1; y++) {
		for (int x = 1; x < M + 1; x++) {
			graph[y][x] = 0;
			cin >> temp;

			if (temp == 'S') {				// 고슴도치라면
				graph[y][x] = 1;			// 시작점은 1로 초기화
				day[y][x] = 1;
				q.push(make_pair(x, y));	// 시작점 q에 넣음
				visited[y][x] = -1;				// 시작점 방문했음
				visitedWater[y][x] = 0;
			}

			else if (temp == '*') {			// 물의 시작점
				graph[y][x] = -2;			// 물은 -2
				dayWater[y][x] = 1;
				qWater.push(make_pair(x, y));  // 시작점 qWater에 넣음
				visitedWater[y][x] = -1;				// 물 시작점 방문했음
			}

			else if (temp == 'D') {
				graph[y][x] = visited[y][x] = 0; // 고슴도치는 갈수 있음
				visitedWater[y][x] = -1; // 물은 갈수 없음
				dest = make_pair(x, y); // 비버굴을 목적지로 설정
			}

			else if (temp == 'X') {
				graph[y][x] = visited[y][x] = visitedWater[y][x] = -1;
				day[y][x] = -1;
				dayWater[y][x] = -1;
			}// 돌은 지나갈 수 없음

			else graph[y][x] = visited[y][x] = visitedWater[y][x] = 0;
		} 
	}

	//printVector(graph, N, M);

	bfsWater();
	bfs();
	
	if (day[dest.second][dest.first] != 0) cout << day[dest.second][dest.first]-1;
	else cout << "KAKTUS";

	//cout << "\nthis is dayWater vector\n";
	//printVector(dayWater, N, M);
	
	//cout << "\nthis is daygoseum vector\n";
	//printVector(day, N, M);

}


void visit(int x, int y) {
	graph[y][x] == -1; // 방문한 곳은 다 걸러버리게 -1로 처리한다
}

void bfs() {
	p temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		check(temp.first, temp.second);
//		//cout << "bfs\n";
	}
}

void bfsWater() { // 물 전파시간 bfs돌리기
	p temp;
	int cnt = 0;
	while (!qWater.empty()) {
	//	//cout << endl;
		temp = qWater.front();
		qWater.pop();
		checkWater(temp.first, temp.second);
	}
	////cout << "bfsWater end";
}

void checkWater(int x, int y) {
	findWater(x - 1, y, dayWater[y][x]);
	findWater(x + 1, y, dayWater[y][x]);
	findWater(x, y - 1, dayWater[y][x]);
	findWater(x, y + 1, dayWater[y][x]);

}

void check(int x, int y) {
	find(x - 1, y, day[y][x]);
	find(x + 1, y, day[y][x]);
	find(x, y - 1, day[y][x]);
	find(x, y + 1, day[y][x]);
}

void findWater(int x, int y, int d) {

	if (visitedWater[y][x] != -1 && make_pair(x, y) != dest) { // 돌과 비버굴이 아니라면 & 물이 방문하지 않은 곳이라면
		qWater.push(make_pair(x, y));
		visitedWater[y][x] = -1;
		dayWater[y][x] = d + 1;
	}
}

void find(int x, int y, int d) {
	if (visited[y][x] != -1) {
		if (make_pair(x, y) == dest) { // 목적지일 때
			day[y][x] = d + 1;
		}
		if (d < dayWater[y][x] -1) {
			q.push(make_pair(x, y));
			visited[y][x] = -1;
			day[y][x] = d + 1;
		}
	}
}
/*
void printVector(vec v, int N, int M) {

	for (int i = 0; i < N+2; i++) {
		for (int j = 0; j < M+2; j++) {
			//cout << v[i][j] << " ";
		}
		//cout << endl;
	}
	//cout << "-----------------------" << endl;
}

void printQueue(queue<p> que) {
	queue<p> temp = que;
	p pairrr;
	while (!temp.empty()) {
		pairrr = temp.front();
		temp.pop();
		//cout << "(" << pairrr.first << "," << pairrr.second << ") -> ";
	}
}
*/