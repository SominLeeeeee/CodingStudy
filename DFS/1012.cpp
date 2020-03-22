// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector< vector<int> > lettuce;
int N, M, K;

void dfs(int x, int y);

int main() {

	int T; // 몇 번 테스트할건지
	cin >> T;
	cin >> M >> N >> K;					// 가로, 세로, 배추 개수

	lettuce.resize(N + 2);
	for (int i = 0; i < N + 2; i++) {	// N이 세로
		lettuce[i].resize(M + 2, 0);		// M이 가로
	}
	
	int x, y;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			cin >> x >> y;
			lettuce[y + 1][x + 1] = 1;
		}
	}

	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (lettuce[y][x] == 0) {
				dfs(x, y);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}

void dfs(int x, int y) {
	if (lettuce[y][x] == 0) return;
	lettuce[y][x] = 1; // 방문했음

	ifvisit(x-1, y);
}

void ifvisit(int x, int y) {

}