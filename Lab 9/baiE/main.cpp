#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 100000;
int N, M;
vector<int> adj[maxN];
int Num[maxN], Low[maxN], cnt;
bool Node[maxN];

struct Bridge {
    int u, v;
    bool operator<(const Bridge& other) const {
        if (u == other.u)
            return v < other.v;
        return u < other.u;
    }
};

vector<Bridge> bridges;

void tarjian(int u, int parent) {
    int Child = 0;
    Low[u] = Num[u] = ++cnt;
    for (auto v : adj[u]) {
        if (v != parent) {
            if (Num[v])
                Low[u] = min(Low[u], Num[v]);
            else {
                tarjian(v, u);
                Child++;
                Low[u] = min(Low[u], Low[v]);

                if (Low[v] > Num[u]) {
                    if (u < v)
                        bridges.push_back({u, v});
                    else
                        bridges.push_back({v, u});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= N; i++) {
        if (!Num[i]) {
            tarjian(i, i);
        }
    }

    sort(bridges.begin(), bridges.end());

    for (const auto& bridge : bridges) {
        cout << bridge.u << " " << bridge.v << endl;
    }

    return 0;
}