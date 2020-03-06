#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <map>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int cnt = 0;

    stack<int> open, close;
    auto iter = arrangement.begin();
    vector<int> lazr;
    map<int, int> stick;

    cout << "cnt is " ;
    while(iter != arrangement.end()) {
        while(*iter == '(' && iter != arrangement.end()) {
            cout << cnt << " ";
            open.push(cnt);
            cnt++;
            iter++;
        }   // ( 일 동안 계속 넣는다

        lazr.push_back(cnt);    // )가 나오기 시작했다면 그곳이 레이저
        cout << cnt << " ";
        cnt++;

        while(*iter == ')' && iter != arrangement.end()) {
            cout << cnt << " ";
            stick.insert(make_pair(open.top(), cnt));
            open.pop();
            cnt++;
            iter++;
        }
    }

    cout << "lazr is ";
    for(int i = 0; i < lazr.size(); i++) {
        cout << lazr[i] << " ";
    }
    cout << endl;

    auto it1 = stick.begin();
    
    for(; it1 != stick.end(); it1++) {
        cnt = 1;
        for(auto it2 = lazr.begin(); it2 != lazr.end(); it2++) {
            if(*it2 > it1->first && *it2 < it1->second) {
                cnt++;
            }
        }
        answer += cnt;
    }
    answer -= lazr.size() * 2;

    cout << "answer is " << answer << endl;
    return answer;
}

int main() {
    solution("()(((()())(())()))(())");
}