#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;

vector<int> adj[MAX_N + 1];
vector<vector<int>> strong_connected(MAX_N + 1);

bool isStrongConnected(int u, int v) {
    return find(strong_connected[u].begin(), strong_connected[u].end(), v) != strong_connected[u].end() ||
           find(strong_connected[v].begin(), strong_connected[v].end(), u) != strong_connected[v].end();
}

void addStrongConnected(int u, int v) {
    strong_connected[u].push_back(v);
    strong_connected[v].push_back(u);
}

bool isConnected(int u, int v) {
    vector<bool> visited(MAX_N + 1, false);
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == v) return true;
        for (int next : adj[curr]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return false;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < q; i++) {
        char op;
        int a, b;
        cin >> op >> a >> b;

        if (op == '?') {
            if (isStrongConnected(a, b) || isConnected(a, b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }

        } else if (op == '-') {
            if (isStrongConnected(a, b)) {
                auto it_a = find(strong_connected[a].begin(), strong_connected[a].end(), b);
                if (it_a != strong_connected[a].end()) strong_connected[a].erase(it_a);
                auto it_b = find(strong_connected[b].begin(), strong_connected[b].end(), a);
                if (it_b != strong_connected[b].end()) strong_connected[b].erase(it_b);
            }
            auto it_a = find(adj[b].begin(), adj[b].end(), a);
            if (it_a != adj[b].end()) adj[b].erase(it_a);
            auto it_b = find(adj[a].begin(), adj[a].end(), b);
            if (it_b != adj[a].end()) adj[a].erase(it_b);
        }
    }

    return 0;
}
