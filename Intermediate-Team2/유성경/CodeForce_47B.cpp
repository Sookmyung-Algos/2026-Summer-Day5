// CodeForce 47B. Coins
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int win[3] = { 0, 0, 0 };
    string s;

    for (int i = 0; i < 3; ++i)
    {
        cin >> s;

        if (s[1] == '>')
        {
            win[s[0] - 'A']++;
        }
        else
        {
            win[s[2] - 'A']++;
        }
    }

    if (win[0] == 1 && win[1] == 1 && win[2] == 1)
    {
        cout << "Impossible\n";
    }
    else
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (win[j] == i)
                {
                    cout << (char)('A' + j);
                }
            }
        }
        cout << "\n";
    }

    return 0;
}
#endif