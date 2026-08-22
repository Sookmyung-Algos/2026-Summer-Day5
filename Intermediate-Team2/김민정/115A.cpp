#include <bits/stdc++.h>
using namespace std;
 
int parentt[2005];
int dp[2005];
 
int getDepth(int x) {
    if(dp[x] != 0)
        return dp[x];
 
    if(parentt[x] == -1) {
        dp[x] = 1;
        return 1;
    }
 
    dp[x] = getDepth(parentt[x]) + 1;
    return dp[x];
}
 
int main() {
    int n;
    cin >> n;
 
    for(int i = 1; i <= n; i++) {
        cin >> parentt[i];
    }
 
    int ans = 0;
 
    for(int i = 1; i <= n; i++) {
        ans = max(ans, getDepth(i));
    }
 
    cout << ans;
 
    return 0;
}
