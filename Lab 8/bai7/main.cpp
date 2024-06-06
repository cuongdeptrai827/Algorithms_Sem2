#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y, z, h;
};

struct Node {
    ll x, y, z;
    ll energy;

    bool operator<(const Node& other) const {
        return energy > other.energy;
    }
};

vector<Point> plants;

void bfs(const Point& start, unordered_map<int, unordered_map<int, unordered_map<int, int>>>& dist, int E) {
priority_queue<Node> pq;
pq.push({start.x, start.y, start.z, 0});

while (!pq.empty()) {
Node current = pq.top();
pq.pop();

if (current.energy > E)
continue;

for (const Point& plant : plants) {
ll energyNeededToPlant = abs(current.x - plant.x) + abs(current.y - plant.y) + abs(current.z - plant.z);
if (energyNeededToPlant <= E - current.energy) {
int x_diff = plant.x - current.x;
int y_diff = plant.y - current.y;
int z_diff = plant.z - current.z;
if (dist[current.x][current.y][current.z] == 0 || dist[current.x][current.y][current.z] > current.energy + energyNeededToPlant) {
dist[current.x][current.y][current.z] = current.energy + energyNeededToPlant;
pq.push({plant.x, plant.y, plant.z, current.energy + energyNeededToPlant});
}
}
}

// Move in all 6 directions
for (int dx = -1; dx <= 1; ++dx) {
for (int dy = -1; dy <= 1; ++dy) {
for (int dz = -1; dz <= 1; ++dz) {
if (abs(dx) + abs(dy) + abs(dz) != 1) {
continue; // Skip diagonals and staying in the same place
}
ll nx = current.x + dx;
ll ny = current.y + dy;
ll nz = current.z + dz;
if (nx >= 1 && nx <= 100 && ny >= 1 && ny <= 100 && nz >= 1 && nz <= 100) {
if (dist[nx][ny][nz] == 0 || dist[nx][ny][nz] > current.energy + 1) {
dist[nx][ny][nz] = current.energy + 1;
pq.push({nx, ny, nz, current.energy + 1});
}
}
}
}
}
}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K, E;
    cin >> K >> E;

    ll xs, ys, zs; // Changed to long long
    cin >> xs >> ys >> zs;

    ll xf, yf, zf; // Changed to long long
    cin >> xf >> yf >> zf;

    plants.resize(K);
    for (int i = 0; i < K; ++i) {
        cin >> plants[i].x >> plants[i].y >> plants[i].z >> plants[i].h;
    }

    Point start = {xs, ys, zs, 0};

    unordered_map<int, unordered_map<int, unordered_map<int, int>>> dist;
    bfs(start, dist, E);

    if (dist[xf][yf][zf] != 0)
        cout << dist[xf][yf][zf] << endl;
    else
        cout << "-1" << endl;

    return 0;
}