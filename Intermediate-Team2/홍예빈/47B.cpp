// Day5 - 코드포스 47B : Coins
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> graph(3);
    vector<int> indegree(3, 0);

    auto index = [](char c) {
        return c - 'A';
    };

    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;

        int from, to;

        if (s[1] == '<') {
            // s[0] < s[2]
            from = index(s[0]);
            to = index(s[2]);
        } else {
            // s[0] > s[2] 이므로 s[2] < s[0]
            from = index(s[2]);
            to = index(s[0]);
        }

        graph[from].push_back(to);
        indegree[to]++;
    }

    queue<int> q;

    for (int i = 0; i < 3; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    string answer;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        answer += char('A' + current);

        for (int next : graph[current]) {
            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if (answer.size() != 3) {
        cout << "Impossible\n";
    } else {
        cout << answer << '\n';
    }

    return 0;
}
