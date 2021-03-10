#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< vector<bool> > vec_connected;
queue<int> to_visit;
vector<bool> visited;

void push_visit(int a);
void dfs();

int main() {
    int computer;
    int connect;

    cin >> computer;
    cin >> connect;

    vec_connected.resize(computer+1, vector<bool>(computer+1, false));
    visited.resize(computer+1);

    int com1, com2;
    for (int i = 0; i < connect; i++) {
        cin >> com1 >> com2;
        vec_connected[com1][com2] = true;
        vec_connected[com2][com1] = true;
    }

    push_visit(1);  // start
    dfs();

    int result = 0;
    for (int i = 1; i <= computer; i++) {
        if (visited[i]) result++;
    }

    cout << result - 1;   // result - 1(start)
}

void push_visit(int a) {
    to_visit.push(a);
    visited[a] = true;
}

void dfs() {
    int tmp;
    while(!to_visit.empty()) {
        tmp = to_visit.front();
        to_visit.pop();

        for (int i = 1; i < vec_connected[tmp].size(); i++) {
            if (vec_connected[tmp][i] && !visited[i]) push_visit(i);
        }
    }
}