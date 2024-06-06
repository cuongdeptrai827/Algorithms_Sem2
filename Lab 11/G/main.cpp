#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    queue<int> ds_dinh;
    vector<bool> visited(N, false);
    for (int i = 0; i < M; i++) {
        int v, u;
        cin >> v >> u;
        if (!visited[v]) {
            ds_dinh.push(v);
            visited[v] = true;
        }
        if (!visited[u]) {
            ds_dinh.push(u);
            visited[u] = true;
        }
    }
    while (!ds_dinh.empty()) {
        cout << ds_dinh.front() << " ";
        ds_dinh.pop();
    }
}
