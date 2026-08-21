#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int mat[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    bool visited[100] = { false };
    int minEdge[100];       
    for (int i = 0; i < n; i++)
        minEdge[i] = 1000000; 

    minEdge[0] = 0;
    int totalCost = 0;

    for (int cnt = 0; cnt < n; cnt++) {
       
        int u = -1;
        int best = 1000001;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && minEdge[i] < best) {
                best = minEdge[i];
                u = i;
            }
        }

        visited[u] = true;
        totalCost += minEdge[u];

       
        for (int v = 0; v < n; v++) {
            if (!visited[v] && mat[u][v] < minEdge[v]) {
                minEdge[v] = mat[u][v];
            }
        }
    }

    cout << totalCost << endl;

    return 0;
}
