// https://acmicpc.net/problem/1874

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n; // 입력할 수열 몇줄인지

	int* suyeol = new int[n];	// 수열을 배열로 만들어둠
	stack<int> s;				// 스택
	string result = "";			// 결과값

	for (int i = 0; i < n; i++) {
		cin >> suyeol[i];
	}							// 수열 입력받음

	int curr = 1;
	int idx = 0;

	while(curr <= n) {			// 1부터 n까지만 스택에 넣을수 있음
		s.push(curr);			// 일단 넣음
		result.append("+\n");	// 넣었으니까 결과값에 +를 더해줌
		curr++;					// 넣었으니까 curr도 ++

		while (!s.empty() && s.top() == suyeol[idx]) {	// 만들어야 할 수열이랑 같다면
			s.pop();						// pop
			result.append("-\n");			// pop했으니까 결과에 -를 더해줌
			idx++;							// idx번방 출력했으니 다음번 방 확인
		}
	}

	if (!s.empty()) cout << "NO" << endl;	// n까지 스택에 다넣고 뺼거 뻈는데 안 비어있으면 틀린거임
	else cout << result;					// push랑 pop이 짝이 잘 맞았으면(비었으면) 결과값 출력

	return 0;
}