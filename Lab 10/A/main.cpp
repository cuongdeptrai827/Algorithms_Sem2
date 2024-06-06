#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;

void dfs(int v) {
    for (int u : adj[v]) {
        if (u != parent[v]) {
            parent[u] = v;
            dfs(u);
        }
    }
}

void fromTreeToPrufer(int n) {
    parent.resize(n);
    parent[n-1] = -1;
    dfs(n-1);

    int pointer = -1;
    vector<int> degree(n);

    for (int i = 0; i < n; i++) {
        degree[i] = adj[i].size();
        if (degree[i] == 1 && pointer == -1)
            pointer = i;
    }

    vector<int> result(n - 2);
    int leaf = pointer;
    for (int i = 0; i < n - 2; i++) {
        int next = parent[leaf];
        cout << next + 1 << " ";
        if (--degree[next] == 1 && next < pointer) {
            leaf = next;
        } else {
            pointer++;
            while (degree[pointer] != 1){
                pointer++;
            }

            leaf = pointer;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }

    fromTreeToPrufer(n);

    return 0;
}
