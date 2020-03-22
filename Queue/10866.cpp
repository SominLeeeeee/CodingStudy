// https://acmicpc.net/problem/10866

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	int n; // 명령의 수
	string instruct;	// 명령
	int x;	// push일 경우 뭐 push할건지 받는다

	cin >> n;
	deque<int> deq;

	for (int i = 0; i < n; i++) {
		cin >> instruct;
		if (instruct.compare("push_back") == 0) {
			cin >> x;
			deq.push_back(x);
		}
		else if (instruct.compare("push_front") == 0) {
			cin >> x;
			deq.push_front(x);
		}
		else if (instruct.compare("pop_back") == 0) {
			if (deq.empty()) cout << "-1\n";
			else {
				cout << deq.back() << endl;
				deq.pop_back();
			}
		}
		else if (instruct.compare("pop_front") == 0) {
			if (deq.empty()) cout << "-1\n";
			else {
				cout << deq.front() << endl;
				deq.pop_front();
			}
		}
		else if (instruct.compare("size") == 0) {
			cout << deq.size() << endl;
		}
		else if (instruct.compare("empty") == 0) {
			cout << deq.empty() << endl;
		}
		else if (instruct.compare("front") == 0) {
			if (deq.empty()) cout << "-1\n";
			else cout << deq.front() << endl;
		}
		else if (instruct.compare("back") == 0) {
			if (deq.empty()) cout << "-1\n";
			else cout << deq.back() << endl;
		}
	}

	return 0;
}