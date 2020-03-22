// https://acmicpc.net/problem/6603

#include <iostream>
#include <vector>
using namespace std;

#define MAX 6

vector<int> set;
vector<int> result;
void dfs(int idx, int depth);

int main() {
    int a;
    
    while(cin >> a && a != 0) {
        set.resize(a);
        for(int i = 0; i < a; i++) {
            cin >> set[i]; 
        }

        for(int i = 0; i<=set.size() - MAX; i++) {
            dfs(i, 1);
            result.pop_back();
        }

        cout << endl;
    }

    return 0;
}

void dfs(int start, int depth) {
    result.push_back(set[start]);

    if(depth == MAX) {
        for(int i = 0; i<result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    else {
        for(int n = start+1; n != set.size(); n++) {
            dfs(n, depth+1);
            result.pop_back();
        }
        
    }
}