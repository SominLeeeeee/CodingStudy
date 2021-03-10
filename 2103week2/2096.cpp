#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;

    vector<int> maximum(3,0);
    vector<int> minimum(3,0);
    vector<int> tempvec(3);
    vector<int> input(3,0);

    cin >> N;

    int tmp;

    // 맨 처음 세개 받은걸 max, min 벡터에 넣어주기ㄴ
    for(int i = 0; i < 3; i++) {
        cin >> tmp;
        maximum[i] = minimum[i] = tmp;
    }

    for(int i = 0; i < N-1; i++) {
        // 숫자 세개 씩 입력받고
        for (int j = 0; j < 3; j++) {
            cin >> input[j];
        }

        // 최대 최소 더하면서 value 갱신하기
        tempvec[0] = input[0] + max(maximum[0], maximum[1]);
        tempvec[1] = input[1] + *max_element( maximum.begin(), maximum.end() );
        tempvec[2] = input[2] + max(maximum[2], maximum[1]);
        maximum = tempvec;

        tempvec[0] = input[0] + min(minimum[0], minimum[1]);
        tempvec[1] = input[1] + *min_element( minimum.begin(), minimum.end() );
        tempvec[2] = input[2] + min(minimum[2], minimum[1]);
        minimum = tempvec;
    }

    cout << *max_element(maximum.begin(), maximum.end()) << " ";
    cout << *min_element(minimum.begin(), minimum.end());
}