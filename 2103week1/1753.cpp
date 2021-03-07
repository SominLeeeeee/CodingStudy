#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

#define INF 2147000000

typedef pair<int, int> to_weight;

void print_vec(vector<int> vec) {
    for(int i = 1; i < vec.size(); i++) {
        if(vec[i] == INF) cout << "INF" << endl;
        else cout << vec[i] << endl;
    }
}

void print_queue(queue<int> q) {
    queue<int> copy = q;
    cout << "queue is ";
    while(!copy.empty()) {
        cout << copy.front() << " ";
        copy.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector< queue<to_weight> > graph;
    int V, E;   // vertex num, edge num
    int K;      // start verteex

    cin >> V >> E;
    cin >> K;

    graph.resize(V+1);

    int u, v, w;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        graph[u].push(make_pair(v, w));
    }

    vector<int> djkstra(V+1, INF);
    queue<int> start;
    start.push(K);

    djkstra[K] = 0;
    int min_weight;
    int min_idx;

    while (!start.empty()) {
        min_weight = INF;
        K = start.front();
        start.pop();

        while (!graph[K].empty()) {
            to_weight front;
            front = graph[K].front();
            graph[K].pop();
            djkstra[front.first] = min(djkstra[front.first], djkstra[K] + front.second);
            
            if (min_weight > djkstra[front.first]) {
                min_weight = djkstra[front.first];
                min_idx = front.first;
            }
        }

        if(min_weight != INF) start.push(min_idx);
    }

    print_vec(djkstra);
}