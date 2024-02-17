#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector<int> graph[MAXN];
int dist[MAXN];

void bfs(int start, int N) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // considering bidirectional edges
    }

    // Initialize distances to -1 (unvisited)
    fill(dist, dist + N + 1, -1);

    bfs(1, N); // start BFS from island 1

    bool found = false;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] == K) {
            cout << i << endl;
            found = true;
        }
    }

    if (!found)
        cout << "NO";

    return 0;
}
