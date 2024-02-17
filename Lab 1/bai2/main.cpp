#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& ids, vector<int>& lows, vector<bool>& on_stack, stack<int>& node_stack, vector<vector<int>>& scc, int& id, int node) {
    ids[node] = lows[node] = id++;
    node_stack.push(node);
    on_stack[node] = true;

    for (int neighbor : graph[node]) {
        if (ids[neighbor] == -1) {
            dfs(graph, ids, lows, on_stack, node_stack, scc, id, neighbor);
            lows[node] = min(lows[node], lows[neighbor]);
        } else if (on_stack[neighbor]) {
            lows[node] = min(lows[node], ids[neighbor]);
        }
    }

    if (ids[node] == lows[node]) {
        vector<int> component;
        while (true) {
            int cur_node = node_stack.top();
            node_stack.pop();
            on_stack[cur_node] = false;
            component.push_back(cur_node);
            if (cur_node == node) {
                break;
            }
        }
        scc.push_back(component);
    }
}

vector<vector<int>> tarjan_scc(vector<vector<int>>& graph, int n) {
    vector<int> ids(n, -1);
    vector<int> lows(n, -1);
    vector<bool> on_stack(n, false);
    stack<int> node_stack;
    vector<vector<int>> scc;
    int id = 0;

    for (int i = 0; i < n; ++i) {
        if (ids[i] == -1) {
            dfs(graph, ids, lows, on_stack, node_stack, scc, id, i);
        }
    }

    return scc;
}

bool is_reachable(vector<vector<int>>& graph, int a, int b, vector<vector<int>>& scc) {
    int n = graph.size();
    vector<int> scc_id(n, -1);
    for (int i = 0; i < scc.size(); ++i) {
        for (int node : scc[i]) {
            scc_id[node] = i;
        }
    }
    return scc_id[a] == scc_id[b];
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;
        graph[start - 1].push_back(end - 1);
    }

    vector<vector<int>> scc = tarjan_scc(graph, n);

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        bool reachable = is_reachable(graph, a - 1, b - 1, scc);
        if (reachable) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
