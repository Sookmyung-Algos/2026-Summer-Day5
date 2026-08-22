#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int parent[105];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;

    parent[b] = a;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector<tuple<int, int, int>> edges;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int cost;
            cin >> cost; 
            if (i != j) {
                edges.push_back({cost, i, j});
            }
        }
    }

    for (int i=0; i<N; i++) parent[i] = i; 

    sort(edges.begin(), edges.end());

    int total = 0;
    int count = 0;

    for (auto [cost, a, b] : edges) {
        if (unite(a, b)) {
            total += cost;
            count++;

            if (count == N - 1) break;
        }
    }
    cout << total;
}