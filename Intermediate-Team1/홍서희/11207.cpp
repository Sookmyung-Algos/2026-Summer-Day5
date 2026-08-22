#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

vector<int> v[100001];
bool is_apt[100001] = {
    false,
};
bool removed[100001] = {
    false,
};
int deg[100001];

int main()
{
    int n, k;
    cin >> n >> k;
    int i, j, w;
    for (int it = 0; it < n - 1; it++)
    {
        cin >> i >> j >> w;
        v[i].push_back(j);
        v[j].push_back(i);
        deg[i]++;
        deg[j]++;
    }
    for (int i = 0; i < k; i++)
    {
        int apt;
        cin >> apt;
        is_apt[apt] = true;
    }

    int ans = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 1 && !is_apt[i])
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (removed[cur])
            continue;
        removed[cur] = true;
        ans++;
        for (int nxt : v[cur])
        {
            if (removed[nxt])
                continue;
            deg[nxt]--;
            if (deg[nxt] == 1 && !is_apt[nxt])
            {
                q.push(nxt);
            }
        }
    }
    cout << n - ans;
    return 0;
}
