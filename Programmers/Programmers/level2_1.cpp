#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> best) {
	for (int i = 0; i < 4; i++) {
		cout << best[i] << " ";
	}
	cout << endl;
}
int main() {
	vector< vector<int> > land = { {1,2,3,5}, {5,6,7,8}, {1,2,100,4} };
	vector<int> best;	// �ִ밪 �迭
	int N;	// ���� ��
	int idxbf = -1, idxaf;	// best�� idx / land[i]�� idx
	int max1 = 0, max2 = 0;	// �ִ밪1, �ִ밪2
	int temp;

	best.resize(4, 0);
	best = land[0];
	
	for (int i = 0; i < 4; i++) {
		if (max1 < best[i]) idxaf = i;
	}

	for (int i = 1; i < land.size(); i++) {
		max1 = 0;
		max2 = 0;
		idxbf = idxaf;
		for (int j = 0; j < 4; j++) {
			if (max1 < land[i][j]) {
				max2 = max1;
				temp = idxaf;
				max1 = land[i][j];
				idxaf = j;
			}
		}	// land[n]���� �ִ밪 idx�� max1, 2 ã��

		for (int j = 0; j < 4; j++) {
			best[j] += max1;
		}	// best �迭�� ���� max1���� ���Ѵ�

		if (idxbf == idxaf) {
			best[idxbf] = best[idxbf] + max2 - max1;
			cout << "max2 is " << max2 << endl;
			idxaf = temp;
		}	// best �迭�� max idx�� land �迭�� maxidx�� ���ٸ� max2�� ���Ѵ�
			// �׸��� idxaf = max2�� idx�̴� (���� ���� idx)
		printVec(best);
	}
	int result = 0;
	
	for (int i = 0; i < 4; i++) {
		result = (result < best[i]) ? best[i] : result;
	}
	cout << result << endl;
}