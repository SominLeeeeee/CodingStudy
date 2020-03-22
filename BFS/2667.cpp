// https://acmicpc.net/problem/2667

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;
queue<p> bfsq;				// bfs�� ���� queue
vector< vector<char> > map;	// ����
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

int bfs();		// ������ �ִ� ���� ���� return

int main() {
	int N, house;
	cin >> N;					// ������ ũ�� N*N
	vector<int> result;			// ���� ���� �����صδ� ����

	map.resize(N + 2);

	map[0].resize(N + 2, 48);	// ù �� �ʱ�ȭ
	for (int i = 1; i < N + 1; i++) {	// �״������� �Է¹ޱ�
		map[i].resize(N + 2, 48);
		for (int j = 1; j < N + 1; j++) {
			cin >> map[i][j];
		}
	}
	map[N + 1].resize(N + 2, 48);
	// N+2 * N+2 ũ�� ���� �ʱ�ȭ

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (map[y][x] == 49) {			// ������
				map[y][x] = 48;				// 0�� ���� ���� ������ �ǹ� (�湮���� ó��)
				bfsq.push(make_pair(x, y));	// �������� q�� �ִ´�
				house = bfs();
				result.push_back(house);	// ���� ���� ��� ���Ϳ� �������
			}
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	
}

int bfs() {
	p temp;
	int num = 0;		// ���� ���� �� ����
	int nexty, nextx;	// ���� ���� ��ǥ y,x

	while (!bfsq.empty()) {
		temp = bfsq.front();
		bfsq.pop();
		num++;
		for (int i = 0; i < 4; i++) {
			nexty = temp.second + dir[i][0];
			nextx = temp.first + dir[i][1];
			if (map[nexty][nextx] == 49) {			// �� �� �ִ� ���̶��
				bfsq.push(make_pair(nextx, nexty));	// �ֺ� �� q�� �ֱ�
				map[nexty][nextx] = 48;				// �湮������ ǥ��
			}
		}
	}
	return num;
}