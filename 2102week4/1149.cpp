#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int house;  // house num
    vector< vector<int> > rgb;

    cin >> house;
    rgb.resize(house, vector<int>(3, 0));
    // rgb size => (house, 3)

    // enter rgb vector & make sum rgb
    for (int i = 0; i < 3; i++) {
        cin >> rgb[0][i];
    }

    for (int i = 1; i < house; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> rgb[i][j];
            rgb[i][j] += min(rgb[i-1][(j+1)%3], rgb[i-1][(j+2)%3]);
        }
    }

    // print min
    int min = rgb[house-1][0];
    for(int i = 0; i < 3; i++) 
        min = min < rgb[house-1][i] ? min : rgb[house-1][i];
    
    cout << min;

    return 0;
}