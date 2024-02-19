#include <bits/stdc++.h>
using namespace std;

// Vector luu kqua
vector<int> ans;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited) {
    // Danh dau dinh da duoc tham
    visited[node] = true;

    // Duyet qua cac dinh ke cua dinh hien tai
    for (int neighbor: graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
    // Them dinh vao dau danh sach ket qua
    ans.push_back(node + 1);
}

int main() {
    int n, m;
    bool Condition = true;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    vector<int> answer(n);

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }

    while (Condition) {
        Condition = false;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                dfs(i, graph, visited);
                Condition = true;
            }
        }
    }

    // In ket qua
    for (int i = n - 1; i >= 0; i--){
        int temp = ans[i];
        answer[temp - 1] = n - i;
    }

    for (int i = 0; i < n; i++){
        cout << answer[i] << " ";
    }

    return 0;
}
