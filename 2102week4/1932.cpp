#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
    return a < b ? b : a;
}

int main() {

    int size;   // triangle size
    cin >> size;

    // enter triangle
    vector< vector<int> > triangle;
    triangle.resize(size);

    for (int i = 0; i < size; i++) {
        triangle[i].resize(i+1);

        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    // make sum triangle
    for (int i = 1; i < size; i++) {
        triangle[i][0] += triangle[i-1][0];
        triangle[i][i] += triangle[i-1][i-1];   // both end

        for (int j = 1; j < i; j++) {
            triangle[i][j] = max(
                triangle[i][j] + triangle[i-1][j], 
                triangle[i][j] + triangle[i-1][j-1]
            );
        }
    }

    // decide max of triangle
    int max = 0;
    for(int i = 0; i < size; i++) {
        max = max < triangle[size-1][i] ? triangle[size-1][i] : max;
    }

    cout << max;
    
    return 0;
}