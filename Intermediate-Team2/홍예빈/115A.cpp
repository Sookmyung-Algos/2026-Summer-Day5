// Day5 - 코드포스 115A : Party
#include <bits/stdc++.h>
using namespace std;

vector<int> parentEmployee;
vector<int> dp;

int getDepth(int employee) {
    if (dp[employee] != 0) {
        return dp[employee];
    }

    if (parentEmployee[employee] == -1) {
        dp[employee] = 1;
    } else {
        dp[employee] =
            getDepth(parentEmployee[employee]) + 1;
    }

    return dp[employee];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    parentEmployee.resize(n + 1);
    dp.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> parentEmployee[i];
    }

    int answer = 0;

    for (int employee = 1; employee <= n; employee++) {
        answer = max(answer, getDepth(employee));
    }

    cout << answer << '\n';

    return 0;
}
