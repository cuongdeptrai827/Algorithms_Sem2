#include <bits/stdc++.h>
using namespace std;

// Định nghĩa cấu trúc Đỉnh
struct Vertex {
    int parent; // Số nhà mà đỉnh này thuộc về
    vector<int> neighbors; // Các đỉnh kề
};

// Hàm tìm gốc của cây
int findRoot(vector<Vertex> &graph, int vertex) {
    if (graph[vertex].parent != vertex) {
        graph[vertex].parent = findRoot(graph, graph[vertex].parent);
    }
    return graph[vertex].parent;
}

int main() {
    int N, M;
    cin >> N >> M;

    // Khởi tạo đồ thị
    vector<Vertex> graph(N + 1);
    for (int i = 1; i <= N; ++i) {
        graph[i].parent = i; // Gốc ban đầu của mỗi cây là chính nó
    }

    // Đọc các cạnh và thêm vào đồ thị
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].neighbors.push_back(b);
        graph[b].neighbors.push_back(a);

        // Nếu a và b thuộc các cây khác nhau thì nối chúng lại với nhau
        int root_a = findRoot(graph, a);
        int root_b = findRoot(graph, b);
        if (root_a != root_b) {
            graph[root_b].parent = root_a;
        }
    }

    // Đếm số lượng cây và số lượng cạnh giữa các cây
    int numTrees = 0;
    int numEdges = 0;
    for (int i = 1; i <= N; ++i) {
        if (graph[i].parent == i) {
            numTrees++;
            numEdges += graph[i].neighbors.size();
        }
    }

    // Số cạnh giữa các cây được tính mỗi cạnh 2 lần, nên chia đôi
    numEdges /= 2;

    // In kết quả
    cout << numTrees << " " << numEdges << endl;

    // Duyệt qua các đỉnh, tìm gốc của cây mà đỉnh đó thuộc về
    // và in ra cặp (gốc cây, gốc cây kề)
    for (int i = 1; i <= N; ++i) {
        if (graph[i].parent == i) {
            for (int j : graph[i].neighbors) {
                int root_j = findRoot(graph, j);
                cout << i << " " << root_j << endl;
            }
        }
    }

    return 0;
}
