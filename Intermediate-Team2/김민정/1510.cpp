#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1005], b[1005];
    vector<int> graph[1005];
    int indegree[1005] = {0};
    int dp[1005];

    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];

        if(a[i] > b[i])
            swap(a[i], b[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j)
                continue;

            if(a[i] >= a[j] && b[i] >= b[j]) {
                graph[i].push_back(j);
                indegree[j]++;
            }
        }
    }

    queue<int> q;

    for(int i = 0; i < n; i++) {
        dp[i] = 1;

        if(indegree[i] == 0)
            q.push(i);
    }

    int ans = 1;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int next : graph[now]) {
            dp[next] = max(dp[next], dp[now] + 1);
            ans = max(ans, dp[next]);

            indegree[next]--;

            if(indegree[next] == 0)
                q.push(next);
        }
    }

    cout << ans;

    return 0;
}
