#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A;

int binary_search(int high, int key);

int main() {

    int N, M;

    scanf("%d", &N);
    A.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    sort(A.begin(), A.end());

    scanf("%d", &M);
    int temp;

    for(int i = 0; i < M; i++) {
        scanf("%d", &temp);
        printf("%d\n", binary_search(N-1, temp));
    }
}

int binary_search(int high, int key) {
    int low = 0;
    //int high = A.size()-1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (A[mid] == key) {
            return 1;
        } else if (A[mid] > key) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return 0;
}