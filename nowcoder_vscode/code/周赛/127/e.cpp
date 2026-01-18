#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 998244353;
const i64 N = 3e5 + 7;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    i64 dp1[2][2] = {};

    if (s[0] == '0' || s[0] == '1')
    {
        dp1[0][s[0] - '0'] = 1;
    }
    else
    {
        dp1[0][0] = dp1[0][1] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        i64 dp2[2][2] = {};
        for (int p = 0; p < 2; p++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (dp1[p][j] == 0)
                {
                    continue;
                }
                if (s[i] == '?')
                {
                    for (int k = 0; k < 2; k++)
                    {
                        int y = p ^ (k == j);
                        dp2[y][k] = (dp2[y][k] + dp1[p][j]) % mod;
                    }
                }
                else
                {
                    int y = p ^ (s[i] - '0' == j);
                    dp2[y][s[i] - '0'] = (dp2[y][s[i] - '0'] + dp1[p][j]) % mod;
                }
            }
        }
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                dp1[i][j] = dp2[i][j];
            }
        }
    }

    cout << (dp1[0][0] + dp1[0][1]) % mod << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}