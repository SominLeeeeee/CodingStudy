// https://acmicpc.net/problem/1463

#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b, int c) {
	int aorb = a <= b ? a : b;
	int orc = aorb <= c ? aorb : c;
	return orc;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int main() {
	int n;
	cin >> n;

	int* dp = new int[n+1];

	dp[1] = 0;
	
	for (int i = 2; i <= n; i++) {
		if (i % 6 == 0) { dp[i] = min(dp[i / 3], dp[i / 2], dp[i - 1]) + 1; }
		else if(i%2 == 0) { dp[i] = min(dp[i / 2], dp[i - 1]) + 1; }
		else if(i%3 == 0) { dp[i] = min(dp[i / 3], dp[i - 1]) + 1; }
		else { dp[i] = dp[i - 1] + 1; }
	}

	cout << dp[n] << endl;
}