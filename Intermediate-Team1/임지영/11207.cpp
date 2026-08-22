#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> adj[100005];
int par[100005];
int order_[100005];
int cnt_[100005];   // 서브트리 안 아파트 개수
int childCnt[100005]; // 자식 방향 중 아파트 있는 방향 개수
bool isApt[100005];

int main(){
    cin >> n >> k;

    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w; // w는 이 문제에서 실제로 안 씀 (연결 구조만 중요)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        isApt[x] = true;
    }

    // 1번을 루트로 BFS 하면서 방문 순서, 부모 저장
    vector<bool> visited(n + 1, false);
    queue<int> q;
    int root = 1;
    q.push(root);
    visited[root] = true;

    int idx = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        order_[idx++] = cur;

        for(int next : adj[cur]){
            if(!visited[next]){
                visited[next] = true;
                par[next] = cur;
                q.push(next);
            }
        }
    }

    // 서브트리 아파트 개수 누적 (역순으로 처리하면 자식 -> 부모 순서 보장)
    for(int i = 0; i < n; i++){
        cnt_[order_[i]] = isApt[order_[i]] ? 1 : 0;
    }
    for(int i = n - 1; i >= 1; i--){ // i=0(루트)은 부모 없으니 제외
        int v = order_[i];
        int p = par[v];

        cnt_[p] += cnt_[v];
        if(cnt_[v] > 0) childCnt[p]++; // 자식 방향에 아파트 있으면 branch 카운트
    }

    // 각 노드마다 "아파트가 있는 방향(branch)" 개수 계산
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int branches = childCnt[i];

        if(i != root){
            // 부모 쪽 방향에 아파트가 있는지 (전체 - 서브트리 안)
            if(k - cnt_[i] > 0) branches++;
        }

        if(isApt[i] || branches >= 2) ans++; // 아파트거나 branch 2개 이상이면 good
    }

    cout << ans << "\n";

    return 0;
}