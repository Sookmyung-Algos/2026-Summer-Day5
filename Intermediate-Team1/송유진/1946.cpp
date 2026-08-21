#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int cnt;
        cin >> cnt;
        if (cnt == 0) continue;
        
        int prev;
        cin >> prev;
        for (int j = 1; j < cnt; ++j) {
            int curr;
            cin >> curr;
            adj[prev].push_back(curr);
            indegree[curr]++;
            prev = curr;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        result.push_back(curr);

        for (int next : adj[curr]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if (result.size() == n) {
        for (int i = 0; i < n; ++i) {
            cout << result[i] << "\n";
        }
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
