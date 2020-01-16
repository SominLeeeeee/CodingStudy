/*
현재 node : n
왼쪽 자식 : 2n
오른쪽 자식 : 2n+1
부모 : n/2

처음 시작은 편의를 위해 0이 아닌 1로 한다
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

		// 내가 모든 자식보다 작을 때까지, 둘 중 더 작은 것과 바꾼다
		// 내가 leaf인 경우 관둬야 함
		while (!isLeaf(current)) {
			if (v[current] <= v[2 * current] || v[current] <= v[2 * current + 1]) break;
			smaller = (v[2 * current] < v[2 * current + 1]) ? 2 * current : 2 * current + 1; // 오왼 중 더 작은것의 index
			swap(current, smaller);
			current = smaller;
		}

		return result;
	}
};
