#include<bits/stdc++.h>
using namespace std;
/*
TÌM ĐƯỜNG ĐI GIỮA 2 ĐỈNH TRÊN ĐỒ THỊ ( CÓ HƯỚNG và VÔ HƯỚNG ) :  Code tương tự thuật toán dfs và bfs, tuy nhiên
 duy trì thêm mảng parent[] để truy vết đường đi. Giả sử cần tìm đường đi từ đỉnh s tới đỉnh t, ta gọi bfs(s) hoặc dfs(s).
*/

// input : n, m
int n, m, s, t;
vector<int> adj[1001]; // danh sach ke
bool visited[1001]; // luu cac dinh da duoc tham
int parent[1001]; // Luu dinh cha cua cac dinh

void dfs(int u){
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(!visited[v]){
            // ghi nhan cha cua v la u
            parent[v] = u;
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v= q.front();
        q.pop();
        for(int i = 0; i < adj[v].size(); i++){
            int w = adj[v][i];
            if(!visited[w]){
                // ghi nhan cha cua v la u
                parent[w] = v;
                q.push(w);
                visited[w] = true;
            }
        }
    }
}

// Thu tuc tim duong di giua dinh s toi dinh t
void Path(int s, int t){
    memset(visited, false, sizeof(visited));
    memset(parent, 0 , sizeof(parent));
    dfs(s);
    if(!visited[t]){
        cout << " NO " << endl;
    }
    else{
        cout << " YES " << endl;
        // Truy vet duong di tu dinh s toi dinh t
        vector<int> path; // vector de luu duong di
        // Bat dau tu dinh t
        while(t != s){
            path.push_back(t);
            // Lan nguoc lai
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for(int i = 0; i < path.size(); i++){
            cout << path[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        //adj[b].push_back(a); ( Trong truong hop do thi co huong )
    }
    cin >> s >> t;
    Path(s, t);
    return 0;
}
