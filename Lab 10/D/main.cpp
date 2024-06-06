#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

const long long maxN = 500000;
long long N, M;
vector<pair<long long, long long>> roads;
vector<long long> adj[maxN];
long long degree[maxN];

void findEulerCycle(long long start) {
    vector<long long> EulerCycle;
    stack<long long> st;
    st.push(start);

    while (!st.empty()) {
        long long v = st.top();
        if (!adj[v].empty()) {
            long long u = adj[v].front(); // Choose smallest edge number from the front
            adj[v].erase(adj[v].begin()); // Remove the edge

            // Remove edge from the adjacent vertex
            auto it = find(adj[u].begin(), adj[u].end(), v);
            adj[u].erase(it);
            st.push(u);
        }
        else {
            st.pop();
            EulerCycle.push_back(v);
        }
    }

    // Check if Eulerian cycle is valid
    if (EulerCycle.size() < M) {
        cout << ":(";
        return;
    }

    // Output Eulerian cycle in reverse order
    for (int i = EulerCycle.size() - 1; i >= 0; --i) {
        cout << EulerCycle[i] << " ";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (long long i = 0; i < M; i++) {
        long long x, y;
        cin >> x >> y;
        roads.push_back({min(x, y), max(x, y)});
    }


    for (auto road : roads) {
        long long x = road.first;
        long long y = road.second;
        adj[x].push_back(y);
        adj[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }

    // Check if each vertex has even degree
    for (long long v = 1; v <= N; v++) {
        if ((degree[v] % 2) != 0) {
            cout << ":(";
            return 0;
        }
    }

    findEulerCycle(1);

    return 0;
}
