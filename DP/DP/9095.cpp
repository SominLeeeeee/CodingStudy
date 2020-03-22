#include <iostream>
using namespace std;

int main() {
    int T;  // test case
    cin >> T;

    int result[11] = {0, 1, 2, 4}; // 1,2,3까지는 미리 채워두기

    for(int i = 0; i < T; i++) {
        int n;
        cin >> n;

        for(int j = 4; j <= n; j++) {
            result[j] = result[j-3]+result[j-2]+result[j-1];
        }   // j-3을 더했던 방법에 3을 붙이면 되고
            // j-2를 더했던 방법에 2을 붙이면 되고
            // j-1을 더했던 방법에 1을 붙이면 된다
            // 그러니까 앞에 세개 방법을 다 더하면 된다!

        cout << result[n] << endl;
    }
}