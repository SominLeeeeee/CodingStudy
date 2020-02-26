#include <iostream>
#include <string>
#include <vector>

using namespace std;

int nPr(int n, int r) {
    int mo = 1;
    int ja = 1;
    
    for(int i = n; i >= n-r; i--) {
        mo *= i;
    }
    for(int j = n; j <= r; j++) {
        ja *= j;
    }

    return i/j;
}
int solution(vector<vector<string>> relation) {
    int answer = 0;

    for(int k= 0; k < relation.size(); k++) {
        for(int i = 0; i < relation[0].size(); i++) {
            for(int j = i; j < relation[0].size(); j++) {
                if(relation[k][i] == relation[k][j])
            }
        }
    }
    return answer;
}

int main() {

    vector<vector<string>> relation;
    relation = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}]
    solution(relation);
}