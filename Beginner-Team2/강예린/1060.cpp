#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    parent[b] = a;
}

struct Edge {
    int cost;
    int a;
    int b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    vector<vector<int>> mat(n, vector<int>(n)); 

    vector<Edge> edges;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];

            if (i < j) {
                edges.push_back({ mat[i][j], i, j });
            }
        }
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.cost < b.cost;
        });

    int answer = 0;
    int count = 0;

    for (Edge edge : edges) {
        if (find(edge.a) != find(edge.b)) {
            Union(edge.a, edge.b);

            answer += edge.cost;
            count++;

            // 간선을 n-1개 선택시 종료
            if (count == n - 1)
                break;
        }
    }

    cout << answer;

    return 0;
}
