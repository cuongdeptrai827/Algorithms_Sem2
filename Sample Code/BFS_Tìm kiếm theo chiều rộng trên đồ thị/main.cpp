#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 Input
 10 11
 1 2
 1 3
 1 5
 1 10
 2 4
 3 6
 3 7
 3 9
 6 7
 5 8
 8 9
 */


int n, m; // biến lưu số lượng đỉnh và số lượng cạnh
vector<int> adj[100001]; // biến lưu danh sách kề
bool visited[100001]; // biến lưu trạng thái

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

void bfs(int u) {
    // Buoc khoi tao queue
    queue<int> q;
    q.push(u);
    visited[u] = true;

    // Buoc lap
    while (q.empty() == false) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int i = 0; i < adj[v].size(); i++) {
            if (visited[adj[v][i]] == false) {
                q.push(adj[v][i]);
                visited[adj[v][i]] = true;
            }
        }
    }
}

int main() {
    input();
    bfs(1);
    return 0;
}
