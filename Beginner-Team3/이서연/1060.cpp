#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> cost(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }

    vector<int> minCost(N, 1000000000);
    vector<bool> visited(N, false);

    minCost[0] = 0;

    int answer = 0;

    for (int i = 0; i < N; i++) {

        int now = -1;


        for (int j = 0; j < N; j++) {
            if (!visited[j] &&
                (now == -1 || minCost[j] < minCost[now])) {
                now = j;
            }
        }

        visited[now] = true;
        answer += minCost[now];

        for (int j = 0; j < N; j++) {
            if (!visited[j]) {
                minCost[j] = min(minCost[j], cost[now][j]);
            }
        }
    }

    cout << answer << '\n';

    return 0;
}