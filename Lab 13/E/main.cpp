#include <iostream>
#include <regex>

using namespace std;

// Định nghĩa biểu thức chính quy để kiểm tra định dạng chuỗi
regex pattern(R"(^([A-Z][a-z]*){3}\d{2}((\+7((\(\d{3}\)((\d{3}-\d{4})|(-\d{3}-\d{2}-\d{2})))|(\d{10})))|((7|8)\d{10}))g\.[A-Z]{3}ul\.[A-Z][a-z]*d\.\d{2,}$)");

int main() {
    ios::sync_with_stdio(false); // Tối ưu hóa nhập/xuất
    cin.tie(nullptr); // Tháo liên kết giữa cin và cout để tăng tốc độ nhập

    // Đọc số lượng bộ kiểm tra
    string numTestsStr;
    getline(cin, numTestsStr);
    int numTests = stoi(numTestsStr); // Chuyển đổi chuỗi sang số nguyên

    // Xử lý từng bộ kiểm tra
    for (int i = 0; i < numTests; ++i) {
        string rawInput, cleanedInput;
        getline(cin, rawInput); // Đọc toàn bộ dòng đầu vào

        // Loại bỏ dấu phẩy và khoảng trắng từ chuỗi đầu vào
        for (char ch : rawInput) {
            if (ch != ',' && ch != ' ') {
                cleanedInput.push_back(ch);
            }
        }

        // Kiểm tra xem chuỗi đã làm sạch có khớp với mẫu regex hay không
        if (regex_match(cleanedInput, pattern)) {
            cout << "YES\n"; // In "YES" nếu khớp
        } else {
            cout << "NO\n"; // In "NO" nếu không khớp
        }
    }
}