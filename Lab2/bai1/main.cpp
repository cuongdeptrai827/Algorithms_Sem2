#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    // Tạo vector chứa tập hợp các sự kết nối giữa các cặp giấc mơ
    vector<unordered_set<int>> dreams(n + 1);

    // Đọc các sự kết nối và lưu vào vector
    for (int i = 0; i < m; ++i) {
        int A, B;
        cin >> A >> B;
        dreams[A].insert(B);
        dreams[B].insert(A);
    }

    // Xử lý các truy vấn của narrator
    for (int i = 0; i < q; ++i) {
        char type;
        int A, B;
        cin >> type >> A >> B;

        if (type == '?') {
            // Kiểm tra xem A và B có kết nối không
            if (dreams[A].find(B) != dreams[A].end() || dreams[B].find(A) != dreams[B].end()) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (type == '-') {
            // Xóa kết nối giữa A và B
            dreams[A].erase(B);
            dreams[B].erase(A);
        }
    }

    return 0;
}
