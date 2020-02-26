#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> p;

vector< vector<int> > graph1;
vector< vector<int> > graph2;
int cache;
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int dfs1(p yx);
int dfs2(p yx);

int main() {
	int N;
	cin >> N;	// NxN grid

	char temp;

	graph1.resize(N+2);
	graph2.resize(N+2);
	for(int i = 0; i < N+2; i++) {
		graph1[i].resize(N+2);
		graph2[i].resize(N+2);
	}			// graph1, 2 할당

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cin >> temp;
			graph1[i][j] = graph2[i][j] = temp;	// 입력받은걸 알맞는 위치에 입력

			if(temp == 'G') graph2[i][j] = 'R';	// 색약한테는 G가 R로 보인다 치자
		}
	}

	int result1=0, result2=0;
	for(int y = 1; y <= N; y++) {
		for(int x = 1; x <= N; x++) {
				
			if(graph1[y][x] != 0) {	// 방문하지 않은 시작점이라면
				cache = graph1[y][x];
				graph1[y][x] = 0;
				dfs1(make_pair(y,x));	// 정상인 dfs
				result1++;
			}
			
			if(graph2[y][x] != 0) {	// 방문하지 않은 시작점이라면
				cache = graph2[y][x];
				graph2[y][x] = 0;
				dfs2(make_pair(y,x));	// 정상인 dfs
				result2++;
			}
		}
	}

	cout << result1 << " " << result2;
}	

int dfs1(p yx) {
	
	for(int i = 0; i < 4; i++) {
		int nexty = yx.first + dir[i][0];
		int nextx = yx.second + dir[i][1];
		if(graph1[nexty][nextx] == cache) {	// 색이 같다면
			graph1[nexty][nextx] = 0;
			dfs1(make_pair(nexty, nextx));
		}
	}

	return 0;
}

int dfs2(p yx) {

	for(int i = 0; i < 4; i++) {
		int nexty = yx.first + dir[i][0];
		int nextx = yx.second + dir[i][1];
		if(graph2[nexty][nextx] == cache) {	// 색이 같다면
			graph2[nexty][nextx] = 0; // 방문했음 처리
			dfs2(make_pair(nexty, nextx));
		}
	}

	return 0;
}
	
