#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> degree(n + 1, 0);
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w; 
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    vector<bool> is_apt(n + 1, false);
    for (int i = 0; i < k; ++i) {
        int apt;
        cin >> apt;
        is_apt[apt] = true;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1 && !is_apt[i]) {
            q.push(i);
        }
    }

    int removed = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        removed++;

        for (int neighbor : adj[curr]) {
            degree[neighbor]--;
            if (degree[neighbor] == 1 && !is_apt[neighbor]) {
                q.push(neighbor);
            }
        }
    }

    cout << n - removed << "\n";
    return 0;
}
