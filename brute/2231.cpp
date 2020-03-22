// https://acmicpc.net/problem/2231

#include <iostream>
using namespace std;

int main() {
	int N;	// 분해합 
	cin >> N;
	
	int tmp = N;
	int cnt = 0;
	while(tmp != 0) {
		tmp /= 10;
		cnt++;	// 자리수 구하기 
	}
	
	int result = 0;
	int sum = 0;
	int cpy;
	
	for(int i = N-9*cnt; i < N; i++) {
		cpy = i;	// i값이 바뀌면 안되니까 
		sum = i;
		while(cpy != 0) {
			sum += cpy%10;
			cpy /= 10;
		}
		if(sum == N) {
			result = i;	// 그 분해합이 N이라면 답이다! 
			break; 
		}
	} 
	
	cout << result << endl;
} 
