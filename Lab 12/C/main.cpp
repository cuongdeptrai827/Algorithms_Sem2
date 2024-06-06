#include<iostream>
#include<vector>
using namespace std;

const int MAX_N = 1000000;

int hashFunction(const string& str){
    int hash = 0;
    for( char ch : str){
        hash = (hash + ch^2) % MAX_N;
    }
    return hash;
}

int main() {
    int N;
    cin >> N;

    string set1[N];
    string set2[N];

    for (int i = 0; i < N; i++)
        cin >> set1[i];

    for (int i = 0; i < N; i++)
        cin >> set2[i];

    vector<bool> hash_table_1(MAX_N, false);
    vector<bool> hash_table_2(MAX_N, false);

    for (int i = 0; i < N; i++){
        hash_table_1[hashFunction(set1[i])] = true;
    }

    for (int i = 0; i < N; i++){
        hash_table_2[hashFunction(set2[i])] = true;
    }

    for (int i = 0; i < MAX_N; i++){
        if (hash_table_1[i] != hash_table_2[i]){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
