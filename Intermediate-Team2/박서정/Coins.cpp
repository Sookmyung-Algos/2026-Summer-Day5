#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> g(3);
    vector<int> indeg(3, 0);

    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;

        int a = s[0] - 'A';
        int b = s[2] - 'A';

        if (s[1] == '>') swap(a, b);

        g[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;

    for (int i = 0; i < 3; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    string ans;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        ans += char('A' + cur);

        for (int nxt : g[cur]) {
            if (--indeg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    if (ans.size() != 3)
        cout << "Impossible\n";
    else
        cout << ans << '\n';

    return 0;
}