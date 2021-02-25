#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
vector< vector<int> > sum_result;
vector< vector<bool> > check;

// num[k] + num[k+1] + ... + num[n]
int sum(int k, int n) {
    int result = 0;

    for(int i = k; i <= n; i++) {
        result += num[i];
    }

    return result;
}

int dp(int n, int m) {
    int k;  // k ~ n : m th group
    if (m == 0) return 0;
    if (n < 2 * m - 1) return -3276900;
    if (check[n][m]) return sum_result[n][m];

    //cout << "n is " << n << ", m is " << m << endl;
    //fflush(stdout);

    check[n][m] = true;
    sum_result[n][m] = dp(n-1, m);

    for(k = n; k >= m-1; k--) {
        sum_result[n][m] = max(dp(k-2, m-1) + sum(k, n), sum_result[n][m]);
    }

    return sum_result[n][m];
}

int main() {
    int N, M;   // N - number count, M - group count
    cin >> N >> M;

    num.resize(N+1);
    sum_result.resize(N+1, vector<int>(M+1, 0));
    check.resize(N+1, vector<bool>(M+1, false));

    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }

    dp(N, M);

    cout << sum_result[N][M];
    return 0;
}