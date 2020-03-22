// https://acmicpc.net/problem/2579

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> grade;
vector<int> best;

int main() {
	int n;	// ����� ����
	cin >> n;

	grade.resize(n);	// grade[idx]�� idx��° ����� ����
	best.resize(n);		// best[idx]�� idx��° ��ܱ��� ���� �ִ� ����

	int i;
	for (i = 0; i < n; i++) {
		cin >> grade[i];
	}

	best[0] = grade[0];										// 0��° ��ܱ��� �ִ�� �׳� 0�� ��°� �ۿ� ����
	best[1] = max(grade[0] + grade[1], grade[1]);			// 1��° ����� 0-1 Ȥ�� �ٷ� 1�� �� ���
	best[2] = max(grade[0] + grade[2], grade[1] + grade[2]);// 2��° ����� 1-2 Ȥ�� 0-2

	/*
	��ȭ�Ŀ� ���� ����
	  ++���� ~ �������� �� ����
		������-1 ����� ���� ��� ���� ~ ������-3 ~ ������-1 ~ ������
		������-2 ����� ���� ��� ���� ~ ������-2 ~ ������ �̴�.
		���� ���ӵ� ����� ������ �ȵǱ� �����̴�!

	  ++���� ��ȭ����
		best[dst] = max(best[dst-3] + grade[dst-1] + grade[dst], 
						best[dst-2] + grade[dst] �̴�.
		
	  ++dst-3�� �����Ҷ� ������ ���� �ȵǹǷ� dst�� �ּ� 3 �̻���ͷ� �ؾ��Ѵ�
	*/

	int dst;
	for (dst = 3; dst < n; dst++) {	// �츮�� best[n-1]�� ���ؾ� �Ѵ�
		best[dst] = max(best[dst - 3] + grade[dst - 1] + grade[dst],
						best[dst - 2] + grade[dst]);
	}

	cout << best[n-1] << endl;
}