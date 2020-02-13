// https://acmicpc.net/problem/2667

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;
queue<p> bfsq;				// bfs를 위한 queue
vector< vector<char> > map;	// 지도
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

int bfs();		// 마을에 있는 집의 개수 return

int main() {
	int N, house;
	cin >> N;					// 지도의 크기 N*N
	vector<int> result;			// 집의 수를 저장해두는 벡터

	map.resize(N + 2);

	map[0].resize(N + 2, 48);	// 첫 줄 초기화
	for (int i = 1; i < N + 1; i++) {	// 그다음부턴 입력받기
		map[i].resize(N + 2, 48);
		for (int j = 1; j < N + 1; j++) {
			cin >> map[i][j];
		}
	}
	map[N + 1].resize(N + 2, 48);
	// N+2 * N+2 크기 지도 초기화

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (map[y][x] == 49) {			// 시작점
				map[y][x] = 48;				// 0은 이제 갈수 없음을 의미 (방문했음 처리)
				bfsq.push(make_pair(x, y));	// 시작점을 q에 넣는다
				house = bfs();
				result.push_back(house);	// 집의 수를 결과 벡터에 집어넣음
			}
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	
}

int bfs() {
	p temp;
	int num = 0;		// 집의 수를 셀 변수
	int nexty, nextx;	// 새로 넣을 좌표 y,x

	while (!bfsq.empty()) {
		temp = bfsq.front();
		bfsq.pop();
		num++;
		for (int i = 0; i < 4; i++) {
			nexty = temp.second + dir[i][0];
			nextx = temp.first + dir[i][1];
			if (map[nexty][nextx] == 49) {			// 갈 수 있는 곳이라면
				bfsq.push(make_pair(nextx, nexty));	// 주변 점 q에 넣기
				map[nexty][nextx] = 48;				// 방문했음을 표시
			}
		}
	}
	return num;
}