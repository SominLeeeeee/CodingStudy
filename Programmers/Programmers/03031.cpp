#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.resize(prices.size(), -1);
    int cnt = 0;
    int i, j;

    prices.push_back(0);
    for(i = 0; i < prices.size()-1; i++) {
        for(j = i+1; j < prices.size() && prices[i] <= prices[j]; j++) { }
        
        if(j == prices.size()-1) answer[i] = j-i-1;
        else answer[i] = j-i;
    }

    return answer;
}

int main() {
    solution({1,2,3,2,3});
}