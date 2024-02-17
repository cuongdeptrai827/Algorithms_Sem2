#include<bits/stdc++.h>
using namespace std;

const int maxn = 10001;
int n, m;
vector<int> adj[maxn];
bool visited[maxn];
vector<int> topo; // Dung de luu thu tu topo

void input(){
    cin >> n >> m;
    for(int i=0; i < m; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    memset(visited, false, sizeof(visited));
}

void dfs(int u){
    visited[u] = true;
    for(int i=0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(!visited[v]){
            dfs(v);
        }
    }
    topo.push_back(u);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();

    for(int i=1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    reverse(topo.begin(), topo.end());

    for(int i=0; i < topo.size(); i++){
        cout << topo[i] << " ";
    }
    return 0;
}