// https://acmcicpc.net/problem/2583

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> p;
vector< vector<int> > vec;
vector<int> result; // 영역 넓이를 저장해둘 벡터
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
void dfs(p start);
int area = 0;

int main() {
    int M, N, K;    // 세로, 가로 직사각형 개수
    int num = 0;    // 나누어지는 영역의 개수를 셀 변수

    cin >> M >> N >> K;

    vec.resize(M+2);
    for(int i = 1; i<=M; i++) {
        vec[i].resize(N+2, 1);  // 직사각형을 0으로 채울 것이다
        vec[i][0] = 0;
        vec[i][N+1] = 0;
    }
    vec[0].resize(N+2, 0);
    vec[M+1].resize(N+2, 0);    // 테두리는 0으로 채우기

    int toX, toY;
    int fromX, fromY;

    for(int i = 0; i<K; i++) {
        cin >> fromX >> fromY >> toX >> toY;
        for(int y = fromY+1; y < toY+1; y++) {
            for(int x = fromX+1; x < toX+1; x++) {
                vec[y][x] = 0;
            }   // 직사각형 부위를 0으로
        }
    }

    for(int y = 1; y<=M; y++) {
        for(int x = 1; x<= N; x++) {    // vec 전체에서 시작점 찾기
            if(vec[y][x]) {             // 시작점이라면 (1이라면 // 1이 갈수 있는 곳)
                num++;                  // 나누어지는 영역 개수++
                vec[y][x] = 0;          // 방문 처리
                dfs(make_pair(y,x));    // 시작점부터 dfs 돌리기
                result.push_back(area); // 영역 넓이 결과벡터에 넣기
                area = 0;
            }
        }
    }

    sort(result.begin(), result.end());
    
    cout << num << endl;
    for(int i = 0; i<result.size(); i++) {
        cout << result[i] << " ";
    }

}

void dfs(p start) {
    area++;
    int nexty, nextx;
    for(int i = 0; i<4; i++) {
        nexty = start.first + dir[i][0];
        nextx = start.second + dir[i][1];
        if(vec[nexty][nextx]) { // 갈 수 있는곳(1)이라면
            vec[nexty][nextx] = 0;
            dfs(make_pair(nexty, nextx));
        }   
    }
}

