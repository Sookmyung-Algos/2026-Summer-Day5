#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> min_cost(n, INT_MAX);
    vector<bool> visited(n, false);

    // 0번 노드부터 시작
    min_cost[0] = 0;
    int total_cost = 0;

    for (int step = 0; step < n; step++) {
        int u = -1;
        int min_val = INT_MAX;

        // 아직 방문하지 않은 정점 중 최소 연결 비용을 가진 정점 선택
        for (int i = 0; i < n; i++) {
            if (!visited[i] && min_cost[i] < min_val) {
                min_val = min_cost[i];
                u = i;
            }
        }

        visited[u] = true;
        total_cost += min_val;

        // u 정점을 통해 연결할 수 있는 인접 정점들의 최소 비용 갱신
        for (int v = 0; v < n; v++) {
            if (!visited[v] && mat[u][v] < min_cost[v]) {
                min_cost[v] = mat[u][v];
            }
        }
    }

    cout << total_cost << "\n";

    return 0;
}