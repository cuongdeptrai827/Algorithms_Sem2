#include <iostream>
#include <vector>

typedef long long ll;
const ll MOD1 = 1e9 + 7;
const ll BASE1 = 31;
const ll MOD2 = 1e9 + 9;
const ll BASE2 = 37;

using namespace std;

struct DoubleHash {
    vector<ll> hash1, hash2, power1, power2;

    DoubleHash(const string &str) {
        int N = str.size();
        hash1.assign(N + 1, 0);
        hash2.assign(N + 1, 0);
        power1.assign(N + 1, 1);
        power2.assign(N + 1, 1);

        for (int i = 1; i <= N; i++) {
            hash1[i] = (hash1[i - 1] * BASE1 + (str[i - 1] - 'a' + 1)) % MOD1;
            power1[i] = (power1[i - 1] * BASE1) % MOD1;

            hash2[i] = (hash2[i - 1] * BASE2 + (str[i - 1] - 'a' + 1)) % MOD2;
            power2[i] = (power2[i - 1] * BASE2) % MOD2;
        }
    }

    pair<ll, ll> getHash(int l, int r) {
        ll hashValue1 = (hash1[r] - hash1[l] * power1[r - l] % MOD1 + MOD1) % MOD1;
        ll hashValue2 = (hash2[r] - hash2[l] * power2[r - l] % MOD2 + MOD2) % MOD2;
        return {hashValue1, hashValue2};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    string str;
    cin >> str;

    DoubleHash dh(str);

    int cnt = 0;

    while(Q--){
        int i, j, k;
        cin >> i >> j >> k;
        i--;
        j--; // Chuyển về chỉ số 0

        auto hash1 = dh.getHash(i, i + k);
        auto hash2 = dh.getHash(j, j + k);

        if (hash1 == hash2) {
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}
