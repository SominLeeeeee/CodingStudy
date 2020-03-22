// https://acmicpc.net/problem/11866

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k; // 사람수 n, k번째 사람 뺀다
	cin >> n >> k;
	queue<int> result;
	queue<int> circle;

	for (int i = 1; i <= n; i++) {
		circle.push(i);
	}

	while (!circle.empty()) {
		for (int i = 1; i <= k-1; i++) {
			circle.push(circle.front());
			circle.pop();
		} // k-1명 마지막에 넣고 뺀다 (head를 움직이는 느낌)
		result.push(circle.front()); // k번째 사람을 결과값에 추가하고
		circle.pop(); // 없앤다..
	}

	cout << "<";
	while (!result.empty()) {
		cout << result.front() << ", ";
		result.pop();
	}
	cout << "\b\b" << ">";
}