#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> parent;
int N, M;

struct Edge {
    int u, v, w;
};

int findParent(int u) {
    if (parent[u] == u) return u;
    return parent[u] = findParent(parent[u]);
}

void unionSets(int u, int v) {
    u = findParent(u);
    v = findParent(v);
    parent[u] = v;
}

int kruskal(vector<Edge>& edges, vector<int>& mstEdges) {
    int mst = 0;
    for (const auto& edge : edges) {
        if (findParent(edge.u) != findParent(edge.v)) {
            mst += edge.w;
            mstEdges.push_back(edge.w);
            unionSets(edge.u, edge.v);
        }
    }
    return mst;
}

int secondBestMST(vector<Edge>& edges, const vector<int>& mstEdges) {
    int secondMST = INT_MAX;
    for (int i = 0; i < mstEdges.size(); i++) {
        vector<int> tempMSTEdges;
        parent = vector<int>(N + 1);

        for(int i = 0; i <= N; i++){
            parent[i] = i;
        }

        int wei = 0;
        for (int j = 0; j < edges.size(); j++) {
            if (edges[j].w == mstEdges[i]) continue;

            if (findParent(edges[j].u) != findParent(edges[j].v)) {
                wei += edges[j].w;
                tempMSTEdges.push_back(edges[j].w);
                unionSets(edges[j].u, edges[j].v);
            }
        }

        if (tempMSTEdges.size() == N - 1) {
            secondMST = min(secondMST, wei);
        }
    }

    return secondMST;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    vector<Edge> edges(M);
    vector<int> mstEdges;

    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    parent = vector<int>(N + 1);

    for(int i = 0; i <= N; i++){
        parent[i] = i;
    }

    int mst = kruskal(edges, mstEdges);
    cout << mst << " ";

    int secondMST = secondBestMST(edges, mstEdges);
    cout << secondMST;

    return 0;
}