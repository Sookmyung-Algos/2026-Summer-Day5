#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> adj[1001];
int indegree[1001];
int result[1001];

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int k;
        cin >> k;

        int order[1001];
        for(int j = 0; j < k; j++){
            cin >> order[j];
        }

        // order[j] -> order[j+1] 간선 추가
        for(int j = 0; j < k - 1; j++){
            int from = order[j];
            int to = order[j+1];

            adj[from].push_back(to);
            indegree[to]++;
        }
    }

    // 진입차수 0인 애들부터 시작 (위상 정렬)
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) q.push(i);
    }

    int cnt = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        result[cnt++] = cur;

        for(int i = 0; i < (int)adj[cur].size(); i++){
            int next = adj[cur][i];
            indegree[next]--;
            if(indegree[next] == 0) q.push(next);
        }
    }

    if(cnt != n){ // 사이클 있으면 다 못 돔
        cout << 0 << "\n";
    } else {
        for(int i = 0; i < n; i++){
            cout << result[i] << "\n";
        }
    }

    return 0;
}