#include <iostream>
using namespace std;

int main() {
	int N, K;		
	cin >> N >> K;	// 동전의 종류 개수, 만들어야 하는 가치

	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];	// 동전 종류 입력받기
	}

	int money = 0;	// 현재 얼마까지 만들었는지
	int idx = N-1;	// arr 어디에 있는거 썼는지
	int cnt = 0;	// 동전 몇개 필요한지
	while (money != K) {
		if (arr[idx] <= K - money) {
			money += arr[idx];
			cnt++;
		}
		else idx--;
	}

	cout << cnt;
	
}