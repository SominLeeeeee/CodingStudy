// https://www.acmicpc.net/problem/1931

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<unsigned int, unsigned int> time;	// first = begin & second = end
vector<time> t;					// time들을 저장할 벡터 t
bool cmp(time temp1, time temp2);

int main() {
	int N;						// 회의가 몇개인지
	unsigned int begin, end;	// 입력받을거
	int cnt=0, when=0;			// 회의 가능한 수, 회의 종료지점
	cin >> N;

	t.resize(N);				// 회의 갯수만큼 크기 늘려주기
	for (int i = 0; i < N; i++) {		
		cin >> begin >> end;
		t[i] = make_pair(begin, end);	// begin, end 저장하기
	}

	sort(t.begin(), t.end(), cmp);		// 종료시간이 빠른 순으로 정렬

	for (int i = 0; i < t.size(); i++) {
		if (when <= t[i].first) {		// 회의 종료지점이 시작지점보다 작으면
			when = t[i].second;			// 그 회의 진행(종료지점 업데이트)
			cnt++;						// 가능한 회의 수 증가
		}
	}

	cout << cnt;
	return 0;
}

bool cmp(time temp1, time temp2) {
	if (temp1.second == temp2.second)
		return temp1.first < temp2.first;	// 종료시간이 같다면 시작이 빠른 순
	else
		return temp1.second < temp2.second;	// 같지 않으면 종료가 빠른 순
}