#include <iostream>
using namespace std;

int main() {
	int N, K;		
	cin >> N >> K;	// ������ ���� ����, ������ �ϴ� ��ġ

	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];	// ���� ���� �Է¹ޱ�
	}

	int money = 0;	// ���� �󸶱��� ���������
	int idx = N-1;	// arr ��� �ִ°� �����
	int cnt = 0;	// ���� � �ʿ�����
	while (money != K) {
		if (arr[idx] <= K - money) {
			money += arr[idx];
			cnt++;
		}
		else idx--;
	}

	cout << cnt;
	
}