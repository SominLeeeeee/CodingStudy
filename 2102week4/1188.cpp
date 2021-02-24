#include <iostream>
using namespace std;

int LCM(int n, int m) {
    int result = 1; // n*m is always common multiple

    for (int sum=n; sum != n*m; sum += n) {
        if(sum % m == 0) result++;
    }

    return result;
}

int main() {
    int N, M;
    cin >> N >> M;

    cout << M - LCM(N, M);
    return 0;
}