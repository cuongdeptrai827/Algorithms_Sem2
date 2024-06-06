#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int *arr = new int[n];
    vector<int> ans;

    // Read input array in reverse order
    for (int i = n - 1; i >= 0; i--) {
        cin >> arr[i];
    }

    // Calculate the starting index
    int start = n / 2;
    if (n % 2 == 1) {
        start++;
    }

    // Check for symmetric subsequences
    for (int i = start; i < n; i++) {
        bool check = true;
        int jump = 1;
        for (int j = i; j < n; j++) {
            if (arr[j] != arr[j - jump]) {
                check = false;
                break;
            }
            jump += 2;
        }
        if (check) {
            ans.push_back(i);
        }
    }

    // Print the indices of symmetric subsequences
    ans.push_back(n);
    for (auto i : ans) {
        cout << i << " ";
    }

    delete[] arr; // Clean up dynamic memory
    return 0;
}