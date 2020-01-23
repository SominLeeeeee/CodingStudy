// https://www.acmicpc.net/problem/3055

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> p;
typedef vector< vector<int> > vec;
p dest;			// 목적지 (비버굴)
vec day;		// 몇일 걸리는지 나타낼 2차원 벡터
vec dayWater;	// 물이 퍼지는ㄷㅔ 며칠 걸리는지
queue<p> q;		// 집어넣을 큐
queue<p> qWater;
vec graph;		// 인접행렬

void bfs();
void bfsWater();
void check(int x, int y);
void checkWater(int x, int y);
void visit(int x, int y);
void find(int x, int y, int d);
void findWater(int x, int y, int d);
void printVector(vec v, int N, int M);

int main() {
	int N, M;
	cin >> M >> N;
	
	graph.resize(M + 2);
	for (int i = 0; i < M + 2; i++) {
		graph[i].resize(N + 2, -1);
	}	// 크기가 N+2 * M+2인 2차원 벡터 graph 생성
		// 가장자리의 주변을 탐색할 때를 대비해 상하좌우 한줄씩 추가했음

	day.resize(M + 2);
	for (int i = 0; i < M + 2; i++) {
		day[i].resize(N + 2, 0);
	}

	dayWater.resize(M + 2);
	for (int i = 0; i < M + 2; i++) {
		dayWater[i].resize(N + 2, 0);
	}

	char temp;
	//p dest;
	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			graph[i][j] = 0;
			cin >> temp;

			if (temp == 'S') {				// 고슴도치라면
				graph[i][j] = 1;			// 시작점은 1로 초기화
				day[i][j] = 1;
				q.push(make_pair(i, j));	// 시작점 q에 넣음
				visit(i, j);				// 시작점 방문했음
			}

			else if (temp == '*') {			// 물의 시작점
				graph[i][j] = -2;			// 물은 -2
				dayWater[i][j] = 1;
				qWater.push(make_pair(i, j));  // 시작점 qWater에 넣음
				visit(i, j);				// 물 시작점 방문했음
			}

			else if (temp == 'D') {
				graph[i][j] = 0;
				dest = make_pair(i, j); // 비버굴을 목적지로 설정
			}

			else if (temp == 'X') {
				graph[i][j] = -1;
				day[i][j] = -1;
				dayWater[i][j] = -1;
			}// 돌은 지나갈 수 없음

			else graph[i][j] = 0;
		} 
	}

	printVector(graph, N, M);

	bfsWater();
	bfs();
	
	cout << "\nthis is dayWater vector\n";
	printVector(dayWater, N, M);
	
	cout << "\nthis is daygoseum vector\n";
	printVector(day, N, M);



}


void visit(int i, int j) {
	graph[i][j] == -1; // 방문한 곳은 다 걸러버리게 -1로 처리한다
}

void bfs() {
	p temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		check(temp.first, temp.second);
//		cout << "bfs\n";
	}
}

void bfsWater() { // 물 전파시간 bfs돌리기
	p temp;
	int cnt = 0;
	while (!qWater.empty()) {
		temp = qWater.front();
		qWater.pop();
		checkWater(temp.first, temp.second);
	//	cout << cnt++ << endl;
	}
	cout << "bfsWater end";
}

void checkWater(int x, int y) {
	findWater(x - 1, y, dayWater[x][y]);
	findWater(x + 1, y, dayWater[x][y]);
	findWater(x, y - 1, dayWater[x][y]);
	findWater(x, y + 1, dayWater[x][y]);
}

void check(int x, int y) {
	find(x - 1, y, day[x][y]);
	find(x + 1, y, day[x][y]);
	find(x, y - 1, day[x][y]);
	find(x, y + 1, day[x][y]);
}

void findWater(int x, int y, int d) {
	if (graph[x][y] != -1 && make_pair(x, y) != dest) { // 돌과 비버굴이 아니라면
		qWater.push(make_pair(x, y));
		visit(x, y);
		dayWater[x][y] = d + 1;
	}
}

void find(int x, int y, int d) {
	if (graph[x][y] != -1 && d < dayWater[x][y]) {
		q.push(make_pair(x, y));
		visit(x, y);
		day[x][y] = d + 1;
	}
}

void printVector(vec v, int N, int M) {

	for (int i = 0; i < M+2; i++) {
		for (int j = 0; j < N+2; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}