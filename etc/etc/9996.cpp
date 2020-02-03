// https://acmicpc.net/problem/9996

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int NumCase;
	int i, j, eLen, pLen;
	bool result = false;

	cin >> NumCase;	// test ����

	string pattern;	// ����
	string example;	// �˻��� ���ϸ�

	cin >> pattern;	// ���� �Է¹���

	for (i = 0; i < NumCase; i++)
	{
		cin >> example;	// ���ϸ� �Է¹���

		pLen = pattern.length();	// ���� ����
		eLen = example.length();	// ���ϸ� ����

		if (eLen < pLen - 1) {
			cout << "NE" << endl;
			continue;
		}

		for (j = 0; pattern[j] != '*' && j < eLen; j++) {	// ó������ �����ؼ� *�� ������ ������ ������ �˻�
			if (pattern[j] != example[j]) {break;}
			if (pattern[j + 1] == '*') result = true;
		}

		for (j = 1; pattern[pLen - j] != '*' && j < eLen; j++) {	// �ڿ������� �����ؼ� *�� ������ ������ ������ �˻�
			if (example[eLen - j] != pattern[pLen - j]) break;
			if (pattern[pLen - j - 1] == '*') result = true;
		}

		if (result == true) cout << "DA" << endl;
		else cout << "NE" << endl;
	}
}