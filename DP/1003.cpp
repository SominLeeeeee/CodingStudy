// https://acmicpc.net/problem/1003
#include <iostream>
#include <vector>
#include <utility>  // pair를 쓰기 위해서
using namespace std;

int main() {
    vector< pair<int, int> > vec;    // first는 0갯수, second는 1갯수
    vec.resize(40);

    int T;  // test case
    cin >> T;

    vec[0] = make_pair(1,0);  // 0이 1개, 1이 0개
    vec[1] = make_pair(0,1);  // 0이 0개, 1이 1개
    
    auto it = vec.begin()+2;   // it는 아직 결과가 안나온 곳을 가리킬 것이다

    for(int i = 0; i < T; i++) {
        int N;
        cin >> N;

        for(; it <= vec.begin()+N; it++) { // 결과가 없는 곳부터 N까지만 계산하자
            it->first = (it-2)->first + (it-1)->first;
            it->second = (it-2)->second + (it-1)->second;
        }   // 0의 개수와 1의 개수를 따로 계산하자 (n의 0개수 = n-2의 0개수 + n-1의 0개수)

        cout << vec[N].first << " " << vec[N].second << endl;
    }
}