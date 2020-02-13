// https://acmicpc.net/problem/1966

#include <queue>
#include <iostream>
#include <utility>
using namespace std;

typedef pair<int, int> p;

int main() {
	int T;					// test case
	int N, M;				// ���� ����, ���° ����?
	int temp;
	int arr[11] = { 0 };	// �߿䵵�� idx�� ������ � ���Ҵ°�?
	int max = 0;			// ���� ���� �߿䵵 ū�� ���ΰ�?

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		int result = 1;			// ���°���� ���� ���� �����
		queue<p> priority;		// (������ȣ, �߿䵵)�� �����ص� ť

		for (int j = 0; j < N; j++) {
			cin >> temp;
			priority.push(make_pair(j, temp));	// (������ȣ, �߿䵵)
			max = max > temp ? max : temp;		// �߿䵵 max�� ������Ʈ
		}

		p now;
		while (true) {
			if (priority.front().second == max) {	// ���� �߿䵵�� ���� ���ٸ�
				now = priority.front();
				arr[now.second]--;					// �� �߿䵵�� ���� ���� ���� -1
				result++;							// result++
				if (now.first == M) break;			// ���� M��° ������� while�� Ż��
				priority.pop();						// ���� ��µȴ�!
				while (arr[max] == 0) {		// �� ���� �߿䵵�� ã�� ������
					max--;					// max���� �ٿ�����
				}
			}

			else {	// ������ �߿��� �ְ� �ִٸ�
				priority.push(priority.front());	// ���� �� �ڷ� ����
				priority.pop();
			}
		}

		cout << result << endl;
	}
}