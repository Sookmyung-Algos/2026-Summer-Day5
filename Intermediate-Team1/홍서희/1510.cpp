#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

vector<pair<int, int>> v;
int dp[1001];
int main()
{
    int n, h, w;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h >> w;
        if (h > w)
            swap(h, w);
        v.push_back({h, w});
    }
    fill(dp, dp + n + 1, 1);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i].first >= v[j].first && v[i].second >= v[j].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
