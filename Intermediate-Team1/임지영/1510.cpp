#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[100], b[100]; // 각 색종이의 (작은 변, 큰 변)
int dp[100];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a[i] = min(x, y); // 회전 가능하니까 작은 변, 큰 변으로 정규화
        b[i] = max(x, y);
    }

    // 큰 색종이가 앞에 오도록 정렬 (a 기준 내림차순, 같으면 b 기준 내림차순)
    int idx[100];
    for(int i = 0; i < n; i++) idx[i] = i;
    sort(idx, idx + n, [](int i, int j){
        if(a[i] != a[j]) return a[i] > a[j];
        return b[i] > b[j];
    });

    // 정렬된 순서대로 a, b 재배치
    int sa[100], sb[100];
    for(int i = 0; i < n; i++){
        sa[i] = a[idx[i]];
        sb[i] = b[idx[i]];
    }

    // dp[i] : sa[i], sb[i] 색종이를 맨 위에 놓았을 때 쌓을 수 있는 최대 장수
    int ans = 0;
    for(int i = 0; i < n; i++){
        dp[i] = 1; // 자기 자신 한 장은 항상 가능

        for(int j = 0; j < i; j++){
            // j가 i보다 크거나 같아야 i를 j 위에 올릴 수 있음
            if(sa[j] >= sa[i] && sb[j] >= sb[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";

    return 0;
}