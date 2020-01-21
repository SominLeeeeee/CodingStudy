//https://www.acmicpc.net/problem/2178

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define yes 49
#define no 48
using namespace std;

void check(int x, int y);
void visit(int x, int y);
void find(int x, int y, int leng);

vector< vector<int> > length;
queue< pair<int, int> > q;
vector< vector<char> > graph;

int main() {
	int N, M;
	cin >> N >> M;

	pair<int, int> temp;

	graph.resize(N+2);
	for (int i = 0; i < N+2; i++) {
		graph[i].resize(M+2, no);
	}	// ũ�Ⱑ N+2 * M+2�� 2���� ���� graph ����
		// �����ڸ��� �ֺ��� Ž���� ���� ���� �����¿� ���پ� �߰�����

	for (int i = 1; i < N+1; i++) {
		for (int j = 1; j < M+1; j++) {
			cin >> graph[i][j];
		}
	}	// graph ���� �Է¹���

	length.resize(N + 2);
	for (int i = 0; i < N + 2; i++) {
		length[i].resize(M + 2, 0);
	}	// 2���� ���� length ���� �� �ʱ�ȭ

	length[1][1] = 1;					// �������� length�� 1
	
	q.push(make_pair(1, 1));			// �������� Q�� �ִ´�
	visit(1, 1);						// ������ �湮����

	while (!q.empty()) {				// q�� �� ������ ����Ѵ�
		temp = q.front();
		q.pop();						// q�� ù��° pop
		check(temp.first, temp.second); // ���� vertex ����vertex �˻�
	}

	cout << length[N][M];				// ������->(N,M) ����

}

void visit(int x, int y) {
	graph[x][y] = no;					// �湮�� ���� �����°ɷ� ó��
}

void check(int x, int y) {
	find(x, y - 1, length[x][y]);		// �����¿� �� üũ
	find(x, y + 1, length[x][y]);
	find(x - 1, y, length[x][y]);
	find(x + 1, y, length[x][y]);
}

void find(int x, int y, int leng) {
	if (graph[x][y] == yes) {			// �� �� �ִ� ���̶��
		q.push(make_pair(x, y));		// q�� �߰�
		visit(x, y);					// �湮 ������ ǥ��
		length[x][y] = leng + 1;		// �ɸ��� �Ÿ� ǥ��
	}
}