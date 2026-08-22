#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int findParent(vector<int>& parent, int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, parent[x]);
}

int unionParent(vector<int>& parent, vector<int>& cnt, int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);

    if (a == b)
        return cnt[a];

    parent[b] = a;
    cnt[a] += cnt[b];

    return cnt[a];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int E;
        cin >> E;

        map<string, int> id;

        vector<int> parent(2 * E);
        vector<int> cnt(2 * E, 1);

        for (int i = 0; i < 2 * E; i++) {
            parent[i] = i;
        }

        int number = 0;

        for (int i = 0; i < E; i++) {
            string a, b;
            cin >> a >> b;

            if (id.find(a) == id.end()) {
                id[a] = number;
                number++;
            }

            if (id.find(b) == id.end()) {
                id[b] = number;
                number++;
            }

            cout << unionParent(parent, cnt, id[a], id[b]) << '\n';
        }
    }

    return 0;
}