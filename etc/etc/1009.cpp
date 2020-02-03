// https://acmicpc.net/problem/1009

#include <iostream>
using namespace std;

int main() {
	int v[10][4] = { { 10,10,10,10 },
			{ 1,1,1,1 },
			{ 2,4,8,6 },
			{ 3,9,7,1 },
			{ 4,6,4,6 },
			{ 5,5,5,5 },
			{ 6,6,6,6 },
			{ 7,9,3,1 },
			{ 8,6,8,6 },
			{ 9,1,9,1 } };

	int n, a, b, result;
	cin >> n; // 테스트 몇번 할건지

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		result = v[a % 10][(b - 1) % 4];
		cout << result << endl;
	}

	return 0;

}