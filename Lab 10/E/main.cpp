#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, Q;

void bridgeUtil(int u, int parent, vector<int>& disc, vector<int>& low, const vector<vector<int>>& adj, vector<pair<int, int>>& bridges) {
    static int time = 0;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (v != parent) {
            if (disc[v] == -1) {
                bridgeUtil(v, u, disc, low, adj, bridges);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
}

void findBridges(const vector<vector<int>>& adj, vector<pair<int, int>>& bridges) {
    int V = adj.size();
    vector<int> disc(V, -1);
    vector<int> low(V, -1);

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            bridgeUtil(i, -1, disc, low, adj, bridges);
        }
    }
}

void DFS(int u, vector<bool>& visited, const vector<vector<int>>& adj, vector<int>& comp) {
    visited[u] = true;
    comp.push_back(u);

    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v, visited, adj, comp);
        }
    }
}

vector<vector<int>> computeConnectedcomps(const vector<vector<int>>& adj) {
    int V = adj.size();

    vector<bool> visited(V, false);
    vector<vector<int>> comps;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> comp;
            DFS(i, visited, adj, comp);
            comps.push_back(comp);
        }
    }

    return comps;
}

bool inSameConnectedcomp(int x, int y, const vector<vector<int>>& comps) {
    for (const auto& comp : comps) {
        if (find(comp.begin(), comp.end(), x) != comp.end() && find(comp.begin(), comp.end(), y) != comp.end()) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> Q;
    N = N + 1;

    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Find and remove bridges
    vector<pair<int, int>> bridges;
    findBridges(adj, bridges);

    for (const auto& brid : bridges) {
        int u = brid.first;
        int v = brid.second;
        adj[u].erase(remove(adj[u].begin(), adj[u].end(), v), adj[u].end());
        adj[v].erase(remove(adj[v].begin(), adj[v].end(), u), adj[v].end());
    }

    // Compute connected comps in the modified graph
    vector<vector<int>> comps = computeConnectedcomps(adj);

    // Process queries
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;

        if (inSameConnectedcomp(a, b, comps)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
