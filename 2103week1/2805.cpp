#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree;
int N, M;
bool cut_length(int height);

int main() {
    cin >> N >> M;
    tree.resize(N);

    int start = 0;
    int end = 0;
    int height;
    int result = 0;

    for(int i = 0; i < N; i++) {
        cin >> tree[i];
        if (tree[i] > end) end = tree[i];
    }

    //sort(tree.begin(), tree.end(), greater<>());

    while (start <= end) {
        height = (start + end) / 2;

        if (cut_length(height)) {
            if (result < height) result = height;
            start = height + 1;
        } else {
            end = height - 1;
        }
    }

    cout << result << endl;
    return 0;
}

bool cut_length(int height) {
    long sum = 0;

    for(int i = 0; i < N; i++) {
        if (tree[i] > height) sum += (tree[i] - height);
    }

    return sum >= M;
}