#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<long long int, long long int> pii;
typedef vector<vector<pii>> Graph;

const long long int INF = 1e9;

long long int prim(const Graph& graph, long long int start) {
    long long int n = graph.size();
    vector<bool> visited(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    long long int minCost = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        long long int u = pq.top().second;
        long long int w = pq.top().first;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        minCost += w;

        for (const auto& edge : graph[u]) {
            long long int v = edge.first;
            long long int weight = edge.second;
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }

    return minCost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int N, M;
    cin >> N >> M;

    Graph graph(N);

    for (long long int i = 0; i < M; ++i) {
        long long int a, b, l;
        cin >> a >> b >> l;
        graph[a - 1].push_back({b - 1, l});
        graph[b - 1].push_back({a - 1, l});
    }

    long long int minTotalLength = prim(graph, 0);
    cout << minTotalLength << endl;

    return 0;
}