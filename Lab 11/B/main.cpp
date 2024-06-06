
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// Структура для представления ребра
struct Edge {
    int from, to, capacity, flow;
};

// Функция для поиска максимального потока методом Форда-Фалкерсона
int fordFulkerson(vector<vector<int>>& graph, vector<Edge>& edges, int source, int sink) {
    int n = graph.size();
    vector<vector<int>> residual(n, vector<int>(n, 0)); // Создаем остаточную сеть

    // Заполняем остаточную сеть начальными значениями
    for (const auto& edge : edges) {
        residual[edge.from][edge.to] = edge.capacity;
    }

    vector<int> parent(n); // Вектор для хранения родителей вершин в пути от истока к стоку
    int maxFlow = 0; // Инициализируем максимальный поток нулем

    // Пока существует увеличивающий путь в остаточной сети
    while (true) {
        fill(parent.begin(), parent.end(), -1); // Обнуляем вектор родителей
        queue<int> q; // Создаем очередь для поиска в ширину
        q.push(source); // Добавляем исток в очередь

        // Ищем увеличивающий путь в остаточной сети
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; ++v) {
                if (parent[v] == -1 && residual[u][v] > 0) {
                    q.push(v);
                    parent[v] = u;
                }
            }
        }

        // Если достигли стока или больше не можем найти пути, выходим из цикла
        if (parent[sink] == -1) {
            break;
        }

        int minEdge = INF;

        // Находим минимальную пропускную способность в пути
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            minEdge = min(minEdge, residual[u][v]);
        }

        // Обновляем остаточную сеть и увеличиваем максимальный поток
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= minEdge;
            residual[v][u] += minEdge;
        }

        maxFlow += minEdge;
    }

    return maxFlow;
}

int main() {
    int n, m;
    cin >> n >> m;

    int source = 0;
    int sink = n - 1;

    // Создаем граф и список ребер
    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<Edge> edges;

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; // Уменьшаем на 1, так как вершины нумеруются с 1
        v--;

        graph[u][v] = c; // Пропускная способность ребра от u к v
        edges.push_back({u, v, c, 0}); // Добавляем ребро в список ребер
    }

    // Вызываем функцию для нахождения максимального потока
    int maxFlow = fordFulkerson(graph, edges, source, sink);

    cout << maxFlow << endl;

    return 0;
}