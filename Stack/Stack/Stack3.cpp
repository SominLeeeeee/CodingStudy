// https://acmicpc.net/problem/9012

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int T; // test case
	cin >> T;

	for (int i = 0; i < T; i++) { // test case 개수만큼 실행
		string garo;		// 괄호를 입력받는 문자열
		stack<char> open;	// 여는 괄호 넣을 스택
		bool result = true; // 결과괎

		cin >> garo; // 문자열 입력받고

		for (int x = 0; x < garo.length(); x++) {
			if(garo[x] == '(') open.push(garo[x]);				// (라면 open 스택에
			else {												// )가 나왔는데
				if (open.empty()) { result = false; break; }	// 스택이 비어있으면 틀린것(짝이 없는거임)
				open.pop();										// 안 비어있으면 빼내기
			}
		}

		if (!open.empty()) {// 문자열 검사 다 끝났는데 안 비었으면 틀린것(짝이 안맞는거임)
			result = false;
		}

		if (result == true) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}