//https://acmicpc.net/problem/12100

#include <queue>
#include <iostream>
#include <vector>
using namespace std;

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

int N;
int wholeMax = 0;   // max_최종
int recursion(int depth, vector< vector<int> > temp) ;  // 재귀
void dir(int i, vector< vector<int> > &temp) ;   // 방향에 따라 다른거 실행

int main() {
    cin >> N;

    vector< vector<int> > vec;
    vec.resize(N+2);
    for(int i = 0; i < N+2; i++) {
        vec[i].resize(N+2, 0);
    }   // 2048 블록 만들기

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> vec[i][j];
        }
    }

    recursion(0, vec);
    cout << wholeMax << endl;
}

int recursion(int depth, vector< vector<int> > temp) {
    // vec랑 depth받아서 재귀 돌리기, depth가 5면 빠져나갈것
    if(depth == 5) {
        int max = 0;
        for(int i = 1; i <= N; i++ ) {
            for(int j = 1; j <= N; j++) {
                if(temp[i][j] > max) max = temp[i][j];
            }
        }
        
        wholeMax = (max > wholeMax) ? max : wholeMax;
        return 0;
    }   // depth가 5가 됐으면 가장 큰 수를 찾아서 return 한다

    for(int i = 1; i <= 4; i = i+1) {
        vector< vector<int> > cpy = temp;
        dir(i, cpy);
        recursion(depth+1, cpy)*0;
    }

    return 0;
}

void dir(int i, vector< vector<int> > &temp) {
    queue<int> que;

    if(i == LEFT) { 
        for(int y = 1; y <= N; y++) {
            for(int x = 1; x <= N; x++) {    // -> 방향으로 검사하기
                if(temp[y][x] != 0) {
                    que.push(temp[y][x]);    // q에 넣는다
                    temp[y][x] = 0;  // 이미 넣은것은 0으로 돌려둔다
                }
            }   // que에 넣는 과정이 끝난다

            for(int x = 1; x <= N && !que.empty(); x++) {
                temp[y][x] = que.front();
                que.pop();
                if(temp[y][x] == que.front() && !que.empty()) {  // 뒤에 수와 같다면 합쳐지기
                    que.pop();
                    temp[y][x] *= 2;
                }
            }   // 민 걸 다시 집어넣는다
        }
    }

    else if(i == RIGHT) {  
        for(int y = 1; y <= N; y++) {
            for(int x = N; x >= 1; x--) {    // <- 방향으로 검사하기
                if(temp[y][x] != 0) {
                    que.push(temp[y][x]);    // q에 넣는다
                    temp[y][x] = 0;  // 이미 q에 넣은것은 0으로 돌려둔다
                }
            }   // que에 넣는 과정이 끝난다

            for(int x = N; x >= 1 && !que.empty(); x--) {
                temp[y][x] = que.front();
                que.pop();
                if(temp[y][x] == que.front() && !que.empty()) {  // 뒤에 수와 같다면 합쳐지기
                    que.pop();
                    temp[y][x] *= 2;
                }
            }   // 민 걸 다시 집어넣는다
        }
    } 
    
    else if(i == UP) {   
        for(int x = 1; x <= N; x++) {
            for(int y = 1; y <= N; y++) {    // v 방향으로 검사하기
                if(temp[y][x] != 0) {
                    que.push(temp[y][x]);    // q에 넣는다
                    temp[y][x] = 0;  // 이미 q에 넣은것은 0으로 돌려둔다
                }
            }   // que에 넣는 과정이 끝난다

            for(int y = 1; y <= N && !que.empty(); y++) {
                temp[y][x] = que.front();
                que.pop();
                if(temp[y][x] == que.front() && !que.empty()) {  // 뒤에 수와 같다면 합쳐지기
                    que.pop();
                    temp[y][x] *= 2;
                }
            }   // 민 걸 다시 집어넣는다
        }
    } 
    
    else if(i == DOWN) {
        for(int x = 1; x <= N; x++) {
            for(int y = N; y >= 1; y--) {    // ^ 방향으로 검사하기
                if(temp[y][x] != 0) {
                    que.push(temp[y][x]);    // q에 넣는다
                    temp[y][x] = 0;  // 이미 q에 넣은것은 0으로 돌려둔다
                }
            }   // que에 넣는 과정이 끝난다

            for(int y = N; y >= 1 && !que.empty(); y--) {
                temp[y][x] = que.front();
                que.pop();
                if(temp[y][x] == que.front() && !que.empty()) {  // 뒤에 수와 같다면 합쳐지기
                    que.pop();
                    temp[y][x] *= 2;
                }
            }   // 민 걸 다시 집어넣는다
        }
    }
}
