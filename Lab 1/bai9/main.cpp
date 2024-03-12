#include <iostream>
#include <vector>

using namespace std;

void DFS(int node, vector<bool>& visited, const vector<vector<int>>& adjacency_list, int& count_edges, bool& has_cycle) {
    visited[node] = true;
    for (int neighbor : adjacency_list[node]) {
        count_edges++;
        if (!visited[neighbor]) {
            DFS(neighbor, visited, adjacency_list, count_edges, has_cycle);
        } else {
            has_cycle = true;
        }
    }
}

bool is_hydra(int n, vector<vector<int>>& adjacency_list) {
    vector<bool> visited(n + 1, false);
    bool has_cycle = false;
    int count_edges = 0;

    // Kiểm tra số lượng components
    int components = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            components++;
            DFS(i, visited, adjacency_list, count_edges, has_cycle);
        }
    }

    // Kiểm tra số lượng cycle và components
    if (components == 1 && has_cycle && count_edges == 2 * n) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacency_list(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }

    if (is_hydra(n, adjacency_list)) {
        cout << "ARCHIMEDES" << endl;
    } else {
        cout <<"EUCLID" << endl;
    }

    return 0;
}
