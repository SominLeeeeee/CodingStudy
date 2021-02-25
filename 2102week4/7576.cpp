#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> yx;
vector< vector<int> > tomato;
vector< vector<int> > day;
queue<yx> find_queue;

void bfs();
void find(int y, int x, int days);
void check(int y, int x, int days);

int main() {
    int N, M;   // N = x, M = y
    bool all = true;    // 다 익었는지 확인하는 변수  
    //int days = 0;
    
	cin >> N >> M;

    // tomato 벡터 입력받
    tomato.resize(M+2, vector<int>(N+2, -1));
	day.resize(M+2, vector<int>(N+2, -1));

    char temp;
    for (int y = 1; y <= M; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> tomato[y][x];
            if (tomato[y][x] == 1) {
				find_queue.push(make_pair(y, x)); // 모든 시작점을 큐에 넣는다
				tomato[y][x] = -1;
				day[y][x] = 1;
			} 
            else if (tomato[y][x] == 0) all = false;
        }
    }
	
	// 다 익었다면 0 출력 후 종료  
	if (all) {
		cout << 0;
		return 0;
	}

	bfs();

	int max = -1;
	for (int y = 1; y <= M; y++) {
		for (int x = 1; x <= N; x++) {
			if (tomato[y][x] == 0) {
				cout << -1 << endl;
				return 0;
			}
			
			max = day[y][x] > max ? day[y][x] : max;
		}
	}

	cout << max - 1 << endl;
}

/* TODO - bfs 메인 */
void bfs() {
	yx go;
	
	while (!find_queue.empty()) {
		go = find_queue.front();
		find_queue.pop();
		check(go.first, go.second, day[go.first][go.second]);	// 꺼낸 지점의 상하좌우 갈수 있나 검사하
	}
}

/* TODO - 갈 수 있는 곳인지 검사하고 갈 수 있다면 q에 추가하기 */
void find(int y, int x, int days) {
	if (tomato[y][x] != -1) {
		find_queue.push(make_pair(y, x));
		tomato[y][x] = -1;	// 방문했으니 다시는 갈 수 없다고 표시
		day[y][x] = days;
	}
}

/* 상하좌우 다 검사하기 */
void check(int y, int x, int days) {
	find(y-1, x, days+1);
	find(y+1, x, days+1);
	find(y, x-1, days+1);
	find(y, x+1, days+1);
}



