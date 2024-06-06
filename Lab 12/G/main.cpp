#include "blazingio.hpp"
#include <cmath>
#include <vector>

using namespace std;

double hashFunction(int key, int n){
    double X =  0.618033988749895;
    return fmod(((key + X) * X * n), 1.0);
}

bool compare_tree(int tr1[], int tr2[], int n){
    double k1 = 0.0, k2 = 0.0;

    for (int i = 0; i < n; i++){
        k1 += hashFunction(tr1[i], n);
    }

    for (int i = 0; i < n; i++){
        k2 += hashFunction(tr2[i], n);
    }

    double epsilon = 0.0000000001;

    if (fabs(k1 - k2) < epsilon){
        return true;
    } else{
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int tree1[n], tree2[n];

    for(int i = 0; i < n; i++){
        tree1[i] = tree2[i] = 0;
    }

    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tree1[a]++;
        tree1[b]++;
    }

    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tree2[a]++;
        tree2[b]++;
    }

    cout << (compare_tree(tree1, tree2, n) ? "YES" : "NO");

    return 0;
}
