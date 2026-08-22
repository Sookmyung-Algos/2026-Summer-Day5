#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;

    //graph[u]={가중치, 연결된 정점}
    vector<pair<int, int>> graph[101];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){

            int cost;
            cin >> cost;
            if (i != j && cost > 0){
                graph[i].push_back({cost, j});
            }
        }
    }

    bool visited[101] = {false};

    //{가중치, 정점}
    //가장 작은 가중치가 먼저 나오게 설정
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    >pq;

    pq.push({0, 0});

    int answer = 0;

    while (!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (visited[now]){
            continue;
        }

        visited[now] = true;
        answer+=cost;

        for (auto next : graph[now]){

            int nextCost=next.first;
            int nextNode=next.second;

            if (!visited[nextNode]) {
                pq.push({nextCost, nextNode});
            }
        }
    }

    cout << answer;
    return 0;
}