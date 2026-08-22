#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int parent[200005];
int cnt[200005];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<string, int> m;
        int num = 0;

        for (int i = 0; i < 200005; i++) {
            parent[i] = i;
            cnt[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;

            if (m.find(a) == m.end()) {
                m[a] = num++;
            }

            if (m.find(b) == m.end()) {
                m[b] = num++;
            }

            int x = find(m[a]);
            int y = find(m[b]);

            if (x != y) {
                parent[y] = x;
                cnt[x] += cnt[y];
            }

            cout << cnt[find(x)] << '\n';
        }
    }

    return 0;
}