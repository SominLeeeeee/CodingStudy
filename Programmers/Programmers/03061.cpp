#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool incl(char ch, string skill) {
    // ch가 skill에 포함되는지 확인해볼 것이다
    auto it = skill.begin();

    for(; it != skill.end(); it++) {
        if(ch == *it) return true;
    }   // skill에 포함된다면 true를 반환한다

    return false;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    queue<char> sk; // skill의 큐
    queue<char> st; // skill_tree의 큐

    for(int i = 0; i < skill_trees.size(); i++) {
        cout << "i is " << i << endl;

        auto it = skill.begin();
        for(it = skill.begin(); it != skill.end(); it++) {
            sk.push(*it);
        }   // skill에 있는 것들을 큐에 넣어준다
            // 이따 뺄것이기 때문에 skilltree 하나 검사할때마다 새로 큐에 넣어주었다

        for(int j = 0; j < skill_trees[i].size(); j++) {
            if(incl(skill_trees[i][j], skill)) {
                st.push(skill_trees[i][j]); // skill_tree에 있고 skill에도 포함된것
            }
        }

        //skilltree 큐에 들어있는 순서가 skill 큐에 들어있는 순서와 똑같은지 확인하자
        answer++;
        while(!st.empty()) {
            if(st.front() == sk.front()) {
                st.pop();
                sk.pop();
            } else {  // 순서가 다른게 나온다면 answer가 될수없음
                answer--;
                break;
            }
        }

        // sk와 st 큐는 비워두기
        while(!sk.empty()) { sk.pop(); }    
        while(!st.empty()) { st.pop(); }
    }

    return answer;
}

int main() {
    solution("CBD", {"BACDE", "CBADF", "AECB", "BDA"});
}