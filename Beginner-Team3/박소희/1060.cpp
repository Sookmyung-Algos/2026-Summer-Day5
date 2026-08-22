#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N;
int mat[102][102];
int parent[100001];

int find(int x){ 
    if (parent[x] == x) return x;
    return parent[x] = find (parent[x]);
}

bool unionNodes(int u, int v){ // 각 집합의 루트 조회 후 연결
    int rootU = find(u); 
    int rootV = find(v);
    if (rootU == rootV) // 이미 같은 집합이면
        return false;
    parent[rootU] = rootV; //rootV가 rootU의 부모
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> mat[i][j];
        }
    }

    vector<tuple<int, int, int>> edges;

    for (int i = 1; i <= N; i++){ 
        for (int j = i + 1; j <= N; j++){
            if (mat[i][j] != 0)
                edges.push_back({mat[i][j], i, j});
        }
    }
    sort(edges.begin(), edges.end()); // kruskal 알고리즘 수행을 위한 정렬

    for (int i = 1; i <= N; i++) // 부모는 자기 자신
        parent[i] = i;

    long long total = 0;

    for (auto [w, u, v] : edges) { 
        if (unionNodes(u, v)) { // 두 집합이 합쳐지면
            total += w;
        }
    }

    cout << total << '\n';

    return 0;
}