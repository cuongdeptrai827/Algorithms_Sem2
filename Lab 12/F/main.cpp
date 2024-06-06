

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_M = 3000000;


long long linearProbingHash(int func, long long key){
    if(func == 1){
        return (key % MAX_M);
    }
    else if (func == 2){
        const double A = 0.6180339887449;
        return static_cast<long long>((static_cast<long double>(key) * A) + 1) % MAX_M;
    }
    return -1;
}


long long stringHash(const string& str){
    long long hash = 0;
    for (char c : str)
        hash = (hash * 1181 + c) % MAX_M;
    return hash;
}


void insert(vector<long long> &table, string value){
    long long hashValue = stringHash(value); // Băm giá trị chuỗi


    long long index1 = linearProbingHash(1, hashValue);


    if (table[index1] == -1) {
        table[index1] = hashValue;
        return;
    }

    long long index2 = linearProbingHash(2, hashValue);
    if (table[index2] == -1) {
        table[index2] = hashValue;
        return;
    }


    long long tryCount = 100;
    while(tryCount > 0){
        long long newHashValue = table[index1];
        table[index1] = hashValue;
        hashValue = newHashValue;


        index1 = linearProbingHash(1, hashValue);
        if (table[index1] == -1) {
            table[index1] = hashValue;
            return;
        }

        index2 = linearProbingHash(2, hashValue);
        if (table[index2] == -1) {
            table[index2] = hashValue;
            return;
        }
        tryCount--;
    }
}


bool search(const vector<long long> &table, const string& value){
    long long hashValue = stringHash(value);
    long long index1 = linearProbingHash(1, hashValue);


    if (table[index1] == hashValue) {
        return true;
    }

    long long index2 = linearProbingHash(2, hashValue);
    if (table[index2] == hashValue) {
        return true;
    }

    return false;
}

int main(){
    int n;
    cin >> n;

    vector<vector<long long>> table(2, vector<long long>(MAX_M, -1));

    string value;
    int score[3] = {0, 0, 0};


    for (int i = 0; i < n; i++){
        cin >> value;
        insert(table[0], value);
        score[0] += 3;
    }


    for (int i = 0; i < n; i++){
        cin >> value;
        insert(table[1], value);

        if (search(table[0], value)){
            score[0] -= 2;
            score[1] += 1;
        }
        else{
            score[1] += 3;
        }
    }


    for (int i = 0; i < n; i++){
        cin >> value;
        bool checkGroup1 = search(table[0], value);
        bool checkGroup2 = search(table[1], value);


        if (checkGroup1 && checkGroup2){
            score[0] -= 1;
            score[1] -= 1;
        }
        else if(checkGroup1){
            score[0] -= 2;
            score[2] += 1;
        }
        else if(checkGroup2){
            score[1] -= 2;
            score[2] += 1;
        }
        else{
            score[2] += 3;
        }
    }


    for(int i = 0; i < 3; i++){
        cout << score[i] << " ";
    }

    return 0;
}
