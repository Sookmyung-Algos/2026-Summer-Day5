#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> graph[3];
    int indegree[3] = {0, 0, 0};

    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;

        int a = s[0] - 'A';
        int b = s[2] - 'A';

        if (s[1] == '<') {
            graph[a].push_back(b);
            indegree[b]++;
        }
        else {
            graph[b].push_back(a);
            indegree[a]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < 3; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    string answer = "";

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        answer += char('A' + cur);

        for (int next : graph[cur]) {
            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if (answer.size() != 3) {
        cout << "Impossible\n";
    }
    else {
        cout << answer << '\n';
    }

    return 0;
}