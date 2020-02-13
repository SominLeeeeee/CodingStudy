#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

typedef pair<int, int> pint;
queue<pint> q;					// bfs에 사용할 큐
queue<pint> checked;			// 갔다온 곳
vector< vector<char> > castle;	// 성벽 배열
vector< vector<char> > lab;  	// 방 번호 나타내는 배열
vector< vector<int> > graph;	// 인접list 나타내기
int dir[4][2] = { {0,-1}, {-1,0}, {0,1}, {1,0} };	// direction

int bfs();	// area 값을 return
void pushVisit(char a, char b);
void label(int num);

int main() {
	int m, n;	// m이 가로 , n이 세로
	cin >> m >> n;
	int temp, area, num = 0, maxarea = 0;	// 방넓이, 방번호, 넓이최대값
	int maxsum = 0;							// 방 합친 값의 최대
	vector<int> areaArr;					// 방 번호 - 방 넓이 쌍

	castle.resize(n + 2);
	castle[0].resize(m + 2, 0);
	for (int i = 1; i <= n; i++) {
		castle[i].resize(m + 2, 0);
		for (int j = 1; j <= m; j++) {
			cin >> temp;
			castle[i][j] = temp;
		}
	}
	castle[n + 1].resize(m + 2, 0);
	// n+2*m+2 짜리 벡터 castle을 만든다

	lab.resize(n + 2);
	for (int i = 0; i < n + 2; i++) {
		lab[i].resize(m + 2);
	}	// 방 label 표시할 벡터 초기화

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			if (!(castle[y][x] >> 4 & 1)) {	// 안 가본 곳인가?
				q.push(make_pair(y, x));	// 그렇다면 시작점으로 넣는다
				castle[y][x] = castle[y][x] | 16;	// 5번째 bit에 갔다고(1) 표시
				area = bfs();						// y,x에서 갈수 있는 곳까지 bfs 실행
				maxarea = (maxarea > area) ? maxarea : area;	// 넓이 최대값 업데이트
				num++;								// 방 번호 카운트
				areaArr.resize(num + 1);
				areaArr[num] = area;				// 넓이 저장해두는 배열에 넓이 저장하기
				label(num);							// 방 번호 써두기
			}
		}
	}

#if 0
	5 3
		15 7 11 2 14
		3 0 14 5 15
		9 12 11 8 14

#endif
		for (int i = 1; i < num; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				temp = areaArr[i] + areaArr[graph[i][j]];	// 예를들어 1번방과 2번방이 인접했다면 1번방 넓이 + 2번방 넓이를 하는것
				maxsum = (temp > maxsum) ? temp : maxsum;	// 그게 maxsum보다 크다면 업데이트한다
			}
		}

	cout << num << endl;
	cout << maxarea << endl;
	cout << maxsum << endl;
}

int bfs() {
	pint temp;
	char byuk;
	int nextx, nexty, area = 0;

	while (!q.empty()) {
		temp = q.front();	// q의 첫번째꺼 임시 저장
		q.pop();			// q의 첫번째 제거
		checked.push(temp);	// 방문한거 체크하는 큐에 넣는다 (나중에 인접list 만들때 쓸거임)
		area++;				// 넓이 재기
		byuk = castle[temp.first][temp.second]; // 벽위치가 표시되어있다!

		for (int i = 0; i <= 3; i++) {
			if (!((byuk >> i) & 1)) {			// 만약 (남동북서)벽이 뚫려있다면
				nexty = temp.first + dir[i][0];	// 북쪽 벽이 뚫려있으면 북쪽 방을 탐색하도록 하자
				nextx = temp.second + dir[i][1];
				if ((castle[nexty][nextx] >> 4) & 1) continue;
				castle[nexty][nextx] = castle[nexty][nextx] | (int)pow(2, ((i + 2) % 4));
				// 내가 온 벽은 막아버림
				// 그 전의 칸이 왼쪽이 비어서 내(next)게 온거라면 오른쪽 벽을 막는다!
				pushVisit(nexty, nextx);
			}
		}
	}

	return area;
}

void pushVisit(char y, char x) {
	// 좌표 y,x가 갈수 있는 곳이라면
	castle[y][x] = castle[y][x] | 16;	// 5번째 bit에 들렸다고 표시해둔다
	q.push(make_pair(y, x));			// (y,x)를 q에 넣는다
}

void label(int num) {
	graph.resize(num + 1);
	pint temp;
	while (!checked.empty()) {
		temp = checked.front();

		checked.pop();
		lab[temp.first][temp.second] = num;

		for (int i = 0; i < 4; i++) {
			if (lab[temp.first + dir[i][0]][temp.second + dir[i][1]] > 0 &&
				lab[temp.first + dir[i][0]][temp.second + dir[i][1]] < num) {				// 인접 칸이 경계(0)도 아니고 나랑 같은 방도 아니라면 
				graph[num].push_back(lab[temp.first + dir[i][0]][temp.second + dir[i][1]]);	// 인접한 방의 번호를 인접list에 추가
				graph[lab[temp.first + dir[i][0]][temp.second + dir[i][1]]].push_back(num); // 거꾸로도 인접 list에 추가
			}
		}

	}
}