// https://www.acmicpc.net/problem/14502

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

typedef vector< vector<int> > vec;
typedef pair<int, int> p;
vec graph;
vec temp;
queue<p> q;
p* arr;
int N, M;

int bfsVirus();
void find(int x, int y);
void check(int x, int y);

int main() {
	cin >> N >> M;

	graph.resize(N+2);
	for (int y = 0; y < N + 2; y++) {
		graph[y].resize(M + 2, 1);
	} // graph vector �Ҵ�

	temp.resize(N + 2);
	for (int y = 0; y < N + 2; y++) {
		temp[y].resize(M + 2);
	} // temp �Ҵ�

	for (int y = 1; y < N + 1; y++) {
		for (int x = 1; x < M + 1; x++) {
			cin >> graph[y][x];
		}
	} // graph vector �Է¹���
	
	arr = new p[N * M + 1];
	
	for (int y = 1; y < N+1; y++) {
		for (int x = 1; x < M+1; x++) {
			arr[M*(y-1) + x] = make_pair(x, y);
		}
	} // arr[M*(y-1) + x]�� (x, y)�̴�

	int a, max = 0;

	int i, j, k;
	for (i = 1; i <= N*M - 2; i++) {		// �� ���� ������ brute-force�� �� ������
		if (graph[arr[i].second][arr[i].first] != 0) continue;
		graph[arr[i].second][arr[i].first] = 1;
		for (j = i + 1; j <= N*M - 1; j++) {
			if (graph[arr[j].second][arr[j].first] != 0) continue;
			graph[arr[j].second][arr[j].first] = 1;
			for (k = j + 1; k <= N*M; k++) {
				if (graph[arr[k].second][arr[k].first] != 0) continue;
				graph[arr[k].second][arr[k].first] = 1; // 0�̶�� �� �����

				a = bfsVirus();				// �� ���� ���Ŀ� ���̷��� ��Ʈ����
				max = (max > a) ? max : a;	// ���̷��� ��Ʈ�� ���� 0 ����� ���� & max�� ������Ʈ

				graph[arr[k].second][arr[k].first] = 0; // ������� ��������
			}
			graph[arr[j].second][arr[j].first] = 0;
		}
		graph[arr[i].second][arr[i].first] = 0;

	} 
	
	cout << max;
	return 0;
}

int bfsVirus() {

	int cnt = 0;
	p fst;

	for (int y = 0; y < N + 2; y++) {
		for (int x = 0; x < M + 2; x++) {
			temp[y][x] = graph[y][x];
		}
	} // graph�� �����ϱ� ���� �ӽ� ���Ϳ� �����ϵ��� ��

	for (int y = 1; y < N + 1; y++) {
		for (int x = 1; x < M + 1; x++) {
			if (temp[y][x] == 2) {
				q.push(make_pair(x, y));
				temp[y][x] = 1;
			}
		}
	} // ������ q�� �ְ� �湮����(1) ó��

	while (!q.empty()) {
		fst = q.front();				// ó����
		q.pop();						// ����
		find(fst.first, fst.second);	// �ֺ��� �˻�
	}

	for (int y = 1; y < N + 1; y++) {
		for (int x = 1; x < M + 1; x++) {
			if (temp[y][x] == 0) cnt++;	// 0 ���� ����
		}
	}

	return cnt;							// 0 ���� return
}

void find(int x, int y) {
	check(x-1, y);
	check(x+1, y);
	check(x, y-1);
	check(x, y+1);
} // �����¿� ���̷����� ������ �ִ��� �˻�

void check(int x, int y) {
	if (temp[y][x] == 0) {
		q.push(make_pair(x, y));		// 0�̶�� q�� push
		temp[y][x] = 1;					// �湮����(1) ǥ��
	}
}