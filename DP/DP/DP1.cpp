// https://acmicpc.net/problem/2579

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> grade;
vector<int> best;

int main() {
	int n;	// 계단의 개수
	cin >> n;

	grade.resize(n);	// grade[idx]는 idx번째 계단의 점수
	best.resize(n);		// best[idx]는 idx번째 계단까지 가는 최대 점수

	int i;
	for (i = 0; i < n; i++) {
		cin >> grade[i];
	}

	best[0] = grade[0];										// 0번째 계단까지 최대는 그냥 0을 밟는거 밖에 없다
	best[1] = max(grade[0] + grade[1], grade[1]);			// 1번째 계단은 0-1 혹은 바로 1로 간 경우
	best[2] = max(grade[0] + grade[2], grade[1] + grade[2]);// 2번째 계단은 1-2 혹은 0-2

	/*
	점화식에 관한 설명
	  ++시작 ~ 목적지를 갈 때에
		목적지-1 계단을 밟은 경우 시작 ~ 목적지-3 ~ 목적지-1 ~ 목적지
		목적지-2 계단을 밟은 경우 시작 ~ 목적지-2 ~ 목적지 이다.
		세번 연속된 계단을 밟으면 안되기 때문이다!

	  ++따라서 점화식은
		best[dst] = max(best[dst-3] + grade[dst-1] + grade[dst], 
						best[dst-2] + grade[dst] 이다.
		
	  ++dst-3을 접근할때 오류가 나면 안되므로 dst는 최소 3 이상부터로 해야한다
	*/

	int dst;
	for (dst = 3; dst < n; dst++) {	// 우리는 best[n-1]을 구해야 한다
		best[dst] = max(best[dst - 3] + grade[dst - 1] + grade[dst],
						best[dst - 2] + grade[dst]);
	}

	cout << best[n-1] << endl;
}