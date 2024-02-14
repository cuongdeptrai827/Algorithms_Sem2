#include<bits/stdc++.h>
using namespace std;

// input : n,m
int n, m;
vector<int> adj[10001];
bool visited[10001];

void dfs(int u){
    visited[u] = true;
    cout << u << " ";
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    cout << u << " ";
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
                cout << v << " ";
            }
        }
    }
}
void ConnectedComponents(){
    int ans = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++){
        if(!visited[i]) {
            ++ans;
            cout << "Cac dinh thuoc thanh phan lien thong thu " << ans << " : " << endl;
            dfs(i);
            cout << endl;
        }
    }
    cout << "So thanh phan lien thong cua do thi " << ans << endl;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ConnectedComponents();
    return 0;
}