#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int parent[200005];
int group_size[200005];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        parent[b] = a;
        group_size[a] += group_size[b]; 
    }
    
    return group_size[a]; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    while (N--) {
        int E;
        cin >> E;

        map<string, int> to_id;
        int idx = 1;

        for (int j = 0; j < E; j++) {
            string name1, name2;
            cin >> name1 >> name2;

            if (to_id.find(name1) == to_id.end()) {
                to_id[name1] = idx;
                parent[idx] = idx;
                group_size[idx] = 1; 
                idx++;
            }
            if (to_id.find(name2) == to_id.end()) {
                to_id[name2] = idx;
                parent[idx] = idx;
                group_size[idx] = 1; 
                idx++;
            }

            int id1 = to_id[name1];
            int id2 = to_id[name2];

            cout << unite(id1, id2) << "\n";
        }
    }
    return 0;
}