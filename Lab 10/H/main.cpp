#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;
int n, m, k;

int min_path(int n, int m, int k, vector<vector<pair<int, int>>>& G) {
    vector<int> distances(n + 1, INF);
    distances[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int island = pq.top().second;
        pq.pop();

        if (dist > distances[island]) continue;

        for (auto& neighbor : G[island]) {
            int next = neighbor.first;
            int time = neighbor.second;
            if (dist + time < distances[next]) {
                distances[next] = dist + time;
                pq.push({distances[next], next});
            }
        }
    }

    return (distances[k] != INF) ? distances[k] : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> G(n + 1);
    for (int i = 0; i < m; i++) {
        int v, time;
        cin >> v >> time;

        vector<int> list_v(v);

        for (int j = 0; j < v; j++) {
            cin >> list_v[j];
        }
        for (int j = 0; j < v; j++) {
            for (int l = j + 1; l < v; ++l) {
                G[list_v[j]].push_back({list_v[l], time});
                G[list_v[l]].push_back({list_v[j], time});
            }
        }
    }

    cout << min_path(n, m, k, G);

    return 0;
}