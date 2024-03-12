#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1); // Resize to n+1, as indexing starts from 1
    adj_rev.resize(n + 1); // Resize to n+1, as indexing starts from 1
    used.assign(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
        if (!used[i])
            dfs1(i);

    used.assign(n + 1, false);
    reverse(order.begin(), order.end());

    int num_components = 0;
    for (auto v : order)
        if (!used[v]) {
            dfs2(v);
            ++num_components;

            component.clear();
        }

    vector<int> roots(n + 1, 0);
    vector<int> root_nodes;

    for (auto v : order)
        if (!used[v]) {
            dfs2(v);

            int root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.push_back(root);

            component.clear();
        }

    vector<vector<int>> adj_scc(n + 1);

    for (int v = 1; v <= n; ++v)
        for (auto u : adj[v]) {
            int root_v = roots[v],
                    root_u = roots[u];

            if (root_u != root_v)
                adj_scc[root_v].push_back(root_u);
        }

    int num_edges_between_scc = 0;
    for (int i = 1; i <= n; ++i)
        for (auto j : adj_scc[i])
            ++num_edges_between_scc;

    cout << num_components << " " << num_edges_between_scc << endl;

    for (int i = 1; i <= n; ++i)
        for (auto j : adj_scc[i])
            cout << i << " " << j << endl;

    return 0;
}
