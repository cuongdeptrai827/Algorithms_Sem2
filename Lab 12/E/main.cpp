#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 10000000;

vector<pair<int, int>> chairTable(MAX_SIZE);
bool occupied[MAX_SIZE] = {0};
int chairHeights[MAX_SIZE];

int hashFunc(int key, int i){
    return (key^i) % MAX_SIZE;
}

void insert(int height, int index){
    int i = 0;
    bool inserted = false;
    int key;
    while(!inserted){
        key = hashFunc(abs(height - index), i * i);
        i++;
        if (!occupied[key]){
            chairTable[key] = {height, index};
            inserted = true;
            occupied[key] = true;
        }
    }
}

int countPairs(int height, int index){
    int i = 0;
    bool found = false;
    int key;
    int count = 0;
    while(!found){
        key = hashFunc(abs(height - index), i * i);
        i++;
        if (chairTable[key].first == height && chairTable[key].second == index){
            found = true;
        } else {
            if (chairTable[key].first - chairTable[key].second == height - index){
                count++;
            }
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int pairCount = 0;

    for (int i = 0; i < n; i++){
        int height; cin >> height;
        insert(height, i);
        chairHeights[i] = height;
    }


    for (int i = 0; i < n; i++){
        pairCount += countPairs(chairHeights[i], i);
    }
    cout << pairCount;
    return 0;
}