#include <iostream>
#include <vector>

using namespace std;

const int MAX_GROUPS = 10005;
const int TABLE_SIZE = 1000;

pair<int, int> hashTable[MAX_GROUPS][TABLE_SIZE];
int groupSize[MAX_GROUPS];
int groupSum[MAX_GROUPS];
int groupPoints[MAX_GROUPS][101];
bool groupOccupied[MAX_GROUPS][TABLE_SIZE];

int HashFunction(int key, int i){
    key = (key + i) % TABLE_SIZE;
    return key;
}

void insert(int group, int isu, int points){
    int i = 0;
    bool inserted = false;

    int hashIndex;
    while(!inserted){
        hashIndex = HashFunction(isu, i * i);
        i++;
        if (!groupOccupied[group][hashIndex]){
            hashTable[group][hashIndex] = {isu, points};
            inserted = true;
            groupOccupied[group][hashIndex] = true;
        }
    }
    groupSize[group]++;
    groupSum[group] += points;
    groupPoints[group][points]++;
}

void remove(int group, int isu){
    int i = 0;
    bool found = false;
    int hashIndex;
    int points;
    while(!found){
        hashIndex = HashFunction(isu, i * i);
        i++;
        if (hashTable[group][hashIndex].first == isu){
            points = hashTable[group][hashIndex].second;
            found = true;
            hashTable[group][hashIndex].first = 0;
            hashTable[group][hashIndex].second = 0;
            groupOccupied[group][hashIndex] = false;
        }
    }
    groupSize[group]--;
    groupSum[group] -= points;
    groupPoints[group][points]--;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int M, Q;
    cin >> M >> Q;
    unsigned int group, isu, points;
    char command;

    for(unsigned int i = 0; i < Q; i++){
        cin >> command;
        switch(command){
            case 'a':
                cin >> group;
                cout << (groupSize[group] == 0 ? 0 : groupSum[group] / groupSize[group]) << "\n";
                break;

            case '+':
                cin >> group >> isu >> points;
                insert(group, isu, points);
                break;

            case '-':
                cin >> group >> isu;
                remove(group, isu);
                break;

            case 'm':
                cin >> group;
                for (int j = 100; j >= 0; j--){
                    if (groupPoints[group][j] > 0){
                        cout << j << "\n";
                        break;
                    }
                }
                break;
        }
    }
    return 0;
}
