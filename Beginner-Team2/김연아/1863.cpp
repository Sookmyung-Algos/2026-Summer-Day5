#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

// Find 연산 (경로 압축 적용)
int find_root(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_root(parent[x]);
}

// Union 연산
bool union_sets(int a, int b) {
    int root_a = find_root(a);
    int root_b = find_root(b);

    if (root_a != root_b) {
        parent[root_b] = root_a;
        return true; // 두 집합이 합쳐짐
    }
    return false; // 이미 같은 집합
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // 초기화: 각자 자기 자신을 부모로 설정
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int religion_count = n;

    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;

        // 서로 다른 집합에 속한 학생이면 하나로 합치고 종교 개수 -1
        if (union_sets(i, j)) {
            religion_count--;
        }
    }

    cout << religion_count << "\n";

    return 0;
}