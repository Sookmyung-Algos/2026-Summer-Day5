#include <bits/stdc++.h>
using namespace std;
 
int main() {
    vector<int> g[3];
    int indegree[3] = {0, 0, 0};
 
    for(int i = 0; i < 3; i++) {
        string s;
        cin >> s;
 
        int a = s[0] - 'A';
        int b = s[2] - 'A';
 
        if(s[1] == '<') {
            g[a].push_back(b);
            indegree[b]++;
        }
        else {
            g[b].push_back(a);
            indegree[a]++;
        }
    }
 
    queue<int> q;
 
    for(int i = 0; i < 3; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }
 
    string ans = "";
 
    while(!q.empty()) {
        int now = q.front();
        q.pop();
 
        ans += char(now + 'A');
 
        for(int next : g[now]) {
            indegree[next]--;
 
            if(indegree[next] == 0)
                q.push(next);
        }
    }
 
    if(ans.size() != 3)
        cout << "Impossible";
    else
        cout << ans;
 
    return 0;
}
