// https://acmicpc.net/problem/6549

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	while(true) { // 0 �Է¹��� ������ �׽�Ʈ ��� �ؾ��Ѵ�
	
		int n; // ���簢���� ����
		int temp;
		long long max = 0, area;
		cin >> n;
		if (n == 0) return 0; // 0 �Է¹����� ���α׷� ����

		vector<long long> h; // ���簢���� ���� �����ϴ� ����
		stack<int> remain;	// �����ִ� ���簢�� ���°���� �����ϴ� ����

		for (int i = 0; i < n; i++) {
			cin >> temp;
			h.push_back(temp); // i��° ���簢�� ���� �Է¹ޱ�
		}
		h.push_back(0); // �������� ���� ���� ���簢���� �־��ش�

		for (int i = 0; i < h.size(); i++) {
			while (!remain.empty() && h[remain.top()] >= h[i]) { // ���� ������ >=�� �ְ� �ִٸ�
				temp = remain.top();
				remain.pop(); // ������. 
							// �̶� ���� ���� left�� ���� �ִ� top�̰�, right�� ����!

				if (remain.empty()) { // ���� �� ���ʿ� �ƹ� ���ڵ� ���ٸ�?
					area = i * h[temp];
					max = (area > max) ? area : max;
				}

				else { // �� ���ʿ� ���� �ִ� == ���� ���� ���� �ְ� �ƴ϶��
					area = (i - remain.top() - 1) * h[temp]; // ���� = (right(��) - left(top) - 1) * h[������]
					max = (area > max) ? area : max; // ���̰� �ִ��̸� �������ش�
				}
			} // ������� ������ ������ ���ų� ū ���ڴ� �� ������ ���̴�

			remain.push(i); // ���� ���� �ִ´�!
		}

		cout << max << endl;
	}


}

