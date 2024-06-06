#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;

// Định nghĩa cấu trúc Edge
struct Edge {
    int u, v, weight ;

    // So sánh cạnh theo trọng số
    bool operator<(const Edge& other) const {
        return weight  < other.weight ;
    }
};

// Định nghĩa cấu trúc Set để sử dụng trong thuật toán Kruskal
struct Set {
    vector<int> parent ;
    vector<int> rank;

    // Khởi tạo
    Set(int n) : parent (n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent [i] = i;
        }
    }

    void make(int v) {
        parent [v] = v;
        rank[v] = 0;
    }

    // Tìm phần tử đại diện của tập hợp
    int find(int v) {
        if (v == parent [v])
            return v;
        return parent [v] = find(parent [v]);
    }

    // Gom nhóm hai tập hợp
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent [b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};


// Hàm DFS để tính chuỗi dài nhất từ một đỉnh
void dfs(const vector<vector<pair<int, int>>>& G, int vertices, vector<bool>& visited, vector<int>& a, vector<int>& b, vector<int>& c) {
    visited[vertices] = true;

    for (int i = 0; i < G[vertices].size(); i++) {
        int v = G[vertices][i].first;
        int w = G[vertices][i].second;
        if (!visited[v]) {
            dfs(G, v, visited, a, b, c);
            if (b[v] + w - c[v] > a[vertices]) {
                a[vertices] = b[v] + w - c[v];
            }
            b[vertices] += c[v];
        }
    }

    a[vertices] += b[vertices];
    c[vertices] = max(a[vertices], b[vertices]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    vector<Edge> edges(M);
    vector<vector<pair<int, int>>> G(N);
    vector<int> a(N, 0), b(N, 0), c(N, 0);
    vector<bool> visited(N, false);

    Set group(N);

    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight ;
        edges[i].u--;
        edges[i].v--;
    }
    for (int i = 0; i < N; i++)
        group.make(i);

    sort(edges.begin(), edges.end());

    for (int i = 0; i < M; i++) {
        Edge curr = edges[i];
        if (group.find(curr.u) != group.find(curr.v)) {
            group.merge(curr.u, curr.v);
            G[curr.u].push_back(make_pair(curr.v, curr.weight ));
            G[curr.v].push_back(make_pair(curr.u, curr.weight ));
        }
    }

    dfs(G, 0, visited, a, b, c);

    cout << c[0];
    return 0;
}