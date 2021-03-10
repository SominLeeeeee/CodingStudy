#include <vector>
#include <string>
#include <iostream>
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;

    vector< vector<int> > lcs;

    // 입력받은 두 문자열 크기 + 1만큼 2차원 벡터 만들기
    lcs.resize(str2.size() + 1, vector<int>(str1.size() + 1, 0));
    
    for (int y = 1; y <= str2.size(); y++ ) {
        for (int x = 1; x <= str1.size(); x++) {
            // lcs[y][x]의 value를 채울 것인데
            // str2의 y번째 문자와 str1의 x번째 문자가 같은지 검사
            // lcs index 1부터 시작했으니 주의
            if (str1[x-1] == str2[y-1]) lcs[y][x] = lcs[y-1][x-1] + 1;
            else lcs[y][x] = max(lcs[y][x-1], lcs[y-1][x]);
        }
    }

    cout << lcs[str2.size()][str1.size()] << endl;
}