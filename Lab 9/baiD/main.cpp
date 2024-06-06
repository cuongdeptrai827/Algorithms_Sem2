#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 500;
const unsigned long long INF = 2e64;
int N, M;
vector<pair<int, unsigned long long>> adj[maxN];

unsigned long long dijkstra(int s) {
    vector<unsigned  long long> d(N + 1, INF);
    d[s] = 0;
    priority_queue<pair<unsigned long long, int>, vector<pair<unsigned long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        pair<unsigned long long, int> top = pq.top();
        pq.pop();
        int u = top.second;
        unsigned  long long dis = top.first;

        if (dis > d[u]) {
            continue;
        }

        for (auto it : adj[u]) {
            int v = it.first;
            unsigned long long w = it.second;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }

    // Находим сумму всех расстояний до остальных домов
    unsigned long long total_distance = 0;
    for (int i = 1; i <= N; ++i) {
        total_distance += d[i];
    }

    return total_distance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y;
        unsigned long long weight;
        cin >> x >> y >> weight;
        adj[x].push_back({y, weight});
        adj[y].push_back({x, weight});
    }

    unsigned long long minSum = INF;
    int minVertex = -1;

    for (int i = 1; i <= N; i++) {
        unsigned long long sum = dijkstra(i);
        if (sum < minSum) {
            minSum = sum;
            minVertex = i;
        }
    }

    cout << minVertex << "\n";


    return 0;
}

