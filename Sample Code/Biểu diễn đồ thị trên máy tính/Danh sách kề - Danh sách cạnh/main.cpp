#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<pair<int, int>> edge;

    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        istringstream iss(s);
        string num;
        while (iss >> num) {
            if (stoi(num) > i){
                edge.push_back({i, stoi(num)});
            }
        }
    }

    for (int i = 0; i < edge.size(); i++) {
        cout << edge[i].first << " " << edge[i].second << endl;
    }

    return 0;
}