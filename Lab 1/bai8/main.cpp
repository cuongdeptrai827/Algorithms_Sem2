#include <bits/stdc++.h>
using namespace std;

void tarjanDFS(int u, vector<int>& discovered, vector<int>& low, stack<int>& st,
               vector<bool>& inStack, const vector<int> graph[], vector<int>& scc,
               int& count, vector<int>& minNodeInSCC) {
    static int time = 0;
    discovered[u] = low[u] = ++time;
    st.push(u);
    inStack[u] = true;

    for (int v : graph[u]) {
        if (discovered[v] == -1) {
            tarjanDFS(v, discovered, low, st, inStack, graph, scc, count, minNodeInSCC);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], discovered[v]);
        }
    }

    if (discovered[u] == low[u]) {
        int cur;
        do {
            cur = st.top();
            st.pop();
            inStack[cur] = false;
            scc[cur] = count;
            if (minNodeInSCC[count] == -1 || cur < minNodeInSCC[count]) {
                minNodeInSCC[count] = cur;
            }
        } while (cur != u);
        count++;
    }
}

void buildGraph(const vector<vector<int>>& roadList, int numVertices, vector<int> graph[]) {
    for (const auto& road : roadList) {
        int u = road[0];
        int v = road[1];
        graph[u].push_back(v);
    }
}

int main() {
    int numVertices, numRoads;
    cin >> numVertices >> numRoads;

    vector<vector<int>> roadList(numRoads, vector<int>(2));
    vector<int> graph[numVertices + 1];

    for (int i = 0; i < numRoads; i++) {
        cin >> roadList[i][0] >> roadList[i][1];
    }

    buildGraph(roadList, numVertices, graph);

    vector<int> discovered(numVertices + 1, -1);
    vector<int> low(numVertices + 1, -1);
    vector<bool> inStack(numVertices + 1, false);
    stack<int> st;
    int count = 0;
    vector<int> scc(numVertices + 1, -1);
    vector<int> minNodeInSCC(numVertices + 1, -1);

    for (int i = 1; i <= numVertices; i++) {
        if (discovered[i] == -1) {
            tarjanDFS(i, discovered, low, st, inStack, graph, scc, count, minNodeInSCC);
        }
    }

    // Đồ thị mới biểu diễn các thành phần liên thông mạnh
    vector<vector<int>> newGraph(count);
    for (const auto& road : roadList) {
        int u = road[0];
        int v = road[1];
        if (scc[u] != scc[v]) {
            newGraph[scc[u]].push_back(scc[v]);
            newGraph[scc[v]].push_back(scc[u]);
        }
    }

    // Tìm đỉnh có số nhà nhỏ nhất trong mỗi thành phần liên thông mạnh
    vector<int> families;
    for (int i = 0; i < count; i++) {
        families.push_back(minNodeInSCC[i]);
    }

    // Đếm số lượng con đường giữa các gia đình khác nhau
    int roadCount = 0;
    set<pair<int, int>> familyRoads;

    for (int i = 0; i < count; i++) {
        for (int neighbor : newGraph[i]) {
            if (i < neighbor) {
                familyRoads.insert({families[neighbor], families[i]});
            }
        }
    }

    // In ra kết quả
    cout << count << " "; // Số lượng gia đình
    cout << familyRoads.size() << endl; // Số lượng con đường giữa các gia đình

    // In ra các con đường giữa các gia đình (đã được sắp xếp)
    for (const auto& road : familyRoads) {
        cout << road.first << " " << road.second << endl;
    }

    return 0;
}
