#include <iostream>
#include <vector>
using namespace std;

// THUAT TOAN DFS DOI VOI DO THI VO HUONG

int m, n; // Luu so luong dinh va so luong canh
vector<int> adj[100000]; // Luu danh sach ke
bool visited[100000]; // Check du lieu da duoc visited hay chua

void intput(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        // Doi voi do thi co huong, thuat toan khong co gi thay doi,
        // chi can loai bo " adj[b].push_back(a); "  la bai toan tro thanh co huong
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < adj[i].size(); j++){
            visited[adj[i][j]] = false;
        }
    }
}

void DFS(int node){
    cout << node << " ";
    visited[node] = true;
    for(int i = 0;i < adj[node].size(); i++){
        if(!visited[adj[node][i]]){
            DFS(adj[node][i]);
        }
    }
}

int main() {
    intput();
    DFS(1);
    return 0;
}
