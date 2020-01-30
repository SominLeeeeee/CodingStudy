// https://www.acmicpc.net/problem/14502

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

typedef vector< vector<int> > vec;
typedef pair<int, int> p;
vec graph;
vec temp;
queue<p> q;
p* arr;
int N, M;

int bfsVirus();
void find(int x, int y);
void check(int x, int y);

int main() {
	cin >> N >> M;

	graph.resize(N+2);
	for (int y = 0; y < N + 2; y++) {
		graph[y].resize(M + 2, 1);
	} // graph vector 할당

	temp.resize(N + 2);
	for (int y = 0; y < N + 2; y++) {
		temp[y].resize(M + 2);
	} // temp 할당

	for (int y = 1; y < N + 1; y++) {
		for (int x = 1; x < M + 1; x++) {
			cin >> graph[y][x];
		}
	} // graph vector 입력받음
	
	arr = new p[N * M + 1];
	
	for (int y = 1; y < N+1; y++) {
		for (int x = 1; x < M+1; x++) {
			arr[M*(y-1) + x] = make_pair(x, y);
		}
	} // arr[M*(y-1) + x]는 (x, y)이다

	int a, max = 0;

	int i, j, k;
	for (i = 1; i <= N*M - 2; i++) {		// 벽 어디다 세울지 brute-force로 다 세워봄
		if (graph[arr[i].second][arr[i].first] != 0) continue;
		graph[arr[i].second][arr[i].first] = 1;
		for (j = i + 1; j <= N*M - 1; j++) {
			if (graph[arr[j].second][arr[j].first] != 0) continue;
			graph[arr[j].second][arr[j].first] = 1;
			for (k = j + 1; k <= N*M; k++) {
				if (graph[arr[k].second][arr[k].first] != 0) continue;
				graph[arr[k].second][arr[k].first] = 1; // 0이라면 벽 세우기

				a = bfsVirus();				// 벽 세운 이후에 바이러스 퍼트리기
				max = (max > a) ? max : a;	// 바이러스 퍼트린 이후 0 몇개인지 세기 & max값 업데이트

				graph[arr[k].second][arr[k].first] = 0; // 원래대로 돌려놓기
			}
			graph[arr[j].second][arr[j].first] = 0;
		}
		graph[arr[i].second][arr[i].first] = 0;

	} 
	
	cout << max;
	return 0;
}

int bfsVirus() {

	int cnt = 0;
	p fst;

	for (int y = 0; y < N + 2; y++) {
		for (int x = 0; x < M + 2; x++) {
			temp[y][x] = graph[y][x];
		}
	} // graph를 보존하기 위해 임시 벡터에 수정하도록 함

	for (int y = 1; y < N + 1; y++) {
		for (int x = 1; x < M + 1; x++) {
			if (temp[y][x] == 2) {
				q.push(make_pair(x, y));
				temp[y][x] = 1;
			}
		}
	} // 시작점 q에 넣고 방문했음(1) 처리

	while (!q.empty()) {
		fst = q.front();				// 처음꺼
		q.pop();						// 빼고
		find(fst.first, fst.second);	// 주변꺼 검사
	}

	for (int y = 1; y < N + 1; y++) {
		for (int x = 1; x < M + 1; x++) {
			if (temp[y][x] == 0) cnt++;	// 0 개수 세기
		}
	}

	return cnt;							// 0 개수 return
}

void find(int x, int y) {
	check(x-1, y);
	check(x+1, y);
	check(x, y-1);
	check(x, y+1);
} // 상하좌우 바이러스가 퍼질수 있는지 검사

void check(int x, int y) {
	if (temp[y][x] == 0) {
		q.push(make_pair(x, y));		// 0이라면 q에 push
		temp[y][x] = 1;					// 방문했음(1) 표시
	}
}