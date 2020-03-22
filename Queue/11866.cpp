// https://acmicpc.net/problem/11866

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k; // ����� n, k��° ��� ����
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
		} // k-1�� �������� �ְ� ���� (head�� �����̴� ����)
		result.push(circle.front()); // k��° ����� ������� �߰��ϰ�
		circle.pop(); // ���ش�..
	}

	cout << "<";
	while (!result.empty()) {
		cout << result.front() << ", ";
		result.pop();
	}
	cout << "\b\b" << ">";
}