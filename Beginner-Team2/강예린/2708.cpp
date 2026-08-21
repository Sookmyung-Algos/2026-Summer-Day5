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

    int m, n;

    while (cin >> m >> n) {

        // 0 0이면 종료
        if (m == 0 && n == 0)
            break;

        parent.resize(m);

        for (int i = 0; i < m; i++) {
            parent[i] = i;
        }

        vector<Edge> edges;
        int total = 0;

        for (int i = 0; i < n; i++) {
            int a, b, cost;
            cin >> a >> b >> cost;

            edges.push_back({ cost, a, b });

            total += cost;
        }

        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.cost < b.cost;
            });

        int mst = 0;

        for (Edge edge : edges) {
            if (find(edge.a) != find(edge.b)) {
                Union(edge.a, edge.b);
                mst += edge.cost;
            }
        }

        cout << total - mst; //최소비용이 아니고 절약할 수있는 금액을 출력해야함
    }

    return 0;
}