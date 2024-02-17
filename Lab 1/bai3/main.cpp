#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &visited, const vector<vector<int>> &adjacency_list) {
    visited[node] = true;
    for (int neighbor : adjacency_list[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adjacency_list);
        }
    }
}

int count_connected_components(int N, const vector<pair<int, int>> &connections) {
    vector<vector<int>> adjacency_list(N + 1);
    vector<bool> visited(N + 1, false);

    // Tạo danh sách kề từ các kết nối
    for (const auto &connection : connections) {
        int i = connection.first;
        int j = connection.second;
        adjacency_list[i].push_back(j);
        adjacency_list[j].push_back(i);
    }

    int connected_components = 0;
    for (int node = 1; node <= N; ++node) {
        if (!visited[node]) {
            dfs(node, visited, adjacency_list);
            connected_components++;
        }
    }

    return connected_components;
}

int main() {
    int  n, m;
    cin >> n >> m;

    vector<pair<int, int>> connections(m);
    for (int i = 0; i < m; ++i) {
        cin >> connections[i].first >> connections[i].second;
    }

    cout << count_connected_components(n, connections) << endl;

    return 0;
}
