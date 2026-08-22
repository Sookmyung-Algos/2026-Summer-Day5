#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int N, E;
string a, b;

int sz[200001]; // i가 루트인 집합의 크기
int parent[200001]; // 십만개의 관계가 나오므로 사람은 이십만명까지 가능

map<string, int> idMap; // 이름, 아이디
int Id = 1;

int getId(string name) {
    if (idMap.find(name) == idMap.end()){ // 처음 보는 이름이면
        idMap[name] = Id; // 아이디 부여
        parent[Id] = Id;
        sz[Id] = 1;
        Id++;
    }
    return idMap[name];
}

int find(int x){
    if (parent[x] == x) return x;
    return parent[x] = find (parent[x]);
}

void unionNodes(int u, int v){ // 각 집합의 루트 조회 후 연결
    int rootU = find(u); 
    int rootV = find(v);
    if (rootU != rootV){
        parent[rootV] = rootU;
        sz[rootU] += sz[rootV]; // 네트워크 크기 합치기
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> E;
        idMap.clear(); Id = 1; // 다른 케이스 넘어갈 때 초기화
        for (int j = 0; j < E; j++){
            cin >> a >> b;
            int A = getId(a);
            int B = getId(b);
            
            unionNodes(A, B); 
            cout << sz[find(A)] << '\n';
        }
    }

    return 0;
}