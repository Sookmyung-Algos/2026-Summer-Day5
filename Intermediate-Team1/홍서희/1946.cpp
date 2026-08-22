#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

vector<int> v[1001];
int deg[1001];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int it = 0; it < m; it++)
    {
        int num, prev, nxt;
        cin >> num;
        cin >> prev;
        for (int t = 0; t < num - 1; t++)
        {
            cin >> nxt;
            v[prev].push_back(nxt);
            deg[nxt]++;
            prev = nxt;
        }
    }
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
            q.push(i);
    }
    if (q.empty())
    {
        cout << 0;
        return 0;
    }
    while (!q.empty())
    {
        int cur = q.front();
        ans.push_back(cur);
        q.pop();

        for (int nxt : v[cur])
        {
            deg[nxt]--;
            if (deg[nxt] == 0)
                q.push(nxt);
        }
    }
    if (ans.size() == n)
    {
        for (int a : ans)
            cout << a << '\n';
    }
    else
        cout << 0;

    return 0;
}
