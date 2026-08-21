#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> parentNode;
vector<int> dp;

int solve(int x) {
    if (dp[x] != -1) return dp[x];
    if (parentNode[x] == -1) return dp[x] = 1;
    return dp[x] = solve(parentNode[x]) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    parentNode.resize(n + 1);
    dp.assign(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        cin >> parentNode[i];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans = max(ans, solve(i));
    }

    cout << ans << '\n';

    return 0;
}