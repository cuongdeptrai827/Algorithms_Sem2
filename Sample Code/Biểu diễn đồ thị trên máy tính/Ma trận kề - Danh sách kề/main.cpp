#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> v[n + 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1][j - 1] == 1) {
                v[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int x : v[i]) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
