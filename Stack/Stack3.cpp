// https://acmicpc.net/problem/9012

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int T; // test case
	cin >> T;

	for (int i = 0; i < T; i++) { // test case ������ŭ ����
		string garo;		// ��ȣ�� �Է¹޴� ���ڿ�
		stack<char> open;	// ���� ��ȣ ���� ����
		bool result = true; // �����

		cin >> garo; // ���ڿ� �Է¹ް�

		for (int x = 0; x < garo.length(); x++) {
			if(garo[x] == '(') open.push(garo[x]);				// (��� open ���ÿ�
			else {												// )�� ���Դµ�
				if (open.empty()) { result = false; break; }	// ������ ��������� Ʋ����(¦�� ���°���)
				open.pop();										// �� ��������� ������
			}
		}

		if (!open.empty()) {// ���ڿ� �˻� �� �����µ� �� ������� Ʋ����(¦�� �ȸ´°���)
			result = false;
		}

		if (result == true) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}