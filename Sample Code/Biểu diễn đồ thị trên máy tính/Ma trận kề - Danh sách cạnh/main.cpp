#include<bits/stdc++.h>
using namespace std; 

int n; 
vector <pair<int, int>> edge;
int  a[1001][1001];

int main(){
    cin >> n; 

    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n ; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n ; j++) {
            if (a[i][j] == 1 && i < j) {
                edge.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < edge.size(); i++) {
        cout << edge[i].first << " " << edge[i].second << endl;
    }

    return 0;
}  