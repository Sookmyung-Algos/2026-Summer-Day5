// Day5 - 정올 1510 : 색종이 올려놓기
#include <bits/stdc++.h>
using namespace std;

struct Paper {
    int width;
    int height;
};

// smaller를 larger 위에 올릴 수 있는지 확인
bool canPlace(const Paper& smaller, const Paper& larger) {
    bool notRotated =
        smaller.width <= larger.width &&
        smaller.height <= larger.height;

    bool rotated =
        smaller.width <= larger.height &&
        smaller.height <= larger.width;

    return notRotated || rotated;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Paper> papers(n);

    for (int i = 0; i < n; i++) {
        cin >> papers[i].width >> papers[i].height;
    }

    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);

    /*
        i를 j 위에 올릴 수 있다면
        큰 색종이 j -> 작은 색종이 i
    */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            // i가 j 위에 올라갈 수 있음
            if (canPlace(papers[i], papers[j])) {
                graph[j].push_back(i);
                indegree[i]++;
            }
        }
    }

    queue<int> q;

    // 가장 큰 색종이 후보부터 시작
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> dp(n, 1);
    int answer = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : graph[current]) {
            dp[next] = max(dp[next], dp[current] + 1);
            answer = max(answer, dp[next]);

            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    cout << answer << '\n';

    return 0;
}
