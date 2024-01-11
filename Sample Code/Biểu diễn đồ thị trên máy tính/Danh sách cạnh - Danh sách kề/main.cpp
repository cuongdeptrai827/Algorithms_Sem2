#include <bits/stdc++.h>
using namespace std;

// Chuyen doi bieu dien tu danh sach canh sang danh sach ke 
int n, m;
vector<int> a[100005];

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; 
        cin >> x >> y; 
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for (int i = 1; i <= n; i++){
        cout << i << ": ";
        for (int j = 0; j < a[i].size(); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}