#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<int, vector<int>> findPresidentName(const string& T, const string& X) {
    int count = 0;
    vector<int> indices;
    size_t pos = T.find(X);

    while (pos != string::npos) {
        count++;
        indices.push_back(pos);
        pos = T.find(X, pos + 1);
    }

    return make_pair(count, indices);
}

int main() {
    string T, X;
    getline(cin, T); // Ввод текста гимна
    getline(cin, X); // Ввод имени правителя

    pair<int, vector<int>> result = findPresidentName(T, X);

    cout << result.first << endl; // Вывод количества упоминаний

    for (int index : result.second) {
        cout << index << " "; // Вывод индексов упоминаний
    }
    cout << endl;

    return 0;
}
