#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int from, to, distance;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.distance < b.distance;
}

int findParent(vector<int>& parent, int node) {
    if (parent[node] == -1)
        return node;
    return parent[node] = findParent(parent, parent[node]);
}

void unionSets(vector<int>& parent, int u, int v) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);
    if (rootU != rootV)
        parent[rootU] = rootV;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].distance;
    }

    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(N + 1, -1);

    int minTotalDistance = 0;
    int edgesTaken = 0;

    for (int i = 0; i < M; ++i) {
        if (edgesTaken == N - 1)
            break;

        int from = edges[i].from;
        int to = edges[i].to;
        int distance = edges[i].distance;

        if (findParent(parent, from) != findParent(parent, to)) {
            unionSets(parent, from, to);
            minTotalDistance += distance;
            ++edgesTaken;
        }
    }

    cout << minTotalDistance << endl;

    return 0;
}