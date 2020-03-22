// https://acmicpc.net/problem/11052

#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}	// �̰� �ϳ� ���ڰ� algorithm include�ϱ� �Ⱦ���!

int main() {
	int N;		// ī�带 ���� ����ϴ���
	cin >> N;

	vector<int> price;		// ī�� ��� �� ������ �����ص� price ����
	price.resize(N + 1, 0);	// idx�� �ͼ��ϰ�? �������� N������� �ְ� �Ѵ�
	for (int i = 1; i <= N; i++) {
		cin >> price[i];	// 1�� ���� N�� ����, 0������ �Ⱦ��°�
	}

	vector<int> best;
	best.resize(N + 1, 0);	// �� �� ������ �ִ� ���� ������ ������ best ����, 0���� �ʱ�ȭ

	for (int i = 1; i <= N; i++) {
		for (int j = i; j > 0; j--) {
			best[i] = max(best[i], best[i - j] + price[j]);
		}	// best[i] = max(best[i], best[0]+price[i]	
			//						best[1]+price[i-1]
			//						best[2]+price[i-2]
			//							.......
			//						best[i-1]+price[1])
	}

	cout << best[N] << endl;
}