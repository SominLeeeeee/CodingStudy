#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string solution(string p);
bool alright(string p);
string func(string w);

int main() {
    solution("()))((()");
}

string solution(string p) {
    string answer = "";

    answer = func(p);
    return answer;
}

string func(string w) {

    if(!w.size()) return w; // 빈 문자열이라면 그냥 리턴한다

    int close=0, open=0;
    int i = 0;
    
    string u, v;


    while(1) {
        if(w[i] == '(') open++;
        else close++;

        i++;
        if(close == open) break;
    }

    // 현재 iter부터 그 뒤는 다 v이다
    u = w.substr(0string solution(string p) {
    string answer = "";

    answer = func(p);
    return answer;
}

string func(string w) {

    if(!w.size()) return w; // 빈 문자열이라면 그냥 리턴한다

    int close=0, open=0;
    int i = 0;
    
    string u, v;


    while(1) {
        if(w[i] == '(') open++;
        else close++;

        i++;
        if(close == open) break;
    }

    // 현재 iter부터 그 뒤는 다 v이다
    u = w.substr(0, i);  // 0부터 i까지 u
    v = w.substr(i, w.size()-i);  // i부터 끝까지 v

    v = func(v);    // v는 재귀함수로 돌린다

    string temp;
    string ans = "(";    // 틀린 u를 올바르게 고친 string

    // 이제 u가 올바른지 아닌지에 따라
    if(!alright(u)) { // 만약 u가 올바르지 않다면
        temp = u.substr(1, u.size()-2);    // u의 맨앞 맨끝 제거하고
        for(int i = 0; i < temp.size(); i++) {
            if(temp[i] == '(') ans += ")";
            else ans += "(";
        }   // 괄호를 뒤집어서 뒤에 붙인다
        ans += ")";
        w = ans + v;
    } else {
        w = u + v;
    }

    return w;
}

bool alright(string p) {
    if(p.front() == '(') return true;
    return false;
}

    v = func(v);    // v는 재귀함수로 돌린다

    string temp;
    string ans = "(";    // 틀린 u를 올바르게 고친 string

    // 이제 u가 올바른지 아닌지에 따라
    if(!alright(u)) { // 만약 u가 올바르지 않다면
        temp = u.substr(1, u.size()-2);    // u의 맨앞 맨끝 제거하고
        for(int i = 0; i < temp.size(); i++) {
            if(temp[i] == '(') ans += ")";
            else ans += "(";
        }   // 괄호를 뒤집어서 뒤에 붙인다
        ans += ")";
        w = ans + v;
    } else {
        w = u + v;
    }

    return w;
}

bool alright(string p) {
    if(p.front() == '(') return true;
    return false;
}
