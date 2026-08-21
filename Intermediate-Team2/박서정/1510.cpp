#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> paper(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b) swap(a, b);

        paper[i] = { a, b };
    }

    sort(paper.begin(), paper.end(), [](auto a, auto b) {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second > b.second;
        });

    vector<int> dp(n, 1);
    int ans = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (paper[j].first >= paper[i].first &&
                paper[j].second >= paper[i].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}