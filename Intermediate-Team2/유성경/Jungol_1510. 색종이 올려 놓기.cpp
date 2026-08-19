// 정올 1510. 색종이 올려 놓기 
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    vector<pair<int, int>> papers(n);
    for (int i = 0; i < n; ++i)
    {
        int w, h;
        cin >> w >> h;

        if (w < h)
        {
            int temp = w;
            w = h;
            h = temp;
        }

        papers[i].first = w;
        papers[i].second = h;
    }

    sort(papers.begin(), papers.end());

    vector<int> dp(n, 1);
    int max_papers = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (papers[j].first <= papers[i].first && papers[j].second <= papers[i].second)
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        if (dp[i] > max_papers)
        {
            max_papers = dp[i];
        }
    }

    cout << max_papers << "\n";

    return 0;
}
#endif