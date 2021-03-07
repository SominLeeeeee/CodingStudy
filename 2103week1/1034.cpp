#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int K, N, M;
int max_count;
vector< vector<int> > lamp;

int possible(int row);
int switch_on(queue<int> q);
int count_on(vector< vector<int> > vec);

int main() {
    cin >> N >> M;

    lamp.resize(N, vector<int>(M+1, 0));
    string str;
    int count_zero;

    for(int i = 0; i < N; i++) {
        cin >> str;

        for(int j = 0; j < M; j++) {
            lamp[i][j]  = str[j] - '0';
            if (str[j] == '0') lamp[i][M]++;
        }
    }

    cin >> K;

    max_count = 0;
    int temp = 0;

    for(int i = 0; i < N; i++) {
        temp = possible(i);
        max_count = max_count < temp ? temp : max_count;
    }

    cout << max_count << "\n";
    return 0;
}

int possible(int row) {
    int result = -1;
    queue<int> zero_location;

    if ( lamp[row][M] <= K && (K - lamp[row][M]) % 2 == 0 ) {  // lamp[row] -> all on possible
        for (int i = 0; i < M; i++) {
            if (lamp[row][i] == 0) zero_location.push(i);
        }

        result = switch_on(zero_location);
    }

    return result;
}

int switch_on(queue<int> q) {
    // lamp[x][q front] -> 1 or 0
    vector< vector<int> > copy = lamp;
    int q_front;
    
    while (!q.empty()) {
        q_front = q.front();
        q.pop();

        for(int i = 0; i < N; i++) {
            copy[i][q_front] = (copy[i][q_front] == 0 ? 1 : 0);
        }
    }

    return count_on(copy);
}

int count_on(vector< vector<int> > vec) {
    // if lamp[i] all on -> cnt ++
    int cnt = 0;
    bool check;

    for(int i = 0; i < N; i++) {
        check = true;

        for(int j = 0; j < M; j++) {
            if (vec[i][j] == 0) {
                check = false;
                break;
            }
        }

        if (check) cnt++;
    }

    return cnt;
}