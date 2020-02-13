// https://acmicpc.net/problem/9996

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int NumCase;
	int i, j, eLen, pLen;

	cin >> NumCase;	// test 개수

	string pattern;	// 패턴
	string example;	// 검사할 파일명

	cin >> pattern;	// 패턴 입력받음

	for (i = 0; i < NumCase; i++)
	{
		cin >> example;	// 파일명 입력받음

		pLen = pattern.length();	// 패턴 길이
		eLen = example.length();	// 파일명 길이

		bool result1 = false;
		bool result2 = false;

		if (eLen < pLen - 1) {
			cout << "NE" << endl;
			continue;
		}

		for (j = 0; pattern[j] != '*' && j < eLen; j++) {	// 처음에서 시작해서 *이 나오기 전까지 같은지 검사
			if (pattern[j] != example[j]) {break;}
			if (pattern[j + 1] == '*') result1 = true;
		}

		for (j = 1; pattern[pLen - j] != '*' && j < eLen; j++) {	// 뒤에서부터 시작해서 *이 나오기 전까지 같은지 검사
			if (example[eLen - j] != pattern[pLen - j]) break;
			if (pattern[pLen - j - 1] == '*') result2 = true;
		}

		if (result1 && result2) cout << "DA" << endl;
		else cout << "NE" << endl;
	}
}