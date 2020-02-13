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
	vector<int> best;	// 최대값 배열
	int N;	// 행의 수
	int idxbf = -1, idxaf;	// best의 idx / land[i]의 idx
	int max1 = 0, max2 = 0;	// 최대값1, 최대값2
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
		}	// land[n]행의 최대값 idx랑 max1, 2 찾기

		for (int j = 0; j < 4; j++) {
			best[j] += max1;
		}	// best 배열에 각각 max1값을 더한다

		if (idxbf == idxaf) {
			best[idxbf] = best[idxbf] + max2 - max1;
			cout << "max2 is " << max2 << endl;
			idxaf = temp;
		}	// best 배열의 max idx와 land 배열의 maxidx가 같다면 max2를 더한다
			// 그리고 idxaf = max2의 idx이다 (내가 밟은 idx)
		printVec(best);
	}
	int result = 0;
	
	for (int i = 0; i < 4; i++) {
		result = (result < best[i]) ? best[i] : result;
	}
	cout << result << endl;
}