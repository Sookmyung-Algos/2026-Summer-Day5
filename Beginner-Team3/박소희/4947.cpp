#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> adj[100001];
int parent[100001];
int depth[100001];

void dfs(int cur, int par, int d){ 
    parent[cur] = par;
    depth[cur] = d;

    for (int next : adj[cur]){
        if (next != par){ // 자식노드면
            dfs(next, cur, d + 1); // 현재노드를 부모노드로 설정
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // 지름을 구하기 위해 양방향 필요
    }
    dfs(1, -1, 0); // 1번 노드에서부터의 거리

    int farthest1 = 1;
    for (int i = 1; i <= n; i++) // 1번에서 가장 먼 노드 찾기
        if (depth[i] > depth[farthest1])
            farthest1 = i;

    dfs(farthest1, -1, 0); // 1번에서 가장 먼 노드를 기준으로 각 노드 거리

    int diameter = 0;
    for (int i = 1; i <= n; i++)
        diameter = max(diameter, depth[i]);

    cout << diameter << "\n";


    return 0;
}