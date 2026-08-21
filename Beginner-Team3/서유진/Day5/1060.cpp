#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector(n,0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>> edge;
    vector<int> mst(n,0);
    int total=0;
    
    mst[0] = 1;

    for (int j=1; j<n; j++) {
        edge.push({arr[0][j],j});
    }

    while (!edge.empty()) {
        auto[weight,ver] = edge.top();
        edge.pop();

        if (mst[ver] == 0) {
            mst[ver] = 1;
            total += weight;
            
            for (int i=0; i<n; i++) {
                if (i != ver) {
                    if (mst[i] == 0) {
                        edge.push({arr[ver][i],i});
                    }
                }
            }
        }
    }

    cout << total;

}