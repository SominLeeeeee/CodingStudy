// https://www.acmicpc.net/problem/1931

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<unsigned int, unsigned int> time;	// first = begin & second = end
vector<time> t;					// time���� ������ ���� t
bool cmp(time temp1, time temp2);

int main() {
	int N;						// ȸ�ǰ� �����
	unsigned int begin, end;	// �Է¹�����
	int cnt=0, when=0;			// ȸ�� ������ ��, ȸ�� ��������
	cin >> N;

	t.resize(N);				// ȸ�� ������ŭ ũ�� �÷��ֱ�
	for (int i = 0; i < N; i++) {		
		cin >> begin >> end;
		t[i] = make_pair(begin, end);	// begin, end �����ϱ�
	}

	sort(t.begin(), t.end(), cmp);		// ����ð��� ���� ������ ����

	for (int i = 0; i < t.size(); i++) {
		if (when <= t[i].first) {		// ȸ�� ���������� ������������ ������
			when = t[i].second;			// �� ȸ�� ����(�������� ������Ʈ)
			cnt++;						// ������ ȸ�� �� ����
		}
	}

	cout << cnt;
	return 0;
}

bool cmp(time temp1, time temp2) {
	if (temp1.second == temp2.second)
		return temp1.first < temp2.first;	// ����ð��� ���ٸ� ������ ���� ��
	else
		return temp1.second < temp2.second;	// ���� ������ ���ᰡ ���� ��
}