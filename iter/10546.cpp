// https://www.acmicpc.net/problem/10546
#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;   // 참가자 수

    map<string, int> maraton;
    for(int i = 0; i < 2 * N - 1; i++) {
        string s;
        cin >> s;

        maraton[s]++;   // map은 할당할 때 다 0으로 초기화된다
    }

    auto iter = maraton.begin();
    for(; iter != maraton.end(); iter++) {
        if((iter->second) % 2) {    // 나머지가 있다==홀수라는 뜻
            cout << iter->first << endl;
        }
    }
}