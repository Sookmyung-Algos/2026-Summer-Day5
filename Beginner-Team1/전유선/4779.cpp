#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int find(vector<int>& parent, int x) {
    if (parent[x] == x) {
        return x;
    }

    return parent[x] = find(parent, parent[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int E;
        cin >> E;

        unordered_map<string, int> id;

        vector<int> parent;
        vector<int> size;

        for (int i = 0; i < E; i++) {
            string a, b;
            cin >> a >> b;

            // a가 처음 등장한 사람이라면 번호를 부여한다.
            if (id.find(a) == id.end()) {
                int number = id.size();

                id[a] = number;
                parent.push_back(number);
                size.push_back(1);
            }

            // b가 처음 등장한 사람이라면 번호를 부여한다.
            if (id.find(b) == id.end()) {
                int number = id.size();

                id[b] = number;
                parent.push_back(number);
                size.push_back(1);
            }

            // 두 사람의 대표를 찾고
            int rootA = find(parent, id[a]);
            int rootB = find(parent, id[b]);

            // 서로 다른 네트워크라면 합친다.
            if (rootA != rootB) {
                parent[rootB] = rootA;
                size[rootA] += size[rootB];
            }

            // 합쳐진 네트워크의 사람 수를 출력한다.
            cout << size[find(parent, rootA)] << '\n';
        }
    }

    return 0;
}