// https://www.acmicpc.net/problem/7576

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> p;
vector< vector<int> > day;		// ���� �ɸ����� ��Ÿ�� 2���� ����
queue<p> q;						// ������� ť
vector< vector<int> > graph;	// �������

void check(int x, int y);
void visit(int x, int y);
void find(int x, int y, int d);

int main() {
	int N, M;
	cin >> N >> M;

	graph.resize(M + 2);
	for (int i = 0; i < M + 2; i++) {
		graph[i].resize(N + 2, -1);
	}	// ũ�Ⱑ N+2 * M+2�� 2���� ���� graph ����
		// �����ڸ��� �ֺ��� Ž���� ���� ����� �����¿� ���پ� �߰�����

	bool all = true;	// ���� �� ���� �������� Ȯ���ϴ� ����
	p temp;

	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) all = false;
		}
	}	// graph ���� �Է¹���

	if (all == true) {
		cout << 0;
		return 0;
	}	// ���� �� �;��ٸ� 0�� �ɸ��ٰ� ����ϰ� ���α׷� ����

	day.resize(M + 2);
	for (int i = 0; i < M + 2; i++) {
		day[i].resize(N + 2);
	}	// 2���� ���� day ����

	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			day[i][j] = graph[i][j];
		}
	}	// day = graph

	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (graph[i][j] == 1) {
				q.push(make_pair(i, j));
				visit(i,j);
			}
		}
	}	// ��� �������� q�� �ִ´�
		// �������� day���� 1�̴ϱ� �� ����� �� -1

	while (!q.empty()) {				// q�� �� ������ ����Ѵ�
		temp = q.front();
		q.pop();						// q�� ù��° pop
		check(temp.first, temp.second); // ���� vertex ����vertex �˻�
	}

	int max = -1;
	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (day[i][j] == 0) {
				cout << -1;
				return 0;
			} // ��� �� ������ ���ϴ� ��Ȳ�ΰ�?

			if (day[i][j] > max) max = day[i][j];
		}
	}

	cout << max - 1;
	return 0;
}

void visit(int x, int y) {
	graph[x][y] = -1;				// �湮�� ���� �����°ɷ� ó��
}

void check(int x, int y) {
	find(x, y - 1, day[x][y]);		// �����¿� �� üũ
	find(x, y + 1, day[x][y]);
	find(x - 1, y, day[x][y]);
	find(x + 1, y, day[x][y]);
}

void find(int x, int y, int d) {
	if (graph[x][y] != -1) {		// �� �� �ִ� ���̶��
		q.push(make_pair(x, y));	// q�� �߰�
		visit(x, y);				// �湮 ������ ǥ��
		day[x][y] = d + 1;			// �ɸ��� �ð� ǥ��
	}
}