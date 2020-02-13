// https://acmicpc.net/problem/1966

#include <queue>
#include <iostream>
#include <utility>
using namespace std;

typedef pair<int, int> p;

int main() {
	int T;					// test case
	int N, M;				// 문서 갯수, 몇번째 문서?
	int temp;
	int arr[11] = { 0 };	// 중요도가 idx인 문서가 몇개 남았는가?
	int max = 0;			// 현재 가장 중요도 큰게 뭐인가?

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		int result = 1;			// 몇번째인지 세고 있을 결과값
		queue<p> priority;		// (문서번호, 중요도)를 저장해둘 큐

		for (int j = 0; j < N; j++) {
			cin >> temp;
			priority.push(make_pair(j, temp));	// (문서번호, 중요도)
			max = max > temp ? max : temp;		// 중요도 max값 업데이트
		}

		p now;
		while (true) {
			if (priority.front().second == max) {	// 나의 중요도가 제일 높다면
				now = priority.front();
				arr[now.second]--;					// 내 중요도를 가진 문서 개수 -1
				result++;							// result++
				if (now.first == M) break;			// 내가 M번째 문서라면 while문 탈출
				priority.pop();						// 나는 출력된다!
				while (arr[max] == 0) {		// 그 다음 중요도를 찾을 때까지
					max--;					// max값을 줄여간다
				}
			}

			else {	// 나보다 중요한 애가 있다면
				priority.push(priority.front());	// 나는 맨 뒤로 간다
				priority.pop();
			}
		}

		cout << result << endl;
	}
}