#include <iostream>
#include <vector>
using namespace std;

vector< vector<char> > board;
vector<bool> visited(27, false);
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int maxx = 0;

void dfs(int y, int x, int horse) {
    if (maxx < horse) maxx = horse;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i]; // next x
        int ny = y + dy[i]; // next y

        if (board[ny][nx] != 'a' && !visited[board[ny][nx] - 'A']) {
            visited[board[ny][nx] - 'A'] = true;
            dfs(ny, nx, horse+1);
            visited[board[ny][nx] - 'A'] = false;
        }            
    }
}

int main() {
    int R, C;
    cin >> R >> C;

    board.resize(R+2, vector<char>(C+2, 'a'));  // a인 경우 : 경계이므로 갈 수 없음

    for (int y = 1; y <= R; y++) {
        for (int x = 1; x <= C; x++) {
            cin >> board[y][x];
        }
    }

    visited[board[1][1] - 'A'] = true;
    dfs(1, 1, 1);
    
    cout << maxx << endl;
}