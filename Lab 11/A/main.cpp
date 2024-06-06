#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> match;
vector<bool> visited;

bool dfs(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (match[v] == -1 || (!visited[match[v]] && dfs(match[v]))) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int kuhn(int n) {
    match.assign(n, -1);
    int maxMatching = 0;
    for (int u = 0; u < n; ++u) {
        visited.assign(n, false);
        if (dfs(u)) {
            maxMatching++;
        }
    }
    return maxMatching;
}

int main() {
    int N, M, Q;
    cin >> N >> M;
    cin >> Q;

    graph.resize(N * M);
    match.resize(N * M, -1);
    visited.resize(N * M, false);

    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;
        int u = (x - 1) * M + y - 1;
        match[u] = 0;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (match[i * M + j] == -1) {
                if (j + 1 < M && match[i * M + j + 1] == -1) {
                    graph[i * M + j].push_back(i * M + j + 1);
                    graph[i * M + j + 1].push_back(i * M + j);
                }
                if (i + 1 < N && match[(i + 1) * M + j] == -1) {
                    graph[i * M + j].push_back((i + 1) * M + j);
                    graph[(i + 1) * M + j].push_back(i * M + j);
                }
            }
        }
    }

    int maxCoveredCells = kuhn(N * M);
    cout << maxCoveredCells  << endl;
    return 0;
}
