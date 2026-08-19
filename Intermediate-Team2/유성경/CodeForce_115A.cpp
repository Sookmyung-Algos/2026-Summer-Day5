// CodeForce 115A. Party
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
    }

    int max_groups = 0;

    for (int i = 1; i <= n; ++i)
    {
        int curr = i;
        int depth = 0;

        while (curr != -1)
        {
            curr = p[curr];
            depth++;
        }

        if (depth > max_groups)
        {
            max_groups = depth;
        }
    }

    cout << max_groups << "\n";

    return 0;
}
#endif
