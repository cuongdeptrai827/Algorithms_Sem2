#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> findN(string spell) {
    int n = spell.length();
    vector<int> result(n, 0);
    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && spell[i] != spell[j])
            j = pi[j - 1];
        if (spell[i] == spell[j])
            j++;
        pi[i] = j;
    }

    for (int i = 0; i < n; i++) {
        result[i] = pi[i];
    }

    return result;
}

int main() {
    string spell;
    cin >> spell;

    vector<int> result = findN(spell);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}