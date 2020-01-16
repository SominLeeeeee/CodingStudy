/*
���� node : n
���� �ڽ� : 2n
������ �ڽ� : 2n+1
�θ� : n/2

ó�� ������ ���Ǹ� ���� 0�� �ƴ� 1�� �Ѵ�
*/

#pragma once
#include <vector>
using namespace std;

class Heap {
public:
	vector<int> v;

	void swap(int indexa, int indexb) {
		int temp;
		temp = v[indexa];
		v[indexa] = v[indexb];
		v[indexb] = temp;
	}

	void makeHeap() {
		v.push_back(0);
	}

	bool isLeaf(int n) {
		bool result = false;
		if (2 * n >= v.size() || 2 * n + 1 >= v.size()) result = true;
		return result;
	}

	void push(int p) {
		v.push_back(p);
		int current = v.size() - 1;

		while (v[current / 2] > v[current] && current != 1) {
			swap(current / 2, current);
			current /= 2;
		}
	}

	int pop() {
		int result = v[1];

		swap(1, v.size() - 1);
		v.pop_back();
		int current = 1;
		int smaller;

		// ���� ��� �ڽĺ��� ���� ������, �� �� �� ���� �Ͱ� �ٲ۴�
		// ���� leaf�� ��� ���־� ��
		while (!isLeaf(current)) {
			if (v[current] <= v[2 * current] || v[current] <= v[2 * current + 1]) break;
			smaller = (v[2 * current] < v[2 * current + 1]) ? 2 * current : 2 * current + 1; // ���� �� �� �������� index
			swap(current, smaller);
			current = smaller;
		}

		return result;
	}
};
