#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    vector<long long> desc;
    queue<long long> q;
    int N;

    cin >> N;

    desc.resize(N+1, -1);
    long long new_desc;
    int idx;
    
    for(idx = 0; idx <= N && idx <= 9; idx++) {
        desc[idx] = idx;
        q.push(idx);
    }

    while (!q.empty()) {
        for(int i = 0; i <= 9; i++) {
            if (idx <= N && q.front() % 10 > i) {
                desc[idx] = q.front() * 10 + i;
                q.push(desc[idx]);
                idx++;
            } else break;
        }
        q.pop();
    }

    cout << desc[N] << endl;
}