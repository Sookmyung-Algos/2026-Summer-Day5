#include <bits/stdc++.h>
using namespace std;

int parent[200001];
int cnt[200001];

int find(int x) {
    if (parent[x]==x)
        return x;

    return parent[x]=find(parent[x]);
}

int unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return cnt[a];

    parent[b] = a;
    cnt[a] += cnt[b];
    return cnt[a];
}

int main() {

    int T;
    cin >>T;

    while (T--) {
        int F;
        cin >> F;

        map<string, int> name;

        int number = 0;

        for (int i = 0; i < F; i++) {
            string a, b;
            cin >> a >> b;

            // 처음 등장한 친구라면 번호 부여
            if (name.find(a) == name.end()) {
                name[a] = number;

                parent[number] = number;
                cnt[number] = 1;

                number++;
            }

            if (name.find(b) == name.end()) {
                name[b] = number;

                parent[number] = number;
                cnt[number] = 1;
                number++;
            }

            cout << unite(name[a], name[b]) << '\n';
        }
    }
    
    return 0;
}