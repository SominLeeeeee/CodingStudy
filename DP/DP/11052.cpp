// https://acmicpc.net/problem/11052

#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}	// 이거 하나 쓰자고 algorithm include하기 싫었다!

int main() {
	int N;		// 카드를 몇장 사야하는지
	cin >> N;

	vector<int> price;		// 카드 장수 별 가격을 저장해둘 price 벡터
	price.resize(N + 1, 0);	// idx를 익숙하게? 쓰기위해 N번방까지 있게 한다
	for (int i = 1; i <= N; i++) {
		cin >> price[i];	// 1장 부터 N장 까지, 0번방은 안쓰는것
	}

	vector<int> best;
	best.resize(N + 1, 0);	// 그 장 수까지 최대 합이 얼마인지 저장할 best 벡터, 0으로 초기화

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