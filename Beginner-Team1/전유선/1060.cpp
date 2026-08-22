#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    // 행렬 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    const int INF = 1000000000;

    vector<int> dist(n, INF);
    vector<bool> visited(n, false);

    dist[0] = 0;

    int answer = 0;

    for (int i = 0; i < n; i++) {

        // 아직 방문하지 않은 정점 중
        // dist가 가장 작은 정점 찾기
        int current = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                if (current == -1 || dist[j] < dist[current]) {
                    current = j;
                }
            }
        }

        // 방문 처리
        visited[current] = 1;

        // 비용 추가
        answer += dist[current];

        // dist 갱신
        for (int next = 0; next < n; next++) {
            if (!visited[next] &&
                mat[current][next] < dist[next]) {

                dist[next] = mat[current][next];
            }
        }
    }

    cout << answer;

    return 0;
}