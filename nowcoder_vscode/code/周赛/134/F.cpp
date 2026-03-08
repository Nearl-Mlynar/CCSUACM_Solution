#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 998244353;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;

    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j + i - 1 <= n; ++j)
        {
            int k = j + i - 1;
            if (i == 1)
            {
                a[j][k] = 1;
            }
            else if (i == 2)
            {
                a[j][k] = (s[j] == s[k]);
            }
            else
            {
                a[j][k] = (s[j] == s[k] && a[j + 1][k - 1]);
            }
        }
    }

    vector<i64> dp(n + 1, 0);
    vector<i64> ans(n + 1, 0);

    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (a[j][i])
            {
                i64 sz = i - j + 1;
                i64 res = (sz * sz) % mod;

                dp[i] = (dp[i] + dp[j - 1]) % mod;
                ans[i] = (ans[i] + ans[j - 1] + (dp[j - 1] * res) % mod) % mod;
            }
        }
    }

    cout << ans[n] << endl;
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