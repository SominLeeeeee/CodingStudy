// https://acmicpc.net/problem/6549

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	while(true) { // 0 입력받을 때까지 테스트 계쏙 해야한다
	
		int n; // 직사각형의 개수
		int temp;
		long long max = 0, area;
		cin >> n;
		if (n == 0) return 0; // 0 입력받으면 프로그램 종료

		vector<long long> h; // 직사각형의 높이 저장하는 벡터
		stack<int> remain;	// 남아있는 직사각형 몇번째인지 저장하는 스택

		for (int i = 0; i < n; i++) {
			cin >> temp;
			h.push_back(temp); // i번째 직사각형 높이 입력받기
		}
		h.push_back(0); // 마지막에 가장 작은 직사각형을 넣어준다

		for (int i = 0; i < h.size(); i++) {
			while (!remain.empty() && h[remain.top()] >= h[i]) { // 만약 나보다 >=한 애가 있다면
				temp = remain.top();
				remain.pop(); // 꺼낸다. 
							// 이때 꺼낸 것의 left는 현재 있는 top이고, right는 나다!

				if (remain.empty()) { // 이제 내 왼쪽에 아무 판자도 없다면?
					area = i * h[temp];
					max = (area > max) ? area : max;
				}

				else { // 내 왼쪽에 뭐가 있다 == 내가 제일 작은 애가 아니라면
					area = (i - remain.top() - 1) * h[temp]; // 넓이 = (right(나) - left(top) - 1) * h[꺼낸거]
					max = (area > max) ? area : max; // 넓이가 최댓값이면 갱신해준다
				}
			} // 여기까지 왔으면 나보다 같거나 큰 판자는 다 제거한 것이다

			remain.push(i); // 이제 나를 넣는다!
		}

		cout << max << endl;
	}


}

