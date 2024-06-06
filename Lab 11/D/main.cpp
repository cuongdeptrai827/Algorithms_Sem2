#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> find_stable_pairs(vector<vector<int>>& cat_pref, vector<vector<int>>& owner_pref, int n) {
    vector<int> chosen_owner(n, -1);
    vector<int> free_cat(n);
    for (int i = 0; i < n; i++) {
        free_cat[i] = i;
    }

    vector<vector<int>> ranking(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ranking[i][owner_pref[i][j]] = j;
        }
    }

    while (!free_cat.empty()) {
        int m = free_cat[0];
        int w = cat_pref[m][0];
        cat_pref[m].erase(cat_pref[m].begin());

        if (chosen_owner[w] == -1) {
            chosen_owner[w] = m;
            free_cat.erase(free_cat.begin());
        } else {
            if (ranking[w][m] < ranking[w][chosen_owner[w]]) {
                free_cat.erase(free_cat.begin());
                free_cat.push_back(chosen_owner[w]);
                chosen_owner[w] = m;
            }
        }
    }

    vector<pair<int, int>> stable_marriage;
    for (int i = 0; i < n; i++) {
        stable_marriage.push_back(make_pair(chosen_owner[i], i));
    }

    // Sắp xếp theo thứ tự tăng dần của người đàn ông
    sort(stable_marriage.begin(), stable_marriage.end());

    return stable_marriage;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> cat_pref(n, vector<int>(n));
    vector<vector<int>> owner_pref(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cat_pref[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> owner_pref[i][j];
        }
    }

    vector<pair<int, int>> stable_marriage = find_stable_pairs(cat_pref, owner_pref, n);

    for (auto& couple : stable_marriage) {
        cout  << couple.first << " " << couple.second << "\n";
    }

    return 0;
}