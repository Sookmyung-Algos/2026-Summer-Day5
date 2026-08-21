#include <iostream>
#include <string>
#include <map>
using namespace std;

int parent[200001];
int sz[200001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); 
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    
    if (sz[a] < sz[b]) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    parent[b] = a;
    sz[a] += sz[b];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int e;
        cin >> e;

        map<string, int> id;
        int cnt = 0;

        for (int i = 0; i < e; i++) {
            string a, b;
            cin >> a >> b;

            if (id.find(a) == id.end()) {
                id[a] = cnt;
                parent[cnt] = cnt;
                sz[cnt] = 1;
                cnt++;
            }
            if (id.find(b) == id.end()) {
                id[b] = cnt;
                parent[cnt] = cnt;
                sz[cnt] = 1;
                cnt++;
            }

            merge(id[a], id[b]);

            int root = find(id[a]);
            cout << sz[root] << "\n";
        }
    }

    return 0;
}
