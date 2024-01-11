#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[1000][1000];
    cin.ignore();

    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        istringstream iss(s);
        string num;
        while (iss >> num) {
            a[i][stoi(num)] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}