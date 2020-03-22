// https://acmicpc.net/problem/1874

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n; // �Է��� ���� ��������

	int* suyeol = new int[n];	// ������ �迭�� ������
	stack<int> s;				// ����
	string result = "";			// �����

	for (int i = 0; i < n; i++) {
		cin >> suyeol[i];
	}							// ���� �Է¹���

	int curr = 1;
	int idx = 0;

	while(curr <= n) {			// 1���� n������ ���ÿ� ������ ����
		s.push(curr);			// �ϴ� ����
		result.append("+\n");	// �־����ϱ� ������� +�� ������
		curr++;					// �־����ϱ� curr�� ++

		while (!s.empty() && s.top() == suyeol[idx]) {	// ������ �� �����̶� ���ٸ�
			s.pop();						// pop
			result.append("-\n");			// pop�����ϱ� ����� -�� ������
			idx++;							// idx���� ��������� ������ �� Ȯ��
		}
	}

	if (!s.empty()) cout << "NO" << endl;	// n���� ���ÿ� �ٳְ� �E�� �Q�µ� �� ��������� Ʋ������
	else cout << result;					// push�� pop�� ¦�� �� �¾�����(�������) ����� ���

	return 0;
}