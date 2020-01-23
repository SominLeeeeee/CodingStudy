// https://www.acmicpc.net/problem/3055

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> p;
typedef vector< vector<int> > vec;
p dest;			// ������ (�����)
vec day;		// ���� �ɸ����� ��Ÿ�� 2���� ����
vec dayWater;	// ���� �����¤��� ��ĥ �ɸ�����
queue<p> q;		// ������� ť
queue<p> qWater;
vec graph;		// �������

void bfs();
void bfsWater();
void check(int x, int y);
void checkWater(int x, int y);
void visit(int x, int y);
void find(int x, int y, int d);
void findWater(int x, int y, int d);
void printVector(vec v, int N, int M);

int main() {
	int N, M;
	cin >> M >> N;
	
	graph.resize(M + 2);
	for (int i = 0; i < M + 2; i++) {
		graph[i].resize(N + 2, -1);
	}	// ũ�Ⱑ N+2 * M+2�� 2���� ���� graph ����
		// �����ڸ��� �ֺ��� Ž���� ���� ����� �����¿� ���پ� �߰�����

	day.resize(M + 2);
	for (int i = 0; i < M + 2; i++) {
		day[i].resize(N + 2, 0);
	}

	dayWater.resize(M + 2);
	for (int i = 0; i < M + 2; i++) {
		dayWater[i].resize(N + 2, 0);
	}

	char temp;
	//p dest;
	for (int i = 1; i < M + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			graph[i][j] = 0;
			cin >> temp;

			if (temp == 'S') {				// ����ġ���
				graph[i][j] = 1;			// �������� 1�� �ʱ�ȭ
				day[i][j] = 1;
				q.push(make_pair(i, j));	// ������ q�� ����
				visit(i, j);				// ������ �湮����
			}

			else if (temp == '*') {			// ���� ������
				graph[i][j] = -2;			// ���� -2
				dayWater[i][j] = 1;
				qWater.push(make_pair(i, j));  // ������ qWater�� ����
				visit(i, j);				// �� ������ �湮����
			}

			else if (temp == 'D') {
				graph[i][j] = 0;
				dest = make_pair(i, j); // ������� �������� ����
			}

			else if (temp == 'X') {
				graph[i][j] = -1;
				day[i][j] = -1;
				dayWater[i][j] = -1;
			}// ���� ������ �� ����

			else graph[i][j] = 0;
		} 
	}

	printVector(graph, N, M);

	bfsWater();
	bfs();
	
	cout << "\nthis is dayWater vector\n";
	printVector(dayWater, N, M);
	
	cout << "\nthis is daygoseum vector\n";
	printVector(day, N, M);



}


void visit(int i, int j) {
	graph[i][j] == -1; // �湮�� ���� �� �ɷ������� -1�� ó���Ѵ�
}

void bfs() {
	p temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		check(temp.first, temp.second);
//		cout << "bfs\n";
	}
}

void bfsWater() { // �� ���Ľð� bfs������
	p temp;
	int cnt = 0;
	while (!qWater.empty()) {
		temp = qWater.front();
		qWater.pop();
		checkWater(temp.first, temp.second);
	//	cout << cnt++ << endl;
	}
	cout << "bfsWater end";
}

void checkWater(int x, int y) {
	findWater(x - 1, y, dayWater[x][y]);
	findWater(x + 1, y, dayWater[x][y]);
	findWater(x, y - 1, dayWater[x][y]);
	findWater(x, y + 1, dayWater[x][y]);
}

void check(int x, int y) {
	find(x - 1, y, day[x][y]);
	find(x + 1, y, day[x][y]);
	find(x, y - 1, day[x][y]);
	find(x, y + 1, day[x][y]);
}

void findWater(int x, int y, int d) {
	if (graph[x][y] != -1 && make_pair(x, y) != dest) { // ���� ������� �ƴ϶��
		qWater.push(make_pair(x, y));
		visit(x, y);
		dayWater[x][y] = d + 1;
	}
}

void find(int x, int y, int d) {
	if (graph[x][y] != -1 && d < dayWater[x][y]) {
		q.push(make_pair(x, y));
		visit(x, y);
		day[x][y] = d + 1;
	}
}

void printVector(vec v, int N, int M) {

	for (int i = 0; i < M+2; i++) {
		for (int j = 0; j < N+2; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}