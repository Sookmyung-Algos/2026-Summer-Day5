#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Paper {
    int w, h;
};

bool compare(const Paper& a, const Paper& b) {
    if (a.w == b.w) {
        return a.h > b.h;
    }
    return a.w > b.w;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Paper> papers(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        papers[i].w = max(x, y);
        papers[i].h = min(x, y);
    }

    sort(papers.begin(), papers.end(), compare);

    vector<int> dp(n, 1);
    int max_papers = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (papers[j].w >= papers[i].w && papers[j].h >= papers[i].h) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_papers = max(max_papers, dp[i]);
    }

    cout << max_papers << "\n";
    return 0;
}
