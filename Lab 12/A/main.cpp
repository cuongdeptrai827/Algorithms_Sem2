#include <iostream>
#include <vector>

using namespace std;

const int MAX_M = 50000;

int hashFunction(long long int key, int i){
    return (key + i) % MAX_M;
}

void insert(vector<pair<long long int, int>> &table1, vector<pair<long long int, int>> &table2, long long int x, long long int y){
    int i = 0;
    long long int key;
    bool inserted = false;

    while (true){
        key = hashFunction(x, i);

        if (table1[key].first == -1)   break;

        if (table1[key].first == x) {
            table1[key].second++;
            inserted = true;
            break;
        }
        i++;
    }

    if (!inserted) {
        table1[key] = {x, 1};
    }

    i = 0;
    inserted = false;

    while (true){
        key = hashFunction(y, i);
        if (table2[key].first == -1)    break;

        if (table2[key].first == y){
            table2[key].second++;
            inserted = true;
            break;
        }
        i++;
    }

    if (!inserted) table2[key] = {y, 1};
}

int search(vector<pair<long long int, int>> &table, int coordi){
    int count = 0, i = 0, key;

    while (true){
        key = hashFunction(coordi, i);
        if (table[key].first == -1) break;

        else if (table[key].first == coordi){
            return table[key].second;
        }
        i++;
    }

    return 0;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pair<long long int, int>> table1(MAX_M, {-1, -1}), table2(MAX_M, {-1, -1});
    vector<pair<long long int, long long int>> point;
    vector<bool> deleted;

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        insert(table1, table2, x, y);
        point.push_back({x, y});
    }

    int res = 0;
    for (int j = 0; j < 3; j++){
        if (point.size() == 0) continue;

        int pair_1 = 0;
        int x;

        for (int i = 0; i < point.size(); i++){
            int t = search(table1, point[i].first);

            if (pair_1 < t){
                pair_1 = t;
                x = point[i].first;
            }
        }

        int pair_2 = 0;
        int y;

        for (int i = 0; i < point.size(); i++){
            int t = search(table2, point[i].second);

            if (pair_2 < t){
                pair_2 = t;
                y = point[i].second;
            }
        }

        if    (pair_1 >= pair_2){
            int i = 0;

            while (true){
                int key = hashFunction(x, i);

                if (table1[key].first == x){
                    table1[key].first = -2;
                    table1[key].second = -2;
                    break;
                }
                i++;
            }

            auto it = point.begin();
            while (it != point.end()){
                if (it->first == x){
                    point.erase(it);
                    continue;
                }
                it++;
            }
            res += pair_1;
        }

        else{
            int i = 0;
            while (true){
                int key = hashFunction(y, i);

                if (table2[key].first == y){
                    table2[key].first = -2;
                    table2[key].second = -2;
                    break;
                }
                i++;
            }

            auto it = point.begin();
            while (it != point.end()){
                if (it->second == y){
                    point.erase(it);
                    continue;
                }
                it++;
            }
            res += pair_2;
        }
    }

    if    (point.size() == 0) cout << "YES" << "\n";
    else                      cout << "NO" << "\n";
}
