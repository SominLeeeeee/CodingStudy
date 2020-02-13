#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

typedef pair<int, int> pint;
queue<pint> q;					// bfs�� ����� ť
queue<pint> checked;			// ���ٿ� ��
vector< vector<char> > castle;	// ���� �迭
vector< vector<char> > lab;  	// �� ��ȣ ��Ÿ���� �迭
vector< vector<int> > graph;	// ����list ��Ÿ����
int dir[4][2] = { {0,-1}, {-1,0}, {0,1}, {1,0} };	// direction

int bfs();	// area ���� return
void pushVisit(char a, char b);
void label(int num);

int main() {
	int m, n;	// m�� ���� , n�� ����
	cin >> m >> n;
	int temp, area, num = 0, maxarea = 0;	// �����, ���ȣ, �����ִ밪
	int maxsum = 0;							// �� ��ģ ���� �ִ�
	vector<int> areaArr;					// �� ��ȣ - �� ���� ��

	castle.resize(n + 2);
	castle[0].resize(m + 2, 0);
	for (int i = 1; i <= n; i++) {
		castle[i].resize(m + 2, 0);
		for (int j = 1; j <= m; j++) {
			cin >> temp;
			castle[i][j] = temp;
		}
	}
	castle[n + 1].resize(m + 2, 0);
	// n+2*m+2 ¥�� ���� castle�� �����

	lab.resize(n + 2);
	for (int i = 0; i < n + 2; i++) {
		lab[i].resize(m + 2);
	}	// �� label ǥ���� ���� �ʱ�ȭ

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			if (!(castle[y][x] >> 4 & 1)) {	// �� ���� ���ΰ�?
				q.push(make_pair(y, x));	// �׷��ٸ� ���������� �ִ´�
				castle[y][x] = castle[y][x] | 16;	// 5��° bit�� ���ٰ�(1) ǥ��
				area = bfs();						// y,x���� ���� �ִ� ������ bfs ����
				maxarea = (maxarea > area) ? maxarea : area;	// ���� �ִ밪 ������Ʈ
				num++;								// �� ��ȣ ī��Ʈ
				areaArr.resize(num + 1);
				areaArr[num] = area;				// ���� �����صδ� �迭�� ���� �����ϱ�
				label(num);							// �� ��ȣ ��α�
			}
		}
	}

#if 0
	5 3
		15 7 11 2 14
		3 0 14 5 15
		9 12 11 8 14

#endif
		for (int i = 1; i < num; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				temp = areaArr[i] + areaArr[graph[i][j]];	// ������� 1����� 2������ �����ߴٸ� 1���� ���� + 2���� ���̸� �ϴ°�
				maxsum = (temp > maxsum) ? temp : maxsum;	// �װ� maxsum���� ũ�ٸ� ������Ʈ�Ѵ�
			}
		}

	cout << num << endl;
	cout << maxarea << endl;
	cout << maxsum << endl;
}

int bfs() {
	pint temp;
	char byuk;
	int nextx, nexty, area = 0;

	while (!q.empty()) {
		temp = q.front();	// q�� ù��°�� �ӽ� ����
		q.pop();			// q�� ù��° ����
		checked.push(temp);	// �湮�Ѱ� üũ�ϴ� ť�� �ִ´� (���߿� ����list ���鶧 ������)
		area++;				// ���� ���
		byuk = castle[temp.first][temp.second]; // ����ġ�� ǥ�õǾ��ִ�!

		for (int i = 0; i <= 3; i++) {
			if (!((byuk >> i) & 1)) {			// ���� (�����ϼ�)���� �շ��ִٸ�
				nexty = temp.first + dir[i][0];	// ���� ���� �շ������� ���� ���� Ž���ϵ��� ����
				nextx = temp.second + dir[i][1];
				if ((castle[nexty][nextx] >> 4) & 1) continue;
				castle[nexty][nextx] = castle[nexty][nextx] | (int)pow(2, ((i + 2) % 4));
				// ���� �� ���� ���ƹ���
				// �� ���� ĭ�� ������ �� ��(next)�� �°Ŷ�� ������ ���� ���´�!
				pushVisit(nexty, nextx);
			}
		}
	}

	return area;
}

void pushVisit(char y, char x) {
	// ��ǥ y,x�� ���� �ִ� ���̶��
	castle[y][x] = castle[y][x] | 16;	// 5��° bit�� ��ȴٰ� ǥ���صд�
	q.push(make_pair(y, x));			// (y,x)�� q�� �ִ´�
}

void label(int num) {
	graph.resize(num + 1);
	pint temp;
	while (!checked.empty()) {
		temp = checked.front();

		checked.pop();
		lab[temp.first][temp.second] = num;

		for (int i = 0; i < 4; i++) {
			if (lab[temp.first + dir[i][0]][temp.second + dir[i][1]] > 0 &&
				lab[temp.first + dir[i][0]][temp.second + dir[i][1]] < num) {				// ���� ĭ�� ���(0)�� �ƴϰ� ���� ���� �浵 �ƴ϶�� 
				graph[num].push_back(lab[temp.first + dir[i][0]][temp.second + dir[i][1]]);	// ������ ���� ��ȣ�� ����list�� �߰�
				graph[lab[temp.first + dir[i][0]][temp.second + dir[i][1]]].push_back(num); // �Ųٷε� ���� list�� �߰�
			}
		}

	}
}