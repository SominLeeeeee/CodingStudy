#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;   // 몇줄?

    vector<int> max(3,0);
    vector<int> min(3,0);
    vector<int> temp(3,0);
    vector<int> grade(3, 0);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> grade[j];
        }   // grade 입력받기(메모리 문제 떄문에 한줄씩만)

        temp[0] = *max_element(max.begin(), max.end() - 1) + grade[0];
        temp[1] = *max_element(max.begin(), max.end()) + grade[1];
        temp[2] = *max_element(max.begin() + 1, max.end()) + grade[2];
        max = temp;

        temp[0] = *min_element(min.begin(), min.end() - 1) + grade[0];
        temp[1] = *min_element(min.begin(), min.end()) + grade[1];
        temp[2] = *min_element(min.begin() + 1, min.end()) + grade[2];
        min = temp;

        // max와 min배열에 한줄씩 더해간다
        // 어떤걸 더하는가? -> 더할 수 있는 최대 or 최소 + grade
    }   

    cout << *max_element(max.begin(), max.end()) << " " << *min_element(min.begin(), min.end());

    return 0;

}